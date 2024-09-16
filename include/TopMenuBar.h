#pragma once
#include "gtk/gtk.h"
#include <iostream>
#include "SuperHandler.h"

class TopMenuBar
{
	public:
		TopMenuBar();
		~TopMenuBar();

		static TopMenuBar* globalInstance;

	public:
		// GMenu* Create(GtkApplication* app, GtkWidget* window);
		GMenu* Create(GtkApplication* app);

	private:
		void Quit(GSimpleAction* action, GVariant* parameter, gpointer user_data);
		
	private:
		GMenu* topMenuBar = 0x0;
		GMenu* fileMenu = 0x0;
		GMenu* editMenu = 0x0;
		GMenuItem* addFriendButton = 0x0;
		GMenuItem* quitButton = 0x0;
		GMenuItem* copyButton = 0x0;
		GSimpleAction* addFriendAction = 0x0;
		GSimpleAction* quitAction = 0x0;
};
