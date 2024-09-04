#pragma once
#include "gtk/gtk.h"
#include <iostream>

class MessageField
{
	public:
		MessageField();
		~MessageField();

	public:
	GtkWidget* Create();

	private:
	GtkWidget* scrolledWindow = 0x0;
	GtkWidget* vBox = 0x0;
	GtkWidget* button = 0x0;
};