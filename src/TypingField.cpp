#include "../include/TypingField.h"

TypingField* TypingField::globalInstance = 0x0;

TypingField::TypingField()
{
	button = gtk_button_new();
	scrolledWindow = gtk_scrolled_window_new();
	textView = gtk_text_view_new();
	gtk_widget_set_margin_bottom(scrolledWindow, 10);
	gtk_widget_set_margin_start(scrolledWindow, 5);
	gtk_widget_set_margin_end(scrolledWindow, 5);

	// Remember to delete
	tmp = gtk_entry_new();	

	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolledWindow), textView);
}

TypingField::~TypingField()
{}

GtkWidget* TypingField::Create()
{
	return scrolledWindow;
}