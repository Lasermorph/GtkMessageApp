#include "../include/Menu.h"
#include <map>

MtkMenu::MtkMenu(const std::string& name)
{
	m_name = name;
	m_menuItems = new std::vector<gpointer>();
	m_gMenu = g_menu_new();
	m_subMenus = new std::vector<MtkMenu*>();
}

MtkMenu::~MtkMenu()
{
	for (size_t i = 0; i < m_menuItems->size(); i++)
	{
		g_object_unref(m_menuItems->at(i));
		m_menuItems->at(i) = 0x0;
	}

	for (size_t i = 0; i < m_subMenus->size(); i++)
	{
		delete m_subMenus->at(i);
		m_subMenus->at(i) = 0x0;
	}

	g_object_unref(m_gMenu);
	delete m_menuItems;
	m_menuItems = 0x0;
	delete m_subMenus;
	m_subMenus = 0x0;
}

void MtkMenu::AddSubMenu(MtkMenu* subMenu)
{
	g_menu_append_submenu(m_gMenu, subMenu->GetName().c_str(), G_MENU_MODEL(subMenu->AsGMenu()));
	m_subMenus->push_back(subMenu);
}

void MtkMenu::AddMenuItem(std::string label, std::string detailedAction)
{
	gpointer gp = g_menu_item_new(label.c_str(), detailedAction.c_str());
	g_menu_append_item(m_gMenu, G_MENU_ITEM(gp));
	m_menuItems->push_back(gp);
}

MtkMenu* MtkMenu::GetSubMenu(const std::string& subMenuName)
{
	for (auto it : *m_subMenus)
	{
		if (it->GetName() == subMenuName)
		{
			return it;
		}
	}
	return 0x0;
}

GMenu* MtkMenu::AsGMenu()
{
	return m_gMenu;
}

std::string MtkMenu::GetName()
{
	return m_name;
}