#include "gtk/gtk.h"

class TypingField
{
	public:
		TypingField();
		~TypingField();

	public:
		GtkWidget* Create();

	private:
		GtkWidget* textView = 0x0;
		GtkWidget* button = 0x0;
};