#include "../include/FriendsList.h"

FriendsList* FriendsList::globalInstance = 0x0;

FriendsList::FriendsList()
{
	friendsAndGroupsContainer = gtk_box_new(GtkOrientation::GTK_ORIENTATION_VERTICAL, 0);
	groupAndFriendsList = gtk_box_new(GtkOrientation::GTK_ORIENTATION_HORIZONTAL, 0);

	friendsListContainer = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

	scrolledWindow = gtk_scrolled_window_new();
	friendButton = gtk_toggle_button_new_with_label("Søren");
	friendButton1 = gtk_toggle_button_new_with_label("Anders");
	friendButton2 = gtk_toggle_button_new_with_label("Claus");

	friendsListButton = gtk_toggle_button_new();
	groupListButton = gtk_toggle_button_new();

	gtk_widget_set_size_request(scrolledWindow, 100, 0);

	gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(friendButton1), GTK_TOGGLE_BUTTON(friendButton));
	gtk_toggle_button_set_group(GTK_TOGGLE_BUTTON(friendButton2), GTK_TOGGLE_BUTTON(friendButton));

	gtk_box_append(GTK_BOX(friendsListContainer), friendButton);
	gtk_box_append(GTK_BOX(friendsListContainer), friendButton1);
	gtk_box_append(GTK_BOX(friendsListContainer), friendButton2);
	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolledWindow), friendsListContainer);


	gtk_widget_set_vexpand(scrolledWindow, true);


	gtk_box_append(GTK_BOX(groupAndFriendsList), friendsListButton);
	// gtk_box_append(GTK_BOX(groupAndFriendsList), groupListButton);
	gtk_box_append(GTK_BOX(friendsAndGroupsContainer), groupAndFriendsList);
	gtk_box_append(GTK_BOX(friendsAndGroupsContainer), scrolledWindow);
}

GtkWidget* FriendsList::Create()
{
	return friendsAndGroupsContainer;
}