#include "../include/TypingField.h"

TypingField::TypingField()
{
	button = gtk_button_new();
}

TypingField::~TypingField()
{}

GtkWidget* TypingField::Create()
{
	return button;
}