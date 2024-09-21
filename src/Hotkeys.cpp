#include "../include/Hotkeys.h"
#include <iostream>
#include "../include/Actions.h"

Hotkeys* Hotkeys::globalInstance = 0x0;

Hotkeys::Hotkeys(GtkWidget* window, GtkApplication* app)
{
	eventController = gtk_shortcut_controller_new();
	shortcut = gtk_shortcut_new
	(
		gtk_keyval_trigger_new(GDK_KEY_q, GDK_CONTROL_MASK),
		gtk_callback_action_new((GtkShortcutFunc)AppAction::ApplicationQuit, app, 0x0)
	);
	gtk_shortcut_controller_add_shortcut(GTK_SHORTCUT_CONTROLLER(eventController), shortcut);
	gtk_widget_add_controller(window, eventController);
}