#include "sll.h"
#include <iostream>


LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
    std::cout << "sll created successfully" << std::endl;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    std::cout << "sll destroyed successfully" << std::endl;
}

// Returns the value of the ith node (0-indexed), -1 if index out of bounds
int LinkedList::get(int index) {
    int output = -1;
    if (index < 0 || index >= size) {
        std::cerr << "Error: index out of bounds" << std::endl;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        output = temp->value;
    }
    return output;
}

// Insert node with value = val at the head of the list
void LinkedList::insertHead(int val) {
    Node* new_head = new Node();
    new_head->value = val;
    new_head->next = head;
    head = new_head;

    // Update tail if list was empty
    if (tail == nullptr) {
        tail = head;
    }
    size++;
}

// Insert node with value = val at the tail of the list
void LinkedList::insertTail(int val) {
    Node *new_tail = new Node();
    new_tail->value = val;
    if (head == nullptr) {
        head = new_tail;
    }
    else {
        tail->next = new_tail;
    }
    tail = new_tail;
    size++;
}

// Removes the ith node (0-indexed)
// Returns true if index is valid and removed, false otherwise
bool LinkedList::remove(int index) {
    bool output = true;
    if (index < 0 || index >= size) {
        output = false;
        std::cerr << "Error: index out of bounds" << std::endl;
    }
    else if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Node* prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        if (temp->next == nullptr) {
            tail = prev;
        }
    }
    size--;
    return output;
}

// Return the vales in the linked list as a vector of the elements
std::vector<int> LinkedList::getValues() {
    std::vector<int> output;
    Node* temp = head;
    while (temp != nullptr) {
        output.push_back(temp->value);
        temp = temp->next;
    }
    return output;
}