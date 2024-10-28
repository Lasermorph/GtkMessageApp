#pragma once
#include "gtk/gtk.h"

class TypingField
{
	public:
		TypingField();
		~TypingField();

		static TypingField* globalInstance;

	public:
		GtkWidget* Create();

	private:
		static int SendMessage(GtkWidget* action, GVariant* parameter, gpointer message);
		static void RemoveChar(GtkEventControllerKey* self, guint keyval, guint keycode, GdkModifierType state, gpointer user_data);
		static void TMP(GtkEventControllerKey* self, guint keyval, guint keycode, GdkModifierType state, gpointer user_data);
		static gboolean Update(GtkWidget* widget, GdkFrameClock* frameClock, gpointer user_data);

		GtkWidget* m_scrolledWindow = 0x0;
};