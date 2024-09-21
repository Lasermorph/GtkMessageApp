#pragma once
#include "gtk/gtk.h"
#include "SuperHandler.h"

class TopMenu
{
	public:
		TopMenu();
		~TopMenu();

		static TopMenu* globalInstance;

	public:
		// GMenu* Create(GtkApplication* app, GtkWidget* window);
		GMenu* TopMenuBarCreate(GtkApplication* app);
		GtkWidget* Create();

	public:
		// void Quit(GSimpleAction* action, GVariant* parameter, gpointer user_data);
		static void Testing(GtkWidget* button, GtkPopover* topMenu);
		
	private:
		GtkWidget* topMenuButton = 0x0;
		GtkWidget* topMenu = 0x0;
		GtkWidget* topMenuButtonImage = 0x0;

		GMenu* topMenuBar = 0x0;
		GMenu* fileMenu = 0x0;
		GMenu* editMenu = 0x0;
		GMenuItem* addFriendButton = 0x0;
		GMenuItem* quitButton = 0x0;
		GMenuItem* copyButton = 0x0;
		GSimpleAction* addFriendAction = 0x0;
		GSimpleAction* quitAction = 0x0;
};
