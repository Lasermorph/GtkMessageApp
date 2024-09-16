#pragma once
#include "gtk/gtk.h"

class Hotkeys
{
	public:
		Hotkeys();
		~Hotkeys(){};

		static Hotkeys* globalInstance;

	public:
		void Create(GtkApplication* app);
		static void QuitApplication(AdwApplication *app, guint keyval, guint keycode, GdkModifierType state, GtkEventControllerKey *event_controller);

	private:
		GtkEventController* eventController = 0x0;
};