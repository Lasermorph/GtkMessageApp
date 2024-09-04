#include "../include/TopMenuBar.h"
#include "../include/Actions.h"
#include "../include/SuperHandler.h"

TopMenuBar* TopMenuBar::globalInstance = 0x0;

TopMenuBar::TopMenuBar()
{}	

TopMenuBar::~TopMenuBar()
{
	if (topMenuBar != 0x0)
	{
		g_object_unref(topMenuBar);
		topMenuBar = 0x0;
	}

	if (fileMenu != 0x0)
	{
		g_object_unref(fileMenu);
	}

	if (editMenu != 0x0)
	{
		g_object_unref(editMenu);
		editMenu = 0x0;
	}

	if (addFriendButton != 0x0)
	{
		g_object_unref(addFriendButton);
		addFriendButton = 0x0;
	}

	if (quitButton != 0x0)
	{
		g_object_unref(quitButton);
		quitButton = 0x0;
	}

	if (copyButton != 0x0)
	{
		g_object_unref(copyButton);
		copyButton = 0x0;
	}

	if (addFriendAction != 0x0)
	{
		g_object_unref(addFriendAction);
		addFriendAction = 0x0;
	}

	if (quitAction != 0x0)
	{
		g_object_unref(quitAction);
		quitAction = 0x0;
	}
}

GMenu* TopMenuBar::Create(GtkApplication* app, GtkWidget* window)
{
	topMenuBar = g_menu_new();
	fileMenu = g_menu_new();
	editMenu = g_menu_new();
	addFriendButton = g_menu_item_new("Add Friend", "app.addFriend");
	quitButton = g_menu_item_new("Quit", "app.quit");
	copyButton = g_menu_item_new("Copy", "app.copy");

	g_menu_append_item(fileMenu, addFriendButton);
	g_menu_append_item(fileMenu, quitButton);
	g_menu_append_item(editMenu, copyButton);

	g_menu_append_submenu(topMenuBar, "File", G_MENU_MODEL(fileMenu));
	g_menu_append_submenu(topMenuBar, "Edit", G_MENU_MODEL(editMenu));

	addFriendAction = g_simple_action_new("addFriend", NULL);
	quitAction = g_simple_action_new("quit", NULL);

	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(addFriendAction));
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(quitAction));
	g_signal_connect(addFriendAction, "activate", G_CALLBACK(AppAction::AddFriend), topMenuBar);
	g_signal_connect(quitAction, "activate", G_CALLBACK(AppAction::ApplicationQuit), app);

	return topMenuBar;
}

void TopMenuBar::Quit(GSimpleAction* action, GVariant* parameter, gpointer user_data)
{
	std::cout << "Quiting application" << std::endl;
	g_application_quit(G_APPLICATION(user_data));
}