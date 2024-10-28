#include "../include/TypingField.h"
#include <iostream>
#include "../include/MtkTextView.h"

TypingField* TypingField::globalInstance = 0x0;

TypingField::TypingField()
{
	m_scrolledWindow = gtk_scrolled_window_new();
	MtkTextView textView = MtkTextView();
	gtk_widget_set_margin_bottom(m_scrolledWindow, 10);
	gtk_widget_set_margin_start(m_scrolledWindow, 5);
	gtk_widget_set_margin_end(m_scrolledWindow, 5);

	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(m_scrolledWindow), textView.AsGtkWidget());

	GtkEventController* controller = gtk_shortcut_controller_new();
	gtk_event_controller_set_propagation_phase(controller, GTK_PHASE_CAPTURE);
	GtkShortcut* shortcut = gtk_shortcut_new
	(
		gtk_keyval_trigger_new(GDK_KEY_Return, GDK_NO_MODIFIER_MASK),
		gtk_callback_action_new(SendMessage, textView.GetBuffer(), 0x0)
	);
	gtk_shortcut_controller_add_shortcut(GTK_SHORTCUT_CONTROLLER(controller), shortcut);
	gtk_widget_add_controller(textView.AsGtkWidget(), controller);

	gtk_widget_add_tick_callback(textView.AsGtkWidget(), Update, textView.GetBuffer(), 0x0);

	// GtkEventController* eventController = gtk_event_controller_key_new();
	// g_signal_connect(eventController, "key-pressed", G_CALLBACK(RemoveChar), 0x0);
	// gtk_widget_add_controller(textView.AsGtkWidget(), eventController);
	// gtk_event_controller_set_propagation_phase(eventController, GTK_PHASE_CAPTURE);
}

TypingField::~TypingField() = default;

GtkWidget* TypingField::Create()
{
	return m_scrolledWindow;
}

int TypingField::SendMessage(GtkWidget* action, GVariant* parameter, gpointer user_data)
{
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(user_data), &start, &end);
	gtk_text_buffer_delete(GTK_TEXT_BUFFER(user_data), &start, &end);

	return 0;
}

gboolean TypingField::Update(GtkWidget* widget, GdkFrameClock* frameClock, gpointer user_data)
{
	if (gtk_widget_has_focus(widget))
	{
		std::string text = "";
		GtkTextIter start, end;
		gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(user_data), &start, &end);
		gtk_text_buffer_get_text(GTK_TEXT_BUFFER(user_data), &start, &end, true);
		// text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(user_data), &start, &end, true);
		// if (text.size() > 0)
		// {
		// 	if (text.at(0) == '\n')
		// 	{
		// 		text = text.erase(0,1);
		// 		gtk_text_buffer_set_text(GTK_TEXT_BUFFER(user_data), text.c_str(), text.size());
		// 	}
		// }
	}

	return true;
}

void TypingField::TMP(GtkEventControllerKey* self, guint keyval, guint keycode, GdkModifierType state, gpointer user_data)
{
	
}

void TypingField::RemoveChar(GtkEventControllerKey* self, guint keyval, guint keycode, GdkModifierType state, gpointer user_data)
{
	std::cout << keycode << std::endl;
}