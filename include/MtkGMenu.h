#pragma once
#include "../include/MtkGMenuItem.h"
#include <gtk/gtk.h>
#include <iostream>
#include <map>

class MtkGMenu
{
	public:
		MtkGMenu(const std::string& name);
		~MtkGMenu();

		void AddSubMenu(MtkGMenu& subMenu);
		void AddMenuItem(MtkGMenuItem& menuItem);
		GMenu* AsGMenu();
		std::string GetName();

	private:
		std::string m_name;
		GMenu* m_gMenu = 0x0;
};