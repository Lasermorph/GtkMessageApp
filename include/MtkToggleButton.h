#pragma once
#include <gtk/gtk.h>
#include <iostream>

class MtkToggleButton
{
	public:
		MtkToggleButton();
		MtkToggleButton(const std::string& label);
		~MtkToggleButton();

		GtkToggleButton* AsGtkToggleButton();
		GtkWidget* AsGtkWidget();
		void SetGroup(MtkToggleButton groupParent);

	private:
		GtkWidget* m_button = 0x0;
};