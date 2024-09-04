#include "MessageField.h"

MessageField::MessageField()
{
	scrolledWindow = gtk_scrolled_window_new();
	// gtk_widget_set_hexpand(scrolledWindow, true);
	// gtk_widget_set_vexpand(scrolledWindow, true);
	vBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	button = gtk_button_new_with_label("scroll me");
}

MessageField::~MessageField()
{}

GtkWidget* MessageField::Create()
{
	gtk_box_append(GTK_BOX(vBox), button);

	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolledWindow), vBox);

	gtk_widget_set_size_request(scrolledWindow, 100, 100);

	// gtk_widget_set_size_request(scrolledWindow, 100, 100);

	return scrolledWindow;
}
