#include <iostream>
using namespace std;

template<typename T>
class Priority_queue {
    struct item {
        T item;
        int prio;
    };
    static const int MAX_SIZE = 1000;
    item mas[MAX_SIZE];
    int size = -1;

public:
    Priority_queue() : mas{}, size(-1) {}
    
    void insert(const T& elem, int pr) {
        size++;
        mas[size].item = elem;
        mas[size].prio = pr;
        int current = size;
        while (current > 0 && mas[current].prio <= mas[(current - 1)].prio) {
            swap(mas[current], mas[(current - 1)]);
            current--;
        }
    }
    bool isEmpty() {
        return size < 0;
    }
    item pop() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        size--;
        return mas[size + 1];
    }
    item getMax() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return mas[size];
    }
    friend ostream& operator<<(ostream& os, const Priority_queue& queue) {
        for (int i = 0; i <= queue.size; ++i) {
            os << "Element: " << queue.mas[i].item << ", Priority: " << queue.mas[i].prio << endl;
        }
        return os;
    }
};
