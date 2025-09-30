# Makefile for PetSpace Chat System
# Comprehensive build system without variables

# Default target - builds the executable
all: TestingMain

# Compile all object files and link into executable
TestingMain: TestingMain.o Users.o ChatRoom.o CtrlCat.o Dogorithm.o Command.o SendMessageCommand.o LogMessageCommand.o UserState.o OnlineState.o OfflineState.o DndState.o iterator.o chatIterator.o messageIterator.o
	g++ -std=c++11 -Wall -o TestingMain TestingMain.o Users.o ChatRoom.o CtrlCat.o Dogorithm.o Command.o SendMessageCommand.o LogMessageCommand.o UserState.o OnlineState.o OfflineState.o DndState.o iterator.o chatIterator.o messageIterator.o

# Compile TestingMain.cpp
TestingMain.o: TestingMain.cpp Users.h ChatRoom.h CtrlCat.h Dogorithm.h Command.h SendMessageCommand.h LogMessageCommand.h UserState.h OnlineState.h OfflineState.h DndState.h iterator.h chatIterator.h messageIterator.h
	g++ -std=c++11 -Wall -c TestingMain.cpp

# Compile Users.cpp
Users.o: Users.cpp Users.h ChatRoom.h Command.h SendMessageCommand.h LogMessageCommand.h UserState.h OnlineState.h OfflineState.h DndState.h
	g++ -std=c++11 -Wall -c Users.cpp

# Compile ChatRoom.cpp
ChatRoom.o: ChatRoom.cpp ChatRoom.h Users.h
	g++ -std=c++11 -Wall -c ChatRoom.cpp

# Compile CtrlCat.cpp
CtrlCat.o: CtrlCat.cpp CtrlCat.h ChatRoom.h Users.h
	g++ -std=c++11 -Wall -c CtrlCat.cpp

# Compile Dogorithm.cpp
Dogorithm.o: Dogorithm.cpp Dogorithm.h ChatRoom.h Users.h
	g++ -std=c++11 -Wall -c Dogorithm.cpp

# Compile Command.cpp
Command.o: Command.cpp Command.h
	g++ -std=c++11 -Wall -c Command.cpp

# Compile SendMessageCommand.cpp
SendMessageCommand.o: SendMessageCommand.cpp SendMessageCommand.h Command.h ChatRoom.h Users.h
	g++ -std=c++11 -Wall -c SendMessageCommand.cpp

# Compile LogMessageCommand.cpp
LogMessageCommand.o: LogMessageCommand.cpp LogMessageCommand.h Command.h ChatRoom.h Users.h
	g++ -std=c++11 -Wall -c LogMessageCommand.cpp

# Compile UserState.cpp
UserState.o: UserState.cpp UserState.h
	g++ -std=c++11 -Wall -c UserState.cpp

# Compile OnlineState.cpp
OnlineState.o: OnlineState.cpp OnlineState.h UserState.h
	g++ -std=c++11 -Wall -c OnlineState.cpp

# Compile OfflineState.cpp
OfflineState.o: OfflineState.cpp OfflineState.h UserState.h
	g++ -std=c++11 -Wall -c OfflineState.cpp

# Compile DndState.cpp
DndState.o: DndState.cpp DndState.h UserState.h
	g++ -std=c++11 -Wall -c DndState.cpp

# Compile iterator.cpp
iterator.o: iterator.cpp iterator.h ChatRoom.h
	g++ -std=c++11 -Wall -c iterator.cpp

# Compile chatIterator.cpp
chatIterator.o: chatIterator.cpp chatIterator.h iterator.h ChatRoom.h
	g++ -std=c++11 -Wall -c chatIterator.cpp

# Compile messageIterator.cpp
messageIterator.o: messageIterator.cpp messageIterator.h iterator.h ChatRoom.h Users.h
	g++ -std=c++11 -Wall -c messageIterator.cpp

# Run the program
run: TestingMain
	./TestingMain

# Clean up object files and executable
clean:
	rm -f TestingMain.o Users.o ChatRoom.o CtrlCat.o Dogorithm.o Command.o SendMessageCommand.o LogMessageCommand.o UserState.o OnlineState.o OfflineState.o DndState.o iterator.o chatIterator.o messageIterator.o TestingMain

# Phony targets (not actual files)
.PHONY: all run clean