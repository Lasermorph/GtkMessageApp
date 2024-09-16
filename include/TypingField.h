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
		GtkWidget* textView = 0x0;
		GtkWidget* scrolledWindow = 0x0;
		GtkWidget* button = 0x0;

		// Remeber to delete
		GtkWidget* tmp = 0x0;
};