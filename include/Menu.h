#include <gtk/gtk.h>
#include <iostream>
#include <vector>

class MtkMenu
{
	public:
		MtkMenu(const std::string& name);
		~MtkMenu();

		void AddSubMenu(MtkMenu* subMenu);
		void AddMenuItem(std::string label, std::string detailedAction);
		MtkMenu* GetSubMenu(const std::string& subMenuName);
		GMenu* AsGMenu();
		std::string GetName();

	private:
		std::string m_name;
		GMenu* m_gMenu = 0x0;
		std::vector<gpointer>* m_menuItems = 0x0;
		std::vector<MtkMenu*>* m_subMenus = 0x0;
};