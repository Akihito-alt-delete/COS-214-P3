#include <iostream>
#include <vector>
#include <string>
#include "Users.h"
#include "ChatRoom.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"

using namespace std;

/**
 * @file testingMain.cpp
 * @brief Comprehensive test suite for PetSpace chat system
 * @author Huai-en Ryan Liao & Zaman Bassa
 * @date September 2025
 */


int testsPassed = 0;
int totalTests = 0;

#define TEST_START(name) \
    cout << "\n=== Testing " << name << " ===" << endl; \
    totalTests++;

#define TEST_END(name) \
    cout << "✓ " << name << " passed!" << endl; \
    testsPassed++;

#define ASSERT(condition, message) \
    if (!(condition)) { \
        cout << "❌ ASSERTION FAILED: " << message << endl; \
        cout << "   Expected: " << #condition << endl; \
        return; \
    }

void testBasicUserCreation() {
    TEST_START("Basic User Creation");
    
    Users* user1 = new Users("Alice");
    Users* user2 = new Users("Bob");
    
    ASSERT(user1->getName() == "Alice", "User1 name should be Alice");
    ASSERT(user2->getName() == "Bob", "User2 name should be Bob");
    
    delete user1;
    delete user2;
    
    TEST_END("Basic User Creation");
}

void testBasicChatRoomCreation() {
    TEST_START("Basic Chat Room Creation");
    
    CtrlCat* ctrlCatRoom = new CtrlCat();
    Dogorithm* dogorithmRoom = new Dogorithm();
    
    ASSERT(ctrlCatRoom->getRoomName() == "CtrlCat", "CtrlCat room name should be correct");
    ASSERT(dogorithmRoom->getRoomName() == "Dogorithm", "Dogorithm room name should be correct");
    
    // Test initial state
    ASSERT(ctrlCatRoom->getUsers().empty(), "CtrlCat should start with no users");
    ASSERT(ctrlCatRoom->getChatHistory().empty(), "CtrlCat should start with empty history");
    ASSERT(dogorithmRoom->getUsers().empty(), "Dogorithm should start with no users");
    ASSERT(dogorithmRoom->getChatHistory().empty(), "Dogorithm should start with empty history");
    
    delete ctrlCatRoom;
    delete dogorithmRoom;
    
    TEST_END("Basic Chat Room Creation");
}

void testUserRegistration() {
    TEST_START("User Registration");
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    // Test normal registration
    room->registerUser(alice);
    ASSERT(room->getUsers().size() == 1, "Room should have 1 user after registration");
    ASSERT(room->getUsers()[0] == alice, "Registered user should be Alice");
    
    room->registerUser(bob);
    ASSERT(room->getUsers().size() == 2, "Room should have 2 users after second registration");
    
    // Test duplicate registration
    room->registerUser(alice);
    ASSERT(room->getUsers().size() == 2, "Room should still have 2 users after duplicate registration");
    
    // Test null user registration
    room->registerUser(nullptr);
    ASSERT(room->getUsers().size() == 2, "Room should still have 2 users after null registration");
    
    delete alice;
    delete bob;
    delete room;
    
    TEST_END("User Registration");
}

void testUserRemoval() {
    TEST_START("User Removal");
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    // Add users
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    ASSERT(room->getUsers().size() == 3, "Room should have 3 users");
    
    // Remove middle user
    room->removeUser(bob);
    ASSERT(room->getUsers().size() == 2, "Room should have 2 users after removal");
    
    // Verify correct users remain
    vector<Users*> remainingUsers = room->getUsers();
    bool aliceFound = false, charlieFound = false, bobFound = false;
    for (Users* user : remainingUsers) {
        if (user == alice) aliceFound = true;
        if (user == charlie) charlieFound = true;
        if (user == bob) bobFound = true;
    }
    ASSERT(aliceFound && charlieFound && !bobFound, "Alice and Charlie should remain, Bob should be gone");
    
    // Test removing non-existent user
    room->removeUser(bob); // Already removed
    ASSERT(room->getUsers().size() == 2, "Room should still have 2 users");
    
    // Test removing null user
    room->removeUser(nullptr);
    ASSERT(room->getUsers().size() == 2, "Room should still have 2 users after null removal");
    
    delete alice;
    delete bob;
    delete charlie;
    delete room;
    
    TEST_END("User Removal");
}

void testMessageSending() {
    TEST_START("Message Sending");
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    // Test sending message
    alice->send("Hello everyone!", room);
    
    // Check chat history
    vector<string> history = room->getChatHistory();
    ASSERT(history.size() == 1, "Chat history should have 1 message");
    ASSERT(history[0] == "[Alice]: Hello everyone!", "Message format should be correct");
    
    // Send another message
    bob->send("Hi Alice!", room);
    history = room->getChatHistory();
    ASSERT(history.size() == 2, "Chat history should have 2 messages");
    ASSERT(history[1] == "[Bob]: Hi Alice!", "Second message format should be correct");
    
    delete alice;
    delete bob;
    delete room;
    
    TEST_END("Message Sending");
}

void testMultipleRooms() {
    TEST_START("Multiple Chat Rooms");
    
    CtrlCat* ctrlCat = new CtrlCat();
    Dogorithm* dogorithm = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    // Register users to different rooms
    ctrlCat->registerUser(alice);
    ctrlCat->registerUser(bob);
    dogorithm->registerUser(alice);
    
    // Send messages to different rooms
    alice->send("I love cats!", ctrlCat);
    alice->send("Dogs are great too!", dogorithm);
    bob->send("Cats rule!", ctrlCat);
    
    // Check individual room histories
    vector<string> ctrlCatHistory = ctrlCat->getChatHistory();
    vector<string> dogorithmHistory = dogorithm->getChatHistory();
    
    ASSERT(ctrlCatHistory.size() == 2, "CtrlCat should have 2 messages");
    ASSERT(dogorithmHistory.size() == 1, "Dogorithm should have 1 message");
    ASSERT(ctrlCatHistory[0] == "[Alice]: I love cats!", "First CtrlCat message should be correct");
    ASSERT(ctrlCatHistory[1] == "[Bob]: Cats rule!", "Second CtrlCat message should be correct");
    ASSERT(dogorithmHistory[0] == "[Alice]: Dogs are great too!", "Dogorithm message should be correct");
    
    delete alice;
    delete bob;
    delete ctrlCat;
    delete dogorithm;
    
    TEST_END("Multiple Chat Rooms");
}

void testCommandPattern() {
    TEST_START("Command Pattern");
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    // Test direct command creation and execution
    Command* sendCmd = new SendMessageCommand(room, alice, "Direct command test");
    Command* logCmd = new LogMessageCommand(room, alice, "Direct command test");
    
    sendCmd->execute();
    logCmd->execute();
    
    // Verify message was logged
    vector<string> history = room->getChatHistory();
    ASSERT(history.size() == 1, "History should have 1 message from direct command");
    ASSERT(history[0] == "[Alice]: Direct command test", "Direct command message should be correct");
    
    delete sendCmd;
    delete logCmd;
    delete alice;
    delete room;
    
    TEST_END("Command Pattern");
}

void testNullPointerHandling() {
    TEST_START("Null Pointer Handling");
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    // Test sending message to null room
    alice->send("Test message", nullptr);
    
    // Test command with null parameters
    Command* nullRoomCmd = new SendMessageCommand(nullptr, alice, "test");
    Command* nullUserCmd = new SendMessageCommand(room, nullptr, "test");
    
    nullRoomCmd->execute(); // Should not crash
    nullUserCmd->execute(); // Should not crash
    
    delete nullRoomCmd;
    delete nullUserCmd;
    delete alice;
    delete room;
    
    TEST_END("Null Pointer Handling");
}

void testEmptyMessages() {
    TEST_START("Empty Messages");
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    // Test empty message
    alice->send("", room);
    
    vector<string> history = room->getChatHistory();
    ASSERT(history.size() == 1, "Empty message should still be logged");
    ASSERT(history[0] == "[Alice]: ", "Empty message format should be correct");
    
    delete alice;
    delete room;
    
    TEST_END("Empty Messages");
}

void testLargeNumberOfUsers() {
    TEST_START("Large Number of Users");
    
    CtrlCat* room = new CtrlCat();
    vector<Users*> users;
    
    // Create and register 20 users
    for (size_t i = 0; i < 20; i++) {
        Users* user = new Users("User" + to_string(i));
        users.push_back(user);
        room->registerUser(user);
    }
    
    ASSERT(room->getUsers().size() == 20, "Room should have 20 users");
    
    // Send message from first user
    users[0]->send("Hello from User0!", room);
    
    vector<string> history = room->getChatHistory();
    ASSERT(history.size() == 1, "History should have 1 message");
    ASSERT(history[0] == "[User0]: Hello from User0!", "Message should be correct");
    
    // Clean up
    for (Users* user : users) {
        delete user;
    }
    delete room;
    
    TEST_END("Large Number of Users");
}

void testMixedScenario() {
    TEST_START("Mixed Scenario");
    
    CtrlCat* ctrlCat = new CtrlCat();
    Dogorithm* dogorithm = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    // Complex scenario
    ctrlCat->registerUser(alice);
    ctrlCat->registerUser(bob);
    dogorithm->registerUser(alice);
    dogorithm->registerUser(charlie);
    
    alice->send("Hello CtrlCat!", ctrlCat);
    bob->send("Hi Alice!", ctrlCat);
    alice->send("Hello Dogorithm!", dogorithm);
    charlie->send("Woof woof!", dogorithm);
    
    // Remove bob from ctrlCat
    ctrlCat->removeUser(bob);
    
    alice->send("Bob left :(", ctrlCat);
    
    // Verify final state
    ASSERT(ctrlCat->getUsers().size() == 1, "CtrlCat should have 1 user");
    ASSERT(dogorithm->getUsers().size() == 2, "Dogorithm should have 2 users");
    ASSERT(ctrlCat->getChatHistory().size() == 3, "CtrlCat should have 3 messages");
    ASSERT(dogorithm->getChatHistory().size() == 2, "Dogorithm should have 2 messages");
    
    delete alice;
    delete bob;
    delete charlie;
    delete ctrlCat;
    delete dogorithm;
    
    TEST_END("Mixed Scenario");
}

void runAllTests() {
    cout << "🚀 Starting PetSpace Chat System Tests..." << endl;
    cout << "===========================================" << endl;
    
    testBasicUserCreation();
    testBasicChatRoomCreation();
    testUserRegistration();
    testUserRemoval();
    testMessageSending();
    testMultipleRooms();
    testCommandPattern();
    testNullPointerHandling();
    testEmptyMessages();
    testLargeNumberOfUsers();
    testMixedScenario();
    
    cout << "\n===========================================" << endl;
    cout << "🏁 Test Results: " << testsPassed << "/" << totalTests << " tests passed" << endl;
    
    if (testsPassed == totalTests) {
        cout << "🎉 All tests passed! No memory leaks expected." << endl;
    } else {
        cout << "❌ Some tests failed. Please check the implementation." << endl;
    }
    cout << "===========================================" << endl;
}

int main() {
    runAllTests();
    return 0;
}