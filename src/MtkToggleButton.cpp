#include "../include/MtkToggleButton.h"

MtkToggleButton::MtkToggleButton()
{
	m_button = gtk_toggle_button_new();
}

MtkToggleButton::MtkToggleButton(const std::string& label)
{
	m_button = gtk_toggle_button_new_with_label(label.c_str());
}

MtkToggleButton::~MtkToggleButton()
{}

GtkWidget* MtkToggleButton::AsGtkWidget()
{
	return m_button;
}

GtkToggleButton* MtkToggleButton::AsGtkToggleButton()
{
	return GTK_TOGGLE_BUTTON(m_button);
}

void MtkToggleButton::SetGroup(MtkToggleButton* groupParent)
{
	gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(m_button), groupParent->AsGtkToggleButton());
}