#include "../include/TopMenu.h"
#include "../include/Actions.h"
#include "../include/SuperHandler.h"
#include <iostream>
#include <vector>


TopMenu* TopMenu::globalInstance = 0x0;

TopMenu::TopMenu(GtkApplication* app)
{
	// m_topMenu = gtk_popover_menu_bar_new_from_model(G_MENU_MODEL(topMenuModel));

	m_menus = new std::vector<MtkMenu*>();

	m_newTopMenuBar = new MtkMenu("topMenuBar");
	MtkMenu* fileMenu = new MtkMenu("File");
	MtkMenu* editMenu = new MtkMenu("Edit");
	MtkMenu* anders = new MtkMenu("anders");
	MtkMenuItem* addFriendItem = new MtkMenuItem("Add Friend", "app.addFriend");
	MtkMenuItem* copyItem = new MtkMenuItem("Copy", "app.copy");
	MtkMenuItem* quitItem = new MtkMenuItem("Quit", "app.quit");

	fileMenu->AddMenuItem(addFriendItem);
	editMenu->AddMenuItem(copyItem);
	m_newTopMenuBar->AddSubMenu(fileMenu);
	m_newTopMenuBar->AddSubMenu(editMenu);
	fileMenu->AddSubMenu(anders);
	m_newTopMenuBar->AddMenuItem(quitItem);

	addFriendItem->ActionMapAdd(nullptr, G_ACTION_MAP(app));
	addFriendItem->SignalConnect(G_CALLBACK(AppAction::AddFriend), 0x0);
	quitItem->ActionMapAdd(0x0, G_ACTION_MAP(app));
	quitItem->SignalConnect(G_CALLBACK(AppAction::ApplicationQuit), app);

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
	g_object_unref(topMenuButtonStyle);
	topMenuButtonStyle = 0x0;
}

TopMenu::~TopMenu()
{
	gtk_widget_unparent(m_topMenu);
	delete m_menus;
	m_menus = 0x0;
	delete m_newTopMenuBar;
	m_newTopMenuBar = 0x0;
}



MtkMenu* TopMenu::TopMenuBarCreate(GtkApplication* app)
{
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