#include "..//skip_list/skip_list.h"
#include <iostream>
int main() {
    SkipList<int> skipList;
    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(9);
    skipList.insert(2);

    std::cout << "Is the skip list empty? " << (skipList.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Searching for 6: " << (skipList.search(6) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for 5: " << (skipList.search(5) ? "Found" : "Not found") << std::endl;

    skipList.remove(6);
    std::cout << "Searching for 6 after removal: " << (skipList.search(6) ? "Found" : "Not found") << std::endl;
    std::cout << skipList;
    skipList.clear();
    std::cout << "Is the skip list empty after clearing? " << (skipList.isEmpty() ? "Yes" : "No") << std::endl;
    return 0;
}