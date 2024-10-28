#include "../include/MtkGMenu.h"
#include <map>

MtkGMenu::MtkGMenu(const std::string& name)
{
	m_name = name;
	m_gMenu = g_menu_new();
}

MtkGMenu::~MtkGMenu()
{
	// for (size_t i = 0; i < m_menuItems->size(); i++)
	// {
	// 	delete m_menuItems->at(i);
	// 	m_menuItems->at(i) = 0x0;
	// }

	// for (size_t i = 0; i < m_subMenus->size(); i++)
	// {
	// 	delete m_subMenus->at(i);
	// 	m_subMenus->at(i) = 0x0;
	// }
	// delete m_menuItems;
	// m_menuItems = 0x0;
	// delete m_subMenus;
	// m_subMenus = 0x0;

	g_object_unref(m_gMenu);
	m_gMenu = 0x0;
}

void MtkGMenu::AddSubMenu(MtkGMenu& subMenu)
{
	g_menu_append_submenu(m_gMenu, subMenu.GetName().c_str(), G_MENU_MODEL(subMenu.AsGMenu()));
}

void MtkGMenu::AddMenuItem(MtkGMenuItem& menuItem)
{
	g_menu_append_item(m_gMenu, menuItem.AsGMenuItem());
}

GMenu* MtkGMenu::AsGMenu()
{
	return m_gMenu;
}

std::string MtkGMenu::GetName()
{
	return m_name;
}