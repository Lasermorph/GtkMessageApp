#pragma once
#include "SuperHandler.h"
#include <vector>
#include "MtkMenu.h"

class TopMenu
{
	public:
		TopMenu(GtkApplication* app);
		~TopMenu();

		static TopMenu* globalInstance;

	public:
		// GMenu* Create(GtkApplication* app, GtkWidget* window);
		MtkMenu* TopMenuBarCreate(GtkApplication* app);
		GtkWidget* Create();

	public:
		// void Quit(GSimpleAction* action, GVariant* parameter, gpointer user_data);
		static void TopMenuShow(GtkWidget* button, GtkPopover* topMenu);
		
	private:
		GtkWidget* m_topMenuButton = 0x0;
		GtkWidget* m_topMenu = 0x0;
		GtkWidget* m_topMenuButtonImage = 0x0;

		MtkMenu* m_topMenuBar = 0x0;
		MtkMenu* m_fileMenu = 0x0;
		MtkMenu* m_editMenu = 0x0;
		GMenuItem* m_addFriendButton = 0x0;
		GMenuItem* m_quitButton = 0x0;
		GMenuItem* m_copyButton = 0x0;
		GSimpleAction* m_addFriendAction = 0x0;
		GSimpleAction* m_quitAction = 0x0;

		std::vector<MtkMenu*>* m_menus = 0x0;
		MtkMenu* m_newTopMenuBar = 0x0;
};
