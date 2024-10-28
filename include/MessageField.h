#pragma once
#include "gtk/gtk.h"
#include "../include/MtkScrolledWindow.h"

class MessageField
{
	public:
		MessageField();
		~MessageField();

		static MessageField* globalInstance;

	public:
		GtkWidget* Create();
	
	private:
		MtkScrolledWindow m_scrolledWindow;
};