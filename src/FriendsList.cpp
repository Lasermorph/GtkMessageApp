#include "../include/FriendsList.h"
#include "../include/MtkToggleButton.h"

FriendsList* FriendsList::globalInstance = 0x0;

FriendsList::FriendsList()
{
	m_scrolledWindow = MtkScrolledWindow();
	gtk_widget_set_vexpand(m_scrolledWindow.AsGtkWidget(), true);

	MtkToggleButton testNewButton = MtkToggleButton("Søren");
	MtkToggleButton testNewButton1 = MtkToggleButton("Anders");
	MtkToggleButton testNewButton2 = MtkToggleButton("Claus");

	MtkBox friendsList = MtkBox(GtkOrientation::GTK_ORIENTATION_VERTICAL, 0);

	friendsList.Add(testNewButton, 2);
	friendsList.Add(testNewButton1, 1);
	friendsList.Add(testNewButton2, 3);

	testNewButton1.SetGroup(testNewButton);
	testNewButton2.SetGroup(testNewButton);

	m_scrolledWindow.SetChild(friendsList);
}

GtkWidget* FriendsList::Create()
{
	return m_scrolledWindow.AsGtkWidget();
}
