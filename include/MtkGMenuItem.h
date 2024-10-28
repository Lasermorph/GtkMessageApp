#pragma once
#include <gtk/gtk.h>
#include <iostream>

class MtkGMenuItem
{
	public:
		MtkGMenuItem(const std::string& label, const std::string& detailedAction);
		~MtkGMenuItem();

		GMenuItem* AsGMenuItem();
		void ActionMapAdd(const GVariantType* parameter_type, GActionMap *action_map);
		void SignalConnect(GCallback func, gpointer data);

	private:
	std::string GetActionName();

	private:
		GMenuItem* m_menuItem = 0x0;
		std::string m_actionName = "";
		GSimpleAction* m_action = 0x0;
};