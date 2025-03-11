#include <iostream>
#include <cmath>
#include <locale>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int choose;
    vector<int> lengths(4);
    enum main {
        trapezoid = 1,
        triangle,
    };
    cout << "������� ������, ������� ������ ����������: \n �������� - 1 \n ����������� - 2 \n ";
    cin >> choose;
    switch (choose) {
    case main::trapezoid: {
        cout << "������� ����� ������ ��������" << endl;
        for (int i = 0; i < 4; i++) {
            cin >> lengths[i];
        }
        sort(begin(lengths), end(lengths));
        int a = lengths[3];
        int b = lengths[2];
        int c = lengths[1];
        int d = lengths[0];
        double height = sqrt(pow(c, 2) - ((pow(a - b, 2) + pow(c, 2) - pow(d, 2) / pow(2 * (a - b), 2))));
        int Perimetr = a + b + c + d;
        double lenMidLine = (a + b) / 2;
        double square = lenMidLine * height;

        cout << "�������� �������� ����� " << Perimetr << endl;
        cout << "������� �������� ����� " << square << endl;
        cout << "����� ������� ����� �������� ����� " << lenMidLine;
        break;
    }
    case triangle: {
        double a, b, c;
        cout << "������� ����� ������ ������������: ";
        cin >> a >> b >> c;
        // ���������� �� �����������
        if (a + b > c and a + c > b and b + c > a) {  // ������� && �� and
            // ��������
            double perimeter = a + b + c;
            cout << "��������: " << perimeter << endl;
            // ������� �� ������� ������
            double s = perimeter / 2; // ������������
            double area = sqrt(s * (s - a) * (s - b) * (s - c));
            cout << "�������: " << area << endl;
            // �������� �� ����������������
            if (a == b or a == c or b == c) {  // ������� || �� or
                cout << "����������� ��������������" << endl;
            }
            else {
                cout << "����������� �� ��������������" << endl;
            }
        }
        else {
            cout << "����������� � ������ ��������� �� ����������!" << endl;
        }
        break;
    }
    };
    return 0;
}