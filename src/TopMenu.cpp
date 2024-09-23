#include "../include/TopMenu.h"
#include "../include/Actions.h"
#include "../include/SuperHandler.h"
#include <iostream>
#include <vector>


TopMenu* TopMenu::globalInstance = 0x0;

TopMenu::TopMenu()
{
	// m_topMenu = gtk_popover_menu_bar_new_from_model(G_MENU_MODEL(topMenuModel));

	m_menus = new std::vector<MtkMenu*>();

	m_newTopMenuBar = new MtkMenu("topMenuBar");
	MtkMenu* fileMenu = new MtkMenu("File");
	MtkMenu* editMenu = new MtkMenu("Edit");
	MtkMenu* anders = new MtkMenu("anders");

	fileMenu->AddMenuItem("Add Friend", "app.addFriend");
	editMenu->AddMenuItem("Copy", "app.copy");
	m_newTopMenuBar->AddSubMenu(fileMenu);	
	m_newTopMenuBar->AddSubMenu(editMenu);
	fileMenu->AddSubMenu(anders);
	m_newTopMenuBar->AddMenuItem("Quit", "app.quit");

	m_addFriendAction = g_simple_action_new("addFriend", NULL);
	m_quitAction = g_simple_action_new("quit", NULL);

	m_topMenu = gtk_popover_menu_new_from_model(G_MENU_MODEL(m_newTopMenuBar->AsGMenu()));
	m_topMenuButton = gtk_button_new();
	// m_topMenuButtonImage = gtk_image_new_from_file("image.png");

	GtkCssProvider* topMenuButtonStyle = gtk_css_provider_new();

	// gtk_css_provider_load_from_string(topMenuButtonStyle, ".gaming {background-color: red;}");

	gtk_css_provider_load_from_path(topMenuButtonStyle, "./style/TopMenu.css");

	gtk_widget_add_css_class(m_topMenuButton, "gaming");

	gtk_button_set_label(GTK_BUTTON(m_topMenuButton), "gamer");

	// gtk_button_set_child(GTK_BUTTON(m_topMenuButton), m_topMenuButtonImage);

	gtk_widget_set_parent(m_topMenu, m_topMenuButton);
	g_signal_connect(m_topMenuButton, "clicked", G_CALLBACK(TopMenuShow), m_topMenu);
}

TopMenu::~TopMenu()
{
	gtk_widget_unparent(m_topMenu);

	// gpointer** objectToUnref[] = 
	// {
	// 	(gpointer**)&m_topMenuBar, (gpointer**)&m_fileMenu, (gpointer**)&m_editMenu, (gpointer**)&m_addFriendButton,
	// 	(gpointer**)&m_quitButton, (gpointer**)&m_copyButton, (gpointer**)&m_addFriendAction, (gpointer**)&m_quitAction
	// };

	// for (int i = 0; i < sizeof(objectToUnref) / sizeof(objectToUnref[0]); i++)
	// {
	// 	if (*objectToUnref != 0x0)
	// 	{
	// 		g_object_unref(*objectToUnref[i]);
	// 		*objectToUnref[i] = 0x0;
	// 	}
	// }
	delete m_menus;
	delete m_newTopMenuBar;
}



MtkMenu* TopMenu::TopMenuBarCreate(GtkApplication* app)
{
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(m_addFriendAction));
	g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(m_quitAction));
	g_signal_connect(m_addFriendAction, "activate", G_CALLBACK(AppAction::AddFriend), 0x0);
	g_signal_connect(m_quitAction, "activate", G_CALLBACK(AppAction::ApplicationQuit), app);

	return m_topMenuBar;
}

GtkWidget* TopMenu::Create()
{
	return m_topMenuButton;
}

// void TopMenu::Quit(GSimpleAction* action, GVariant* parameter, gpointer user_data)
// {
// 	std::cout << "Quiting application" << std::endl;
// 	g_application_quit(G_APPLICATION(user_data));
// }

void TopMenu::TopMenuShow(GtkWidget* button, GtkPopover* topMenu)
{
	gtk_popover_popup(topMenu);
}