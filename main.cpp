#include <iostream>
#include <cmath>
#include <locale>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    system("chcp 1251");
    int choose;
    vector<int> lengths(4);
    enum main {
        trapezoid = 1,
        triangle,
    };
    cout << "Введите фигуру, которую хотите рассчитать: \n Трапеция - 1 \n Треугольник - 2 \n ";
    cin >> choose;
    switch (choose) {
    case main::trapezoid: {
        cout << "Введите длины сторон трапеции" << endl;
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

        cout << "Периметр трапеции равен " << Perimetr << endl;
        cout << "Площадь трапеции равна " << square << endl;
        cout << "Длина средней линии трапеции равна " << lenMidLine;
        break;
    }
    case triangle: {
        double a, b, c;
        cout << "Введите длины сторон треугольника: ";
        cin >> a >> b >> c;
        // существует ли треугольник
        if (a + b > c and a + c > b and b + c > a) {  // Заменил && на and
            // периметр
            double perimeter = a + b + c;
            cout << "Периметр: " << perimeter << endl;
            // площадь по формуле герона
            double s = perimeter / 2; // Полупериметр
            double area = sqrt(s * (s - a) * (s - b) * (s - c));
            cout << "Площадь: " << area << endl;
            // проверка на равнобедренность
            if (a == b or a == c or b == c) {  // Заменил || на or
                cout << "Треугольник равнобедренный" << endl;
            }
            else {
                cout << "Треугольник не равнобедренный" << endl;
            }
        }
        else {
            cout << "Треугольник с такими сторонами не существует!" << endl;
        }
        break;
    }
    };
    return 0;
}