#include "../include/Hotkeys.h"
#include "adwaita.h"

Hotkeys* Hotkeys::globalInstance = 0x0;

Hotkeys::Hotkeys()
{
	eventController = gtk_event_controller_key_new();
}

void Hotkeys::Create(* app)
{
	g_signal_connect_object(eventController, "key-pressed", G_CALLBACK(QuitApplication), app, G_CONNECT_SWAPPED);
}

void Hotkeys::QuitApplication(GtkApplication *app, guint keyval, guint keycode, GdkModifierType state, GtkEventControllerKey *event_controller)
{
	if (keyval == GDK_KEY_Q)
	{
		printf("we hit q");
	}
}