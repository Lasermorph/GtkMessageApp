#pragma once
#include "gtk/gtk.h"

class Hotkeys
{
	public:
		Hotkeys(GtkWidget* window, GtkApplication* app);
		~Hotkeys(){};

		static Hotkeys* globalInstance;

	public:
		void Create(GtkApplication* app, GtkWidget* window);

	private:
		GtkEventController* eventController = 0x0;
		GtkShortcut* shortcut = 0x0;
		GtkShortcutAction* actionS = 0x0;
		GtkShortcutTrigger* triggerS = 0x0;
};