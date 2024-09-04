#pragma once
#include <gtk/gtk.h>

class AppAction
{
	public:
		AppAction();
	
	public:
		static void AddFriend(GSimpleAction* action, GVariant* parameter, gpointer user_data);
		static void ApplicationQuit(GSimpleAction* action, GVariant* parameter, gpointer user_data);
};