#include "sll.h"
#include <iostream>

int main() {
    LinkedList sll;
    sll.insertHead(1);
    sll.insertHead(2);
    sll.insertTail(3);  // 5 2 1 3 4
    sll.insertTail(4);
    sll.insertHead(5);
    std::cout << sll.get(0) << std::endl;
    std::cout << sll.get(2) << std::endl;
    std::cout << sll.get(4) << std::endl;
    std::cout << sll.remove(2) << std::endl;
    std::cout << sll.remove(0) << std::endl;
    sll.insertHead(6);
    sll.insertTail(7);
    std::vector<int> vals = sll.getValues();
    std::cout << "Vals: ";
    for (int i = 0; i < vals.size(); i++) {
        std::cout << vals[i] << " ";
    }
    std::cout << std::endl;
    std::cout << sll.get(5) << std::endl;
    return 0;
}