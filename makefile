BIN:=program.exec

CXX_COMPILER:=g++
CC_COMPILER:=gcc

CXX_VERSION:=-std=c++17
CC_VERSION:=-std=c99

GTK4_FLAGS:=$(shell pkg-config --cflags gtk4)
GTK4_LINK:=$(shell pkg-config --libs gtk4)

CUSTOM_INCLUDE:=-I./include

CXX_OPTIMIZE:=-g3

CXX_FLAGS:=$(GTK4_FLAGS) $(CXX_VERSION) $(CUSTOM_INCLUDE) $(CXX_OPTIMIZE)

CXX_LINK:=$(GTK4_LINK)
default: actions.o typingfield.o superhandler.o messagefield.o topmenubar.o mainwindow.o main.o
	$(CXX_COMPILER) $(CXX_FLAGS) *.o -o $(BIN) $(CXX_LINK)

clean:
	-rm -rf *.o
	-rm -rf $(BIN)

actions.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/Actions.cpp -o actions.o

typingfield.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/TypingField.cpp -o typingfield.o

superhandler.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/SuperHandler.cpp -o superhandler.o

messagefield.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MessageField.cpp -o messagefield.o

topmenubar.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/TopMenuBar.cpp -o topmenubar.o

mainwindow.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./src/MainWindow.cpp -o mainwindow.o

main.o:
	$(CXX_COMPILER) -c $(CXX_FLAGS) ./main.cpp -o main.o