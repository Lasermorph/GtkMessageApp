#include "../include/Actions.h"

AppAction::AppAction()
{};

void AppAction::AddFriend(GSimpleAction* action, GVariant* parameter, gpointer user_data)
{
	g_print("You added a friend\n");
}

void AppAction::ApplicationQuit(GSimpleAction* action, GVariant* parameter, gpointer user_data)
{
	g_application_quit(G_APPLICATION(user_data));
}