#include "../include/MtkBox.h"
#include <stdexcept>

MtkBox::MtkBox(GtkOrientation orientation, int spacing)
{
	m_box = gtk_box_new(orientation, spacing);
	m_map = std::map<const int, GtkWidget*>();
}

MtkBox::~MtkBox() = default;

GtkWidget* MtkBox::AsGtkWidget()
{
	return m_box;
}

GtkBox* MtkBox::AsGtkBox()
{
	return GTK_BOX(m_box);
}

// If same sequenceNumber is used multiple times it will be added after each other
void MtkBox::Add(GtkWidget* const& child, const int sequenceNumber)
{
	int prevKey = 0;
	GtkWidget* prevWidget = 0x0;

	int maxKey = 0;

	for (auto const& [key, val] : m_map)
	{
		maxKey = key;
	}

	if (sequenceNumber < 1)
	{
		std::string error = "MtkBox::Add sequenceNumber must be at least 1: given sequenceNumber: " + std::to_string(sequenceNumber) + \
		(std::string)" Button label: " + gtk_button_get_label(GTK_BUTTON(child));
		throw std::invalid_argument(error);
	}

	if (m_map.end()->first != 0)
	{
		for (auto const& [key, currentWidget] : m_map)
		{
			if (sequenceNumber > maxKey)
			{
				gtk_box_append(GTK_BOX(m_box), child);
				break;
			}
			if (sequenceNumber > prevKey && sequenceNumber < key)
			{
				gtk_box_insert_child_after(GTK_BOX(m_box), child, prevWidget);
				break;
			}
			if (sequenceNumber == key)
			{
				gtk_box_insert_child_after(GTK_BOX(m_box), child, currentWidget);
				break;
			}

			prevKey = key;
			prevWidget = currentWidget;
		}
	}
	else
	{
		gtk_box_append(GTK_BOX(m_box), child);
	}

	m_map[sequenceNumber] = child;
}

void MtkBox::Append(GtkWidget* const& widget)
{
	gtk_box_append(GTK_BOX(m_box), widget);
}

void MtkBox::Prepend(GtkWidget* const& widget)
{
	gtk_box_prepend(GTK_BOX(m_box), widget);
}
