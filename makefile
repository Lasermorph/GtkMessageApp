BIN:=program.exec

CXX_COMPILER:=g++
CC_COMPILER:=gcc

CXX_VERSION:=-std=c++23
CC_VERSION:=-std=c99

GTK4_FLAGS:=$(shell pkg-config --cflags gtk4)
GTK4_LINK:=$(shell pkg-config --libs gtk4)
GTKSOURCEVIEW_FLAGS:=$(shell pkg-config --cflags gtksourceview-5)
GTKSOURCEVIEW_LINK:=$(shell pkg-config --libs gtksourceview-5)
ADW1_FLAGS:=$(shell pkg-config --cflags libadwaita-1)
ADW1_LINK:=$(shell pkg-config --libs libadwaita-1)

CUSTOM_INCLUDE:=-I./include

CXX_OPTIMIZE:=-g3

CXX_FLAGS:=$(CXX_OPTIMIZE) $(GTK4_FLAGS) $(ADW1_FLAGS) $(GTKSOURCEVIEW_FLAGS) $(CXX_VERSION) $(CUSTOM_INCLUDE)

CXX_LINK:=$(GTK4_LINK) $(ADW1_LINK) $(GTKSOURCEVIEW_LINK)
default: mtktextview.o mtkscrolledwindow.o mtkbox.o mtktogglebutton.o mtkbutton.o mtkgmenuitem.o mtkgmenu.o friendslist.o hotkeys.o actions.o typingfield.o superhandler.o messagefield.o topmenu.o mainwindow.o main.o
	$(CXX_COMPILER) $(CXX_FLAGS) *.o -o $(BIN) $(CXX_LINK)

clean:
	-rm -rf *.o
	-rm -rf $(BIN)

mtktextview.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MtkTextView.cpp -o mtktextview.o

mtkscrolledwindow.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MtkScrolledWindow.cpp -o mtkscrolledwindow.o

mtkbox.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MtkBox.cpp -o mtkbox.o

mtktogglebutton.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MtkToggleButton.cpp -o mtktogglebutton.o

mtkbutton.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MtkButton.cpp -o mtkbutton.o

mtkgmenuitem.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MtkGMenuItem.cpp -o mtkgmenuitem.o

mtkgmenu.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MtkGMenu.cpp -o mtkgmenu.o

friendslist.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/FriendsList.cpp -o friendslist.o

hotkeys.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/Hotkeys.cpp -o hotkeys.o

actions.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/Actions.cpp -o actions.o

typingfield.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/TypingField.cpp -o typingfield.o

superhandler.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/SuperHandler.cpp -o superhandler.o

messagefield.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MessageField.cpp -o messagefield.o

topmenu.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/TopMenu.cpp -o topmenu.o

mainwindow.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MainWindow.cpp -o mainwindow.o

main.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./main.cpp -o main.o