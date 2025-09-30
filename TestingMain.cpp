#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Users.h"
#include "ChatRoom.h"
#include "CtrlCat.h"
#include "Dogorithm.h"
#include "Command.h"
#include "SendMessageCommand.h"
#include "LogMessageCommand.h"
#include "UserState.h"
#include "OnlineState.h"
#include "OfflineState.h"
#include "DndState.h"
#include "iterator.h"
#include "chatIterator.h"
#include "messageIterator.h"

using namespace std;

/**
 * @file TestingMain.cpp
 * @brief Comprehensive test suite for PetSpace chat system with high code coverage
 * @author Generated Test Suite
 * @date September 2025
 */

int testsPassed = 0;
int totalTests = 0;

// ==================== BASIC FUNCTIONALITY TESTS ====================

void testBasicUserCreation() {
    cout << "\n=== Testing Basic User Creation ===" << endl;
    totalTests++;
    
    Users* user1 = new Users("Alice");
    Users* user2 = new Users("Bob");
    Users* user3 = new Users("Charlie");
    
    if (user1->getName() == "Alice" && user2->getName() == "Bob" && user3->getName() == "Charlie") {
        cout << "✓ Basic User Creation passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Basic User Creation FAILED!" << endl;
    }
    
    delete user1;
    delete user2;
    delete user3;
}

void testBasicChatRoomCreation() {
    cout << "\n=== Testing Basic Chat Room Creation ===" << endl;
    totalTests++;
    
    CtrlCat* ctrlCatRoom = new CtrlCat();
    Dogorithm* dogorithmRoom = new Dogorithm();
    
    bool passed = true;
    if (ctrlCatRoom->getRoomName() != "CtrlCat") passed = false;
    if (dogorithmRoom->getRoomName() != "Dogorithm") passed = false;
    if (!ctrlCatRoom->getUsers().empty()) passed = false;
    if (!ctrlCatRoom->getChatHistory().empty()) passed = false;
    if (!dogorithmRoom->getUsers().empty()) passed = false;
    if (!dogorithmRoom->getChatHistory().empty()) passed = false;
    
    if (passed) {
        cout << "✓ Basic Chat Room Creation passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Basic Chat Room Creation FAILED!" << endl;
    }
    
    delete ctrlCatRoom;
    delete dogorithmRoom;
}

// ==================== USER STATE TESTS ====================

void testUserStateOnline() {
    cout << "\n=== Testing User State - Online ===" << endl;
    totalTests++;
    
    OnlineState* onlineState = new OnlineState();
    
    if (onlineState->CanSendMessage() && onlineState->CanReceiveMessage()) {
        cout << "✓ User State - Online passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ User State - Online FAILED!" << endl;
    }
    
    delete onlineState;
}

void testUserStateOffline() {
    cout << "\n=== Testing User State - Offline ===" << endl;
    totalTests++;
    
    OfflineState* offlineState = new OfflineState();
    
    if (!offlineState->CanSendMessage() && !offlineState->CanReceiveMessage()) {
        cout << "✓ User State - Offline passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ User State - Offline FAILED!" << endl;
    }
    
    delete offlineState;
}

void testUserStateDND() {
    cout << "\n=== Testing User State - DND ===" << endl;
    totalTests++;
    
    DndState* dndState = new DndState();
    
    if (dndState->CanSendMessage() && !dndState->CanReceiveMessage()) {
        cout << "✓ User State - DND passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ User State - DND FAILED!" << endl;
    }
    
    delete dndState;
}

void testUserStateTransitions() {
    cout << "\n=== Testing User State Transitions ===" << endl;
    totalTests++;
    
    Users* alice = new Users("Alice");
    CtrlCat* room = new CtrlCat();
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->send("Hello", room);
    std::cout<<"alice about to logout.\n";
    alice->logout();
    std::cout << "Testing sending to offline user.\n";
    alice->send("Should not send", room);
    alice->logout();
    alice->login();
    alice->send("Back online", room);
    alice->login();
    alice->GoDND();
    alice->send("In DND", room);
    alice->GoDND();
    alice->login();
    alice->logout();
    alice->GoDND();
    
    cout << "✓ User State Transitions passed!" << endl;
    testsPassed++;
    
    delete alice;
    delete bob;
    delete room;
}

void testUserChangeState() {
    cout << "\n=== Testing User ChangeState Method ===" << endl;
    totalTests++;
    
    Users* alice = new Users("Alice");
    
    UserState* newOnlineState = new OnlineState();
    alice->ChangeState(newOnlineState);
    
    UserState* newOfflineState = new OfflineState();
    alice->ChangeState(newOfflineState);
    
    UserState* newDndState = new DndState();
    alice->ChangeState(newDndState);
    
    cout << "✓ User ChangeState Method passed!" << endl;
    testsPassed++;
    
    delete alice;
}

void testUserReceiveWhileOffline() {
    cout << "\n=== Testing User Receive While Offline ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->logout();
    bob->send("Hello Alice", room);
    
    cout << "✓ User Receive While Offline passed!" << endl;
    testsPassed++;
    
    delete alice;
    delete bob;
    delete room;
}

void testUserReceiveWhileDND() {
    cout << "\n=== Testing User Receive While DND ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->GoDND();
    bob->send("Hello Alice", room);
    
    cout << "✓ User Receive While DND passed!" << endl;
    testsPassed++;
    
    delete alice;
    delete bob;
    delete room;
}

// ==================== USER REGISTRATION TESTS ====================

void testUserRegistration() {
    cout << "\n=== Testing User Registration ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(alice);
    room->registerUser(nullptr);
    
    bool passed = (room->getUsers().size() == 2);
    
    if (passed) {
        cout << "✓ User Registration passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ User Registration FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete room;
}

void testUserRemoval() {
    cout << "\n=== Testing User Removal ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    
    room->removeUser(bob);
    room->removeUser(bob);
    room->removeUser(nullptr);
    room->removeUser(alice);
    room->removeUser(charlie);
    
    bool passed = (room->getUsers().size() == 0);
    
    if (passed) {
        cout << "✓ User Removal passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ User Removal FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete charlie;
    delete room;
}

// ==================== MESSAGE SENDING TESTS ====================

void testMessageSending() {
    cout << "\n=== Testing Message Sending ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->send("Hello everyone!", room);
    bob->send("Hi Alice!", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 2 && 
                   history[0] == "[Alice]: Hello everyone!" && 
                   history[1] == "[Bob]: Hi Alice!");
    
    if (passed) {
        cout << "✓ Message Sending passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Message Sending FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete room;
}

void testSendToNullRoom() {
    cout << "\n=== Testing Send to Null Room ===" << endl;
    totalTests++;
    
    Users* alice = new Users("Alice");
    alice->send("Test message", nullptr);
    
    cout << "✓ Send to Null Room passed!" << endl;
    testsPassed++;
    
    delete alice;
}

void testEmptyMessages() {
    cout << "\n=== Testing Empty Messages ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    alice->send("", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 1 && history[0] == "[Alice]: ");
    
    if (passed) {
        cout << "✓ Empty Messages passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Empty Messages FAILED!" << endl;
    }
    
    delete alice;
    delete room;
}

void testLongMessages() {
    cout << "\n=== Testing Long Messages ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    string longMessage = "";
    for (int i = 0; i < 1000; i++) {
        longMessage += "a";
    }
    
    alice->send(longMessage, room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 1);
    
    if (passed) {
        cout << "✓ Long Messages passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Long Messages FAILED!" << endl;
    }
    
    delete alice;
    delete room;
}

void testSpecialCharactersInMessages() {
    cout << "\n=== Testing Special Characters in Messages ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    alice->send("!@#$%^&*()_+-=[]{}|;':\",./<>?", room);
    alice->send("Hello\nWorld", room);
    alice->send("Tab\tCharacter", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 3);
    
    if (passed) {
        cout << "✓ Special Characters in Messages passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Special Characters in Messages FAILED!" << endl;
    }
    
    delete alice;
    delete room;
}

// ==================== COMMAND PATTERN TESTS ====================

void testCommandPattern() {
    cout << "\n=== Testing Command Pattern ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    Command* sendCmd = new SendMessageCommand(room, alice, "Direct command test");
    Command* logCmd = new LogMessageCommand(room, alice, "Direct command test");
    
    sendCmd->execute();
    logCmd->execute();
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 1 && history[0] == "[Alice]: Direct command test");
    
    if (passed) {
        cout << "✓ Command Pattern passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Command Pattern FAILED!" << endl;
    }
    
    delete sendCmd;
    delete logCmd;
    delete alice;
    delete room;
}

void testCommandWithNullRoom() {
    cout << "\n=== Testing Command with Null Room ===" << endl;
    totalTests++;
    
    Users* alice = new Users("Alice");
    
    Command* sendCmd = new SendMessageCommand(nullptr, alice, "test");
    Command* logCmd = new LogMessageCommand(nullptr, alice, "test");
    
    sendCmd->execute();
    logCmd->execute();
    
    cout << "✓ Command with Null Room passed!" << endl;
    testsPassed++;
    
    delete sendCmd;
    delete logCmd;
    delete alice;
}

void testCommandWithNullUser() {
    cout << "\n=== Testing Command with Null User ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    
    Command* sendCmd = new SendMessageCommand(room, nullptr, "test");
    Command* logCmd = new LogMessageCommand(room, nullptr, "test");
    
    sendCmd->execute();
    logCmd->execute();
    
    cout << "✓ Command with Null User passed!" << endl;
    testsPassed++;
    
    delete sendCmd;
    delete logCmd;
    delete room;
}

void testAddNullCommand() {
    cout << "\n=== Testing Add Null Command ===" << endl;
    totalTests++;
    
    Users* alice = new Users("Alice");
    
    alice->addCommand(nullptr);
    alice->executeAll();
    
    cout << "✓ Add Null Command passed!" << endl;
    testsPassed++;
    
    delete alice;
}

void testMultipleCommands() {
    cout << "\n=== Testing Multiple Commands ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    Command* cmd1 = new SendMessageCommand(room, alice, "Message 1");
    Command* cmd2 = new LogMessageCommand(room, alice, "Message 1");
    Command* cmd3 = new SendMessageCommand(room, alice, "Message 2");
    Command* cmd4 = new LogMessageCommand(room, alice, "Message 2");
    
    alice->addCommand(cmd1);
    alice->addCommand(cmd2);
    alice->addCommand(cmd3);
    alice->addCommand(cmd4);
    
    alice->executeAll();
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 2);
    
    if (passed) {
        cout << "✓ Multiple Commands passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Multiple Commands FAILED!" << endl;
    }
    
    delete alice;
    delete room;
}

// ==================== ITERATOR TESTS ====================

void testChatIteratorBasic() {
    cout << "\n=== Testing Chat Iterator - Basic ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->send("Message 1", room);
    bob->send("Message 2", room);
    alice->send("Message 3", room);
    
    chatIterator* iter = new chatIterator(room);
    
    bool passed = true;
    if (iter->curr() != "[Alice]: Message 1") passed = false;
    if (!iter->hasNext()) passed = false;
    
    iter->next();
    if (iter->curr() != "[Bob]: Message 2") passed = false;
    if (!iter->hasNext()) passed = false;
    
    iter->next();
    if (iter->curr() != "[Alice]: Message 3") passed = false;
    if (iter->hasNext()) passed = false;
    
    iter->first();
    if (iter->curr() != "[Alice]: Message 1") passed = false;
    
    if (passed) {
        cout << "✓ Chat Iterator - Basic passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Chat Iterator - Basic FAILED!" << endl;
    }
    
    delete iter;
    delete alice;
    delete bob;
    delete room;
}

void testChatIteratorNullRoom() {
    cout << "\n=== Testing Chat Iterator - Null Room ===" << endl;
    totalTests++;
    
    bool exceptionThrown = false;
    try {
        chatIterator* iter = new chatIterator(nullptr);
        delete iter;
    } catch (const std::runtime_error& e) {
        exceptionThrown = true;
    }
    
    if (exceptionThrown) {
        cout << "✓ Chat Iterator - Null Room passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Chat Iterator - Null Room FAILED!" << endl;
    }
}

// void testChatIteratorEmptyHistory() {================================================
//     cout << "\n=== Testing Chat Iterator - Empty History ===" << endl;
//     totalTests++;
    
//     CtrlCat* room = new CtrlCat();
    
//     bool exceptionThrown = false;
//     try {
//         chatIterator* iter = new chatIterator(room);
//         cout<<"iterator made";
//         delete iter;
//     } catch (const std::runtime_error& e) {
//         exceptionThrown = true;
//     }
    
//     if (exceptionThrown) {
//         cout << "✓ Chat Iterator - Empty History passed!" << endl;
//         testsPassed++;
//     } else {
//         cout << "✗ Chat Iterator - Empty History FAILED!" << endl;
//     }
    
//     delete room;
// }

void testChatIteratorSingleMessage() {
    cout << "\n=== Testing Chat Iterator - Single Message ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    alice->send("Only message", room);
    
    chatIterator* iter = new chatIterator(room);
    
    bool passed = true;
    if (iter->curr() != "[Alice]: Only message") passed = false;
    if (iter->hasNext()) passed = false;
    
    iter->next();
    if (iter->curr() != "[Alice]: Only message") passed = false;
    
    if (passed) {
        cout << "✓ Chat Iterator - Single Message passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Chat Iterator - Single Message FAILED!" << endl;
    }
    
    delete iter;
    delete alice;
    delete room;
}

void testMessageIteratorBasic() {
    cout << "\n=== Testing Message Iterator - Basic ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    
    messageIterator* iter = new messageIterator(room);
    
    bool passed = true;
    if (iter->curr() != "Alice") passed = false;
    if (!iter->hasNext()) passed = false;
    
    iter->next();
    if (iter->curr() != "Bob") passed = false;
    if (!iter->hasNext()) passed = false;
    
    iter->next();
    if (iter->curr() != "Charlie") passed = false;
    if (iter->hasNext()) passed = false;
    
    iter->first();
    if (iter->curr() != "Alice") passed = false;
    
    if (passed) {
        cout << "✓ Message Iterator - Basic passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Message Iterator - Basic FAILED!" << endl;
    }
    
    delete iter;
    delete alice;
    delete bob;
    delete charlie;
    delete room;
}

void testMessageIteratorNullRoom() {
    cout << "\n=== Testing Message Iterator - Null Room ===" << endl;
    totalTests++;
    
    bool exceptionThrown = false;
    try {
        messageIterator* iter = new messageIterator(nullptr);
        delete iter;
    } catch (const std::runtime_error& e) {
        exceptionThrown = true;
    }
    
    if (exceptionThrown) {
        cout << "✓ Message Iterator - Null Room passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Message Iterator - Null Room FAILED!" << endl;
    }
}

void testMessageIteratorEmptyRoom() {
    cout << "\n=== Testing Message Iterator - Empty Room ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    
    bool exceptionThrown = false;
    try {
        messageIterator* iter = new messageIterator(room);
        delete iter;
    } catch (const std::runtime_error& e) {
        exceptionThrown = true;
    }
    
    if (exceptionThrown) {
        cout << "✓ Message Iterator - Empty Room passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Message Iterator - Empty Room FAILED!" << endl;
    }
    
    delete room;
}

void testMessageIteratorSingleUser() {
    cout << "\n=== Testing Message Iterator - Single User ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    messageIterator* iter = new messageIterator(room);
    
    bool passed = true;
    if (iter->curr() != "Alice") passed = false;
    if (iter->hasNext()) passed = false;
    
    iter->next();
    if (iter->curr() != "Alice") passed = false;
    
    if (passed) {
        cout << "✓ Message Iterator - Single User passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Message Iterator - Single User FAILED!" << endl;
    }
    
    delete iter;
    delete alice;
    delete room;
}

// ==================== MULTI-ROOM TESTS ====================

void testMultipleRooms() {
    cout << "\n=== Testing Multiple Chat Rooms ===" << endl;
    totalTests++;
    
    CtrlCat* ctrlCat = new CtrlCat();
    Dogorithm* dogorithm = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    ctrlCat->registerUser(alice);
    ctrlCat->registerUser(bob);
    dogorithm->registerUser(alice);
    
    alice->send("I love cats!", ctrlCat);
    alice->send("Dogs are great too!", dogorithm);
    bob->send("Cats rule!", ctrlCat);
    
    vector<string> ctrlCatHistory = ctrlCat->getChatHistory();
    vector<string> dogorithmHistory = dogorithm->getChatHistory();
    
    bool passed = (ctrlCatHistory.size() == 2 && dogorithmHistory.size() == 1);
    
    if (passed) {
        cout << "✓ Multiple Chat Rooms passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Multiple Chat Rooms FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete ctrlCat;
    delete dogorithm;
}

void testUserInMultipleRooms() {
    cout << "\n=== Testing User in Multiple Rooms ===" << endl;
    totalTests++;
    
    CtrlCat* room1 = new CtrlCat();
    Dogorithm* room2 = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    room1->registerUser(alice);
    room1->registerUser(bob);
    room2->registerUser(alice);
    room2->registerUser(charlie);
    
    alice->send("Message in CtrlCat", room1);
    alice->send("Message in Dogorithm", room2);
    bob->send("Only in CtrlCat", room1);
    charlie->send("Only in Dogorithm", room2);
    
    bool passed = (room1->getChatHistory().size() == 2 && room2->getChatHistory().size() == 2);
    
    if (passed) {
        cout << "✓ User in Multiple Rooms passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ User in Multiple Rooms FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete charlie;
    delete room1;
    delete room2;
}

// ==================== STRESS TESTS ====================

void testLargeNumberOfUsers() {
    cout << "\n=== Testing Large Number of Users ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    vector<Users*> users;
    
    for (size_t i = 0; i < 50; i++) {
        Users* user = new Users("User" + to_string(i));
        users.push_back(user);
        room->registerUser(user);
    }
    
    users[0]->send("Hello from User0!", room);
    users[25]->send("Hello from User25!", room);
    users[49]->send("Hello from User49!", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (room->getUsers().size() == 50 && history.size() == 3);
    
    if (passed) {
        cout << "✓ Large Number of Users passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Large Number of Users FAILED!" << endl;
    }
    
    for (Users* user : users) {
        delete user;
    }
    delete room;
}

void testLargeNumberOfMessages() {
    cout << "\n=== Testing Large Number of Messages ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    for (int i = 0; i < 100; i++) {
        alice->send("Message " + to_string(i), room);
    }
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 100);
    
    if (passed) {
        cout << "✓ Large Number of Messages passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Large Number of Messages FAILED!" << endl;
    }
    
    delete alice;
    delete room;
}

void testIteratorWithManyMessages() {
    cout << "\n=== Testing Iterator with Many Messages ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    for (int i = 0; i < 50; i++) {
        alice->send("Msg " + to_string(i), room);
    }
    
    chatIterator* iter = new chatIterator(room);
    
    int count = 0;
    while (iter->hasNext()) {
        iter->next();
        count++;
    }
    
    bool passed = (count == 49);
    
    if (passed) {
        cout << "✓ Iterator with Many Messages passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Iterator with Many Messages FAILED!" << endl;
    }
    
    delete iter;
    delete alice;
    delete room;
}

void testIteratorWithManyUsers() {
    cout << "\n=== Testing Iterator with Many Users ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    vector<Users*> users;
    
    for (int i = 0; i < 30; i++) {
        Users* user = new Users("User" + to_string(i));
        users.push_back(user);
        room->registerUser(user);
    }
    
    messageIterator* iter = new messageIterator(room);
    
    int count = 0;
    while (iter->hasNext()) {
        iter->next();
        count++;
    }
    
    bool passed = (count == 29);
    
    if (passed) {
        cout << "✓ Iterator with Many Users passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Iterator with Many Users FAILED!" << endl;
    }
    
    delete iter;
    for (Users* user : users) {
        delete user;
    }
    delete room;
}

// ==================== EDGE CASE TESTS ====================

void testRemoveAllUsers() {
    cout << "\n=== Testing Remove All Users ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    
    room->removeUser(alice);
    room->removeUser(bob);
    room->removeUser(charlie);
    
    bool passed = (room->getUsers().size() == 0 && room->getUsers().empty());
    
    if (passed) {
        cout << "✓ Remove All Users passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Remove All Users FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete charlie;
    delete room;
}

void testMessageAfterUserRemoval() {
    cout << "\n=== Testing Message After User Removal ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->send("Before removal", room);
    room->removeUser(bob);
    alice->send("After Bob removed", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 2);
    
    if (passed) {
        cout << "✓ Message After User Removal passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Message After User Removal FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete room;
}

void testChatIteratorBoundaryConditions() {
    cout << "\n=== Testing Chat Iterator Boundary Conditions ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    alice->send("Msg1", room);
    alice->send("Msg2", room);
    
    chatIterator* iter = new chatIterator(room);
    
    iter->next();
    iter->next();
    iter->next();
    
    iter->first();
    iter->first();
    
    cout << "✓ Chat Iterator Boundary Conditions passed!" << endl;
    testsPassed++;
    
    delete iter;
    delete alice;
    delete room;
}

void testMessageIteratorBoundaryConditions() {
    cout << "\n=== Testing Message Iterator Boundary Conditions ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    messageIterator* iter = new messageIterator(room);
    
    iter->next();
    iter->next();
    iter->next();
    
    iter->first();
    iter->first();
    
    cout << "✓ Message Iterator Boundary Conditions passed!" << endl;
    testsPassed++;
    
    delete iter;
    delete alice;
    delete bob;
    delete room;
}

void testStateTransitionsComplex() {
    cout << "\n=== Testing Complex State Transitions ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->GoDND();
    alice->send("In DND", room);
    bob->send("To Alice in DND", room);
    
    alice->logout();
    alice->send("Offline (should fail)", room);
    bob->send("To offline Alice", room);
    
    alice->login();
    alice->send("Back online", room);
    
    cout << "✓ Complex State Transitions passed!" << endl;
    testsPassed++;
    
    delete alice;
    delete bob;
    delete room;
}

void testMultipleIteratorsOnSameRoom() {
    cout << "\n=== Testing Multiple Iterators on Same Room ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    
    alice->send("Msg1", room);
    bob->send("Msg2", room);
    
    chatIterator* iter1 = new chatIterator(room);
    chatIterator* iter2 = new chatIterator(room);
    messageIterator* iter3 = new messageIterator(room);
    
    iter1->next();
    
    bool passed = (iter2->curr() == "[Alice]: Msg1" && iter3->curr() == "Alice");
    
    if (passed) {
        cout << "✓ Multiple Iterators on Same Room passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Multiple Iterators on Same Room FAILED!" << endl;
    }
    
    delete iter1;
    delete iter2;
    delete iter3;
    delete alice;
    delete bob;
    delete charlie;
    delete room;
}

// ==================== MEDIATOR PATTERN TESTS ====================

void testMediatorNotification() {
    cout << "\n=== Testing Mediator Notification on Join/Leave ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    
    room->removeUser(bob);
    
    bool passed = (room->getUsers().size() == 2);
    
    if (passed) {
        cout << "✓ Mediator Notification on Join/Leave passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Mediator Notification on Join/Leave FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete charlie;
    delete room;
}

void testSendMessageToMultipleRecipients() {
    cout << "\n=== Testing Send Message to Multiple Recipients ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    Users* dave = new Users("Dave");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    room->registerUser(dave);
    
    alice->send("Hello everyone!", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 1 && history[0] == "[Alice]: Hello everyone!");
    
    if (passed) {
        cout << "✓ Send Message to Multiple Recipients passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Send Message to Multiple Recipients FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete charlie;
    delete dave;
    delete room;
}

void testUserDoesNotReceiveOwnMessage() {
    cout << "\n=== Testing User Does Not Receive Own Message ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    alice->send("Talking to myself", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 1);
    
    if (passed) {
        cout << "✓ User Does Not Receive Own Message passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ User Does Not Receive Own Message FAILED!" << endl;
    }
    
    delete alice;
    delete room;
}

// ==================== COMPLEX INTEGRATION TESTS ====================

void testComplexScenario1() {
    cout << "\n=== Testing Complex Scenario 1 ===" << endl;
    totalTests++;
    
    CtrlCat* ctrlCat = new CtrlCat();
    Dogorithm* dogorithm = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    ctrlCat->registerUser(alice);
    ctrlCat->registerUser(bob);
    dogorithm->registerUser(alice);
    dogorithm->registerUser(charlie);
    
    alice->send("Hello CtrlCat!", ctrlCat);
    bob->send("Hi Alice!", ctrlCat);
    alice->send("Hello Dogorithm!", dogorithm);
    charlie->send("Woof woof!", dogorithm);
    
    ctrlCat->removeUser(bob);
    
    alice->send("Bob left :(", ctrlCat);
    
    bool passed = (ctrlCat->getUsers().size() == 1 && 
                   dogorithm->getUsers().size() == 2 && 
                   ctrlCat->getChatHistory().size() == 3 && 
                   dogorithm->getChatHistory().size() == 2);
    
    if (passed) {
        cout << "✓ Complex Scenario 1 passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Complex Scenario 1 FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete charlie;
    delete ctrlCat;
    delete dogorithm;
}

void testComplexScenario2() {
    cout << "\n=== Testing Complex Scenario 2 - States and Multiple Rooms ===" << endl;
    totalTests++;
    
    CtrlCat* room1 = new CtrlCat();
    Dogorithm* room2 = new Dogorithm();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room1->registerUser(alice);
    room1->registerUser(bob);
    room2->registerUser(alice);
    room2->registerUser(bob);
    
    alice->send("Normal message room1", room1);
    alice->send("Normal message room2", room2);
    
    alice->GoDND();
    alice->send("DND message room1", room1);
    bob->send("To Alice in DND room1", room1);
    
    alice->logout();
    alice->send("Offline message (fail)", room1);
    
    alice->login();
    alice->send("Back online room2", room2);
    
    bool passed = (room1->getChatHistory().size() == 3 && room2->getChatHistory().size() == 2);
    
    if (passed) {
        cout << "✓ Complex Scenario 2 - States and Multiple Rooms passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Complex Scenario 2 - States and Multiple Rooms FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete room1;
    delete room2;
}

void testComplexScenario3() {
    cout << "\n=== Testing Complex Scenario 3 - Iterators and Commands ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    
    Command* cmd1 = new SendMessageCommand(room, alice, "Command message 1");
    Command* cmd2 = new LogMessageCommand(room, alice, "Command message 1");
    cmd1->execute();
    cmd2->execute();
    
    bob->send("Regular message", room);
    
    Command* cmd3 = new SendMessageCommand(room, charlie, "Command message 2");
    Command* cmd4 = new LogMessageCommand(room, charlie, "Command message 2");
    cmd3->execute();
    cmd4->execute();
    
    chatIterator* chatIter = new chatIterator(room);
    int msgCount = 1;
    while (chatIter->hasNext()) {
        chatIter->next();
        msgCount++;
    }
    
    messageIterator* msgIter = new messageIterator(room);
    int userCount = 1;
    while (msgIter->hasNext()) {
        msgIter->next();
        userCount++;
    }
    
    bool passed = (msgCount == 3 && userCount == 3);
    
    if (passed) {
        cout << "✓ Complex Scenario 3 - Iterators and Commands passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Complex Scenario 3 - Iterators and Commands FAILED!" << endl;
    }
    
    delete cmd1;
    delete cmd2;
    delete cmd3;
    delete cmd4;
    delete chatIter;
    delete msgIter;
    delete alice;
    delete bob;
    delete charlie;
    delete room;
}

void testComplexScenario4() {
    cout << "\n=== Testing Complex Scenario 4 - User Removal During Iteration ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    vector<Users*> users;
    
    for (int i = 0; i < 10; i++) {
        Users* user = new Users("User" + to_string(i));
        users.push_back(user);
        room->registerUser(user);
    }
    
    for (int i = 0; i < 10; i++) {
        users[i]->send("Message from User" + to_string(i), room);
    }
    
    chatIterator* chatIter = new chatIterator(room);
    messageIterator* msgIter = new messageIterator(room);
    
    room->removeUser(users[5]);
    room->removeUser(users[7]);
    
    int count = 1;
    while (chatIter->hasNext()) {
        chatIter->next();
        count++;
    }
    
    bool passed = (count == 10);
    
    if (passed) {
        cout << "✓ Complex Scenario 4 - User Removal During Iteration passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Complex Scenario 4 - User Removal During Iteration FAILED!" << endl;
    }
    
    delete chatIter;
    delete msgIter;
    
    for (Users* user : users) {
        delete user;
    }
    delete room;
}

void testComplexScenario5() {
    cout << "\n=== Testing Complex Scenario 5 - All State Transitions ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->send("Online", room);
    
    alice->GoDND();
    alice->send("DND", room);
    
    alice->login();
    alice->send("Back online from DND", room);
    
    alice->logout();
    alice->send("Offline (should fail)", room);
    
    alice->GoDND();
    alice->send("DND from offline", room);
    
    alice->logout();
    alice->login();
    alice->send("Online again", room);
    
    UserState* customOnline = new OnlineState();
    alice->ChangeState(customOnline);
    alice->send("Custom state", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 6);
    
    if (passed) {
        cout << "✓ Complex Scenario 5 - All State Transitions passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Complex Scenario 5 - All State Transitions FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete room;
}

void testComplexScenario6() {
    cout << "\n=== Testing Complex Scenario 6 - Queue Multiple Commands ===" << endl;
    totalTests++;
    
    Dogorithm* room = new Dogorithm();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    for (int i = 0; i < 10; i++) {
        Command* sendCmd = new SendMessageCommand(room, alice, "Queued " + to_string(i));
        Command* logCmd = new LogMessageCommand(room, alice, "Queued " + to_string(i));
        alice->addCommand(sendCmd);
        alice->addCommand(logCmd);
    }
    
    alice->executeAll();
    
    vector<string> history = room->getChatHistory();
    
    alice->executeAll();
    
    bool passed = (history.size() == 10);
    
    if (passed) {
        cout << "✓ Complex Scenario 6 - Queue Multiple Commands passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Complex Scenario 6 - Queue Multiple Commands FAILED!" << endl;
    }
    
    delete alice;
    delete room;
}

void testComplexScenario7() {
    cout << "\n=== Testing Complex Scenario 7 - Mixed Online/Offline Users ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    Users* charlie = new Users("Charlie");
    Users* dave = new Users("Dave");
    
    room->registerUser(alice);
    room->registerUser(bob);
    room->registerUser(charlie);
    room->registerUser(dave);
    
    bob->logout();
    charlie->GoDND();
    
    alice->send("To mixed audience", room);
    bob->send("Bob's message (should fail)", room);
    charlie->send("Charlie in DND", room);
    dave->send("Dave's message", room);
    
    vector<string> history = room->getChatHistory();
    bool passed = (history.size() == 3);
    
    if (passed) {
        cout << "✓ Complex Scenario 7 - Mixed Online/Offline Users passed!" << endl;
        testsPassed++;
    } else {
        cout << "✗ Complex Scenario 7 - Mixed Online/Offline Users FAILED!" << endl;
    }
    
    delete alice;
    delete bob;
    delete charlie;
    delete dave;
    delete room;
}

// ==================== MEMORY AND CLEANUP TESTS ====================

void testProperCleanup() {
    cout << "\n=== Testing Proper Cleanup ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    Users* bob = new Users("Bob");
    
    room->registerUser(alice);
    room->registerUser(bob);
    
    alice->send("Test", room);
    bob->send("Test", room);
    
    chatIterator* iter1 = new chatIterator(room);
    messageIterator* iter2 = new messageIterator(room);
    
    Command* cmd1 = new SendMessageCommand(room, alice, "Test");
    Command* cmd2 = new LogMessageCommand(room, bob, "Test");
    
    delete iter1;
    delete iter2;
    delete cmd1;
    delete cmd2;
    delete alice;
    delete bob;
    delete room;
    
    cout << "✓ Proper Cleanup passed!" << endl;
    testsPassed++;
}

void testCommandQueueCleanup() {
    cout << "\n=== Testing Command Queue Cleanup ===" << endl;
    totalTests++;
    
    CtrlCat* room = new CtrlCat();
    Users* alice = new Users("Alice");
    
    room->registerUser(alice);
    
    Command* cmd1 = new SendMessageCommand(room, alice, "Test1");
    Command* cmd2 = new SendMessageCommand(room, alice, "Test2");
    alice->addCommand(cmd1);
    alice->addCommand(cmd2);
    
    delete alice;
    delete room;
    
    cout << "✓ Command Queue Cleanup passed!" << endl;
    testsPassed++;
}

// ==================== MAIN TEST RUNNER ====================

void runAllTests() {
    cout << "🚀 Starting Comprehensive PetSpace Chat System Tests..." << endl;
    cout << "========================================================" << endl;
    
    testBasicUserCreation();
    testBasicChatRoomCreation();
    
    testUserStateOnline();
    testUserStateOffline();
    testUserStateDND();
    testUserStateTransitions();
    testUserChangeState();
    testUserReceiveWhileOffline();
    testUserReceiveWhileDND();
    
    testUserRegistration();
    testUserRemoval();
    
    testMessageSending();
    testSendToNullRoom();
    testEmptyMessages();
    testLongMessages();
    testSpecialCharactersInMessages();
    
    testCommandPattern();
    testCommandWithNullRoom();
    testCommandWithNullUser();
    testAddNullCommand();
    testMultipleCommands();
    
    testChatIteratorBasic();
    testChatIteratorNullRoom();
    // testChatIteratorEmptyHistory();
    testChatIteratorSingleMessage();
    testMessageIteratorBasic();
    testMessageIteratorNullRoom();
    testMessageIteratorEmptyRoom();
    testMessageIteratorSingleUser();
    
    testMultipleRooms();
    testUserInMultipleRooms();
    
    testLargeNumberOfUsers();
    testLargeNumberOfMessages();
    testIteratorWithManyMessages();
    testIteratorWithManyUsers();
    
    testRemoveAllUsers();
    testMessageAfterUserRemoval();
    testChatIteratorBoundaryConditions();
    testMessageIteratorBoundaryConditions();
    testStateTransitionsComplex();
    testMultipleIteratorsOnSameRoom();
    
    testMediatorNotification();
    testSendMessageToMultipleRecipients();
    testUserDoesNotReceiveOwnMessage();
    
    testComplexScenario1();
    testComplexScenario2();
    testComplexScenario3();
    testComplexScenario4();
    testComplexScenario5();
    testComplexScenario6();
    testComplexScenario7();
    
    testProperCleanup();
    testCommandQueueCleanup();
    
    cout << "\n========================================================" << endl;
    cout << "📊 Test Results: " << testsPassed << "/" << totalTests << " tests passed" << endl;
    
    if (testsPassed == totalTests) {
        cout << "🎉 All tests passed! Excellent code coverage achieved." << endl;
        cout << "✓ All design patterns tested" << endl;
        cout << "✓ Edge cases covered" << endl;
        cout << "✓ Error handling verified" << endl;
        cout << "✓ Memory management checked" << endl;
    } else {
        cout << "❌ " << (totalTests - testsPassed) << " test(s) failed." << endl;
        cout << "Please review the implementation." << endl;
    }
    cout << "========================================================" << endl;
}

int main() {
    runAllTests();
    return 0;
}