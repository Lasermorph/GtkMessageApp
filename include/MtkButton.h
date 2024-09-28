#pragma once
#include <gtk/gtk.h>
#include <iostream>

class MtkButton
{
	public:
		MtkButton();
		MtkButton(const std::string& label);
		~MtkButton();

		void SetLabel(const std::string& label);
		void Clicked(GCallback func, gpointer data);
		GtkButton* AsGtkButton();
		GtkWidget* AsGtkWidget();

	private:
		GtkWidget* m_button = 0x0;
};