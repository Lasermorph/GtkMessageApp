#include "gtk/gtk.h"

class FriendsList
{
	public:
		FriendsList();
		~FriendsList(){};

		static FriendsList* globalInstance;

	public:
		GtkWidget* Create();
	
	private:
		GtkWidget* friendsAndGroupsContainer = 0x0;
		GtkWidget* groupAndFriendsList = 0x0;

		GtkWidget* scrolledWindow = 0x0;
		GtkWidget* friendsListContainer = 0x0;
		GtkWidget* friendButton = 0x0;
		GtkWidget* friendButton1 = 0x0;
		GtkWidget* friendButton2 = 0x0;

		GtkWidget* friendsListButton = 0x0;
		GtkWidget* groupListButton = 0x0;
};