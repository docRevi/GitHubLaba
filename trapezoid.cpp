#include <iostream>
#include <cmath>
#include <locale>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  setlocale(LC_ALL, "");
  int choose;
  enum main {
    trapezoid = 1,
  };
  cout << "Выберите фигуру которую хотите рассчитать: \n Трапеция - 1" << endl;
  cin >> choose;
  switch (choose) {
  case main::trapezoid:
    vector<int> lengths(4);
    cout << "Введите длины сторон трапеции" << endl;
    for (int i = 0; i < 4; i++) {
      cin >> lengths[i];
    }
    sort(begin(lengths), end(lengths));
    int a = lengths[3];
    int b = lengths[2];
    int c = lengths[1];
    int d = lengths[0];
    double height = sqrt(c ^ 2 - (((a - b) ^ 2 + c ^ 2 - d ^ 2) / (2 * (a - b)) ^ 2));
    int perimetr = a + b + c + d;
    double lenMidLine = (a + b) / 2;
    double square = lenMidLine * height;

    cout << "Периметр трапеции равен " << perimetr << endl;
    cout << "Площадь трапеции равна " << square << endl;
    cout << "Длина средней линии трапеции равна " << lenMidLine;
    break;
  };

}
