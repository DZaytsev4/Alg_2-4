#include "../priority_queue/priority_queue.h";
#include <iostream>
#include <locale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    Priority_queue<int> pr_q;
    while (true) {
        cout << "Что вы хотите сделать?\n";
        cout << "1 - добавить элемент в очередь\n";
        cout << "2 - посмотреть элемент из вершины\n";
        cout << "3 - проверить на пустоту\n";
        cout << "4 - посмотреть всю очередь\n";
        cout << "5 - извлечь элемент\n";
        cout << "6 - выйти из программы\n";
        int act, x, p;
        cin >> act;
        switch (act) {
        case 1:
            cout << "Введите элемент и его приоритет\n";
            cin >> x >> p;
            pr_q.insert(x, p);
            break;
        case 2:
            cout << "Элемент: " << pr_q.getMax().item << " Приоритет: "<< pr_q.getMax().prio<< endl;
            break;
        case 3:
            if (pr_q.isEmpty()) cout << "Очередь пуста\n";
            else cout << "В очереди есть элементы\n";
            break;
        case 4:
            cout << pr_q;
            break;
        case 5:
            cout << "Вы извлекли элемент: " << pr_q.pop().item << endl;
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
    }
}
