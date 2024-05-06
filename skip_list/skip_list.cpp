#include "..//skip_list/skip_list.h"
#include <iostream>
#include <locale>
using namespace std;
int main() {
    SkipList<int> skipList;
    setlocale(LC_ALL,"Russian");
    while (true) {
        cout << "��� �� ������ �������?" << endl;
        cout << "1 - �������� ������� � ������" << endl;
        cout << "2 - ��������� ���� �� ������� � ������?" << endl;
        cout << "3 - ������� ��� �������� �� ������" << endl;
        cout << "4 - ������� �������" << endl;
        cout << "5 - �������� �������" << endl;
        cout << "6 - ������� ��������� " << endl;
        int act,x;
        cin >> act;
        switch (act) {
        case 1:
            cout << "������� �������: " ;
            cin >> x;
            skipList.insert(x);
            break;
        case 2:
            cout << "����� ������� �� ������ ���������?" << endl;
            cin >> x;
            if (skipList.search(x) == true) cout << "������ ������� ������������\n";
            else cout << "������ ������� ���������� \n";
            break;
        case 3:
            cout << skipList << endl;
            break;
        case 4:
            cout << "����� ������� �� ������ �������?\n";
            cin >> x;
            skipList.remove(x);
            break;
        case 5:
            skipList.clear();
            break;
        case 6:
            return 0;
        default:
            cout << "�������� ����" << endl;
            break;
        }
        
    }
}