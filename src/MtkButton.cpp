#include "../include/MtkButton.h"

// Button without a label or icon
MtkButton::MtkButton()
{
	m_button = gtk_button_new();
}

// Button with a label
MtkButton::MtkButton(const std::string& label)
{
	m_button = gtk_button_new_with_label(label.c_str());
}

MtkButton::~MtkButton()
{}

void MtkButton::SetLabel(const std::string& label)
{
	gtk_button_set_label(GTK_BUTTON(m_button), label.c_str());
}

void MtkButton::Clicked(GCallback func, gpointer data)
{
	g_signal_connect(m_button, "clicked", func, data);
}

GtkButton* MtkButton::AsGtkButton()
{
	return GTK_BUTTON(m_button);
}

GtkWidget* MtkButton::AsGtkWidget()
{
	return m_button;
}
