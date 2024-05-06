#include "../priority_queue/priority_queue.h";
#include <iostream>
#include <locale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    Priority_queue<int> pr_q;
    while (true) {
        cout << "��� �� ������ �������?\n";
        cout << "1 - �������� ������� � �������\n";
        cout << "2 - ���������� ������� �� �������\n";
        cout << "3 - ��������� �� �������\n";
        cout << "4 - ���������� ��� �������\n";
        cout << "5 - ������� �������\n";
        cout << "6 - ����� �� ���������\n";
        int act, x, p;
        cin >> act;
        switch (act) {
        case 1:
            cout << "������� ������� � ��� ���������\n";
            cin >> x >> p;
            pr_q.insert(x, p);
            break;
        case 2:
            cout << "�������: " << pr_q.getMax().item << " ���������: "<< pr_q.getMax().prio<< endl;
            break;
        case 3:
            if (pr_q.isEmpty()) cout << "������� �����\n";
            else cout << "� ������� ���� ��������\n";
            break;
        case 4:
            cout << pr_q;
            break;
        case 5:
            cout << "�� �������� �������: " << pr_q.pop().item << endl;
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "�������� ����" << endl;
            break;
        }
    }
}
