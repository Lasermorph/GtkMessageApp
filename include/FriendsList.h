#pragma once
#include "../include/MtkBox.h"
#include "../include/MtkToggleButton.h"
#include "../include/MtkScrolledWindow.h"
#include <gtk/gtk.h>

class FriendsList
{
	public:
		FriendsList();
		~FriendsList(){};

		static FriendsList* globalInstance;

	public:
		GtkWidget* Create();
	
	private:
		MtkScrolledWindow m_scrolledWindow;
};