#include "..//skip_list/skip_list.h"
#include <iostream>
#include <locale>
using namespace std;
int main() {
    SkipList<int> skipList;
    setlocale(LC_ALL,"Russian");
    while (true) {
        cout << "Что вы хотите сделать?" << endl;
        cout << "1 - добавить элемент в список" << endl;
        cout << "2 - проверить есть ли элемент в списке?" << endl;
        cout << "3 - вывести все элементы из списка" << endl;
        cout << "4 - удалить элемент" << endl;
        cout << "5 - очистить таблицу" << endl;
        cout << "6 - закрыть программу " << endl;
        int act,x;
        cin >> act;
        switch (act) {
        case 1:
            cout << "Введите элемент: " ;
            cin >> x;
            skipList.insert(x);
            break;
        case 2:
            cout << "Какой элемент вы хотите проверить?" << endl;
            cin >> x;
            if (skipList.search(x) == true) cout << "Данный элемент присутствует\n";
            else cout << "Данный элемент отсутсвует \n";
            break;
        case 3:
            cout << skipList << endl;
            break;
        case 4:
            cout << "Какой элемент вы хотите удалить?\n";
            cin >> x;
            skipList.remove(x);
            break;
        case 5:
            skipList.clear();
            break;
        case 6:
            return 0;
        default:
            cout << "Неверный ввод" << endl;
            break;
        }
        
    }
}