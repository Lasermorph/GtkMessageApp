#include "../include/MessageField.h"
#include "../include/MtkBox.h"
#include "../include/MtkButton.h"
#include <string>

MessageField* MessageField::globalInstance = 0x0;

MessageField::MessageField()
{
	MtkBox vbox = MtkBox(GTK_ORIENTATION_VERTICAL, 0);
	MtkButton button = MtkButton("scroll me");
	gtk_widget_set_hexpand(m_scrolledWindow.AsGtkWidget(), true);
	gtk_widget_set_vexpand(m_scrolledWindow.AsGtkWidget(), true);
	vbox.Add(button, 1);
	m_scrolledWindow.SetChild(vbox);
}

MessageField::~MessageField()
{}

GtkWidget* MessageField::Create()
{
	// gtk_widget_set_size_request(scrolledWindow, 100, 100);

	// gtk_widget_set_size_request(scrolledWindow, 100, 100);

	return m_scrolledWindow.AsGtkWidget();
}