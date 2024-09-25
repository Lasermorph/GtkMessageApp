#include "../include/MtkMenuItem.h"
#include <stdexcept>

MtkMenuItem::MtkMenuItem(const std::string& label, const std::string& detailedAction)
{
	m_actionName = detailedAction;
	m_menuItem = g_menu_item_new(label.c_str(), detailedAction.c_str());
	if (detailedAction.find(".") == std::string::npos)
	{
		throw std::invalid_argument("Invalid MenuItem ActionName");
	}
}

MtkMenuItem::~MtkMenuItem()
{
	if (m_action != 0x0)
	{
		g_object_unref(m_action);
		m_action = 0x0;
	}
	g_object_unref(m_menuItem);
	m_menuItem = 0x0;
}

GMenuItem* MtkMenuItem::AsGMenuItem()
{
	return m_menuItem;
}

void MtkMenuItem::ActionMapAdd(const GVariantType* parameter_type, GActionMap *action_map)
{
	m_action = g_simple_action_new(GetActionName().c_str(), parameter_type);
	g_action_map_add_action(G_ACTION_MAP(action_map), G_ACTION(m_action));
}

void MtkMenuItem::SignalConnect(GCallback func, gpointer data)
{
	g_signal_connect(m_action, "activate", func, data);
}

std::string MtkMenuItem::GetActionName()
{
	std::string actionName = m_actionName;
	size_t removeChar = m_actionName.find(".");
	actionName.erase(0, removeChar + 1);
	return actionName;
}