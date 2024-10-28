#pragma once
#include "SuperHandler.h"
#include <vector>
#include "MtkGMenu.h"

class TopMenu
{
	public:
		TopMenu(GtkApplication* app);
		~TopMenu();

		static TopMenu* globalInstance;

	public:
		// GMenu* Create(GtkApplication* app, GtkWidget* window);
		GtkWidget* Create();

	public:
		static void TopMenuShow(GtkWidget* button, GtkPopover* topMenu);
		
	private:
		GtkWidget* m_topMenuButton = 0x0;
		GtkWidget* m_topMenu = 0x0;
		GtkWidget* m_topMenuButtonImage = 0x0;
};
