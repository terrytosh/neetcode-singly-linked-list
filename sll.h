#ifndef SLL_H
#define SLL_H

#include <vector>

struct Node {
    int value;
    Node* next;
};

class LinkedList {

private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();
    int get(int index);
    void insertHead(int val);
    void insertTail(int val);
    bool remove(int index);
    std::vector<int> getValues();
};

#endif /* SLL_H */