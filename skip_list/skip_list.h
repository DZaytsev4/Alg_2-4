#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
class SkipList {
private:
    struct Node {
        T data;
        Node** next;
        Node(const T& val, int level) : data(val) {
            next = new Node * [level];
            for (int i = 0; i < level; ++i) {
                next[i] = nullptr;
            }
        }
        ~Node() {
            delete[] next;
        }
    };

    Node* head;
    int maxLevel;
    int currentLevel;

    int randomLevel() {
        int level = 1;
        while (rand() % 2 == 0 && level < maxLevel) {
            level++;
        }
        return level;
    }

public:
    SkipList(int maxLevels = 5) : maxLevel(maxLevels), currentLevel(1) {
        head = new Node(T(), maxLevel);
    }

    ~SkipList() {
        Node* temp;
        while (head) {
            temp = head->next[0];
            delete head;
            head = temp;
        }
    }

    void insert(const T& val) {
        int level = randomLevel();
        Node* newNode = new Node(val, level);

        Node* current = head;
        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->next[i] != nullptr && current->next[i]->data < val) {
                current = current->next[i];
            }
            if (i < level) {
                newNode->next[i] = current->next[i];
                current->next[i] = newNode;
            }
        }

        if (level > currentLevel) {
            currentLevel = level;
        }
    }

    bool search(const T& val) {
        Node* current = head;
        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->next[i] != nullptr && current->next[i]->data < val) {
                current = current->next[i];
            }
        }
        return (current->next[0] != nullptr && current->next[0]->data == val);
    }

    void remove(const T& val) {
        Node* current = head;
        Node** update = new Node * [maxLevel];
        for (int i = currentLevel - 1; i >= 0; i--) {
            while (current->next[i] != nullptr && current->next[i]->data < val) {
                current = current->next[i];
            }
            update[i] = current;
        }

        current = current->next[0];
        if (current != nullptr && current->data == val) {
            for (int i = 0; i < currentLevel; i++) {
                if (update[i]->next[i] != current) {
                    break;
                }
                update[i]->next[i] = current->next[i];
            }
            delete current;

            while (currentLevel > 1 && head->next[currentLevel - 1] == nullptr) {
                currentLevel--;
            }
        }

        delete[] update;
    }

    bool isEmpty() const {
        return (head->next[0] == nullptr);
    }

    void clear() {
        Node* temp;
        while (head->next[0]) {
            temp = head->next[0];
            head->next[0] = temp->next[0];
            delete temp;
        }
        currentLevel = 1;
    }
    friend ostream& operator<<(ostream& os, const SkipList& list) {
        typename SkipList<T>::Node* current = list.head->next[0];
        for (int i = list.currentLevel - 1; i >= 0; --i) {
            os << "Уровень " << i + 1 << ": ";
            typename SkipList<T>::Node* levelCurrent = list.head->next[i];
            while (levelCurrent) {
                os << levelCurrent->data << " ";
                levelCurrent = levelCurrent->next[i];
            }
            os << endl;
        }
        return os;
    }
};
