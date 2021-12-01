#include <iostream>
using namespace std;

void checkValidInput() {
    if (cin.fail()) {
        cout << endl;
        throw "Ошибка.";
        cout << endl;
    }
}

void checkValidParams(float a, float b, float n, float h) {
    if (a > b) {
        throw "a не может быть больше b.";
        cout << endl;
    }
    if (n <= 2) {
        throw "Ошибка, n не может быть меньше 2.";
        cout << endl;
    }

    if (h <= 0) {
        throw "Ошибка, шаг не может быть отрицательным или равным нулю.";
        cout << endl;
    }
}

int calculate(float a, float b, float n, float h, float x = 1, float y = 0, float z = 1) {
    x = a;

    for (; b >= a; b -= h) {
        if (x < 0) {
            for (int i = 0; i <= n; i++) {

                for (int j = i; j <= n - 1; j++) {
                    z *= (i - j);
                }
                y += z;
            }
        }
        else {
            for (int i = 1; i <= n - 2; i++) {
                y += (i - x) * (i - x);
            }
        }

        cout << "x = " << x << ';' << "\t";
        cout << "y = " << y << endl;
        x += h;
        y = 0; z = 1;
    }
    return x, y;
}

int main()
{
    setlocale(LC_ALL, "russian");
again:
    float x;
    float a, b, h, n;
    float y = 0, z = 1;
    bool cycle = true;
    while (cycle)
    {

        try
        {
            cout << "Введите a: ";
            cin >> a;
            checkValidInput();
            cout << "Введите b: ";
            cin >> b;
            checkValidInput();
            cout << "Введите h: ";
            cin >> h;
            checkValidInput();
            cout << "Введите n: ";
            cin >> n;
            checkValidInput();

            checkValidParams(a, b, n, h);
            calculate(a, b, n, h);
            cycle = false;
        }
        catch (const char* ex)
        {
            cout << ex << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto again;
        }
        cout << endl;

    }
    return 0;
}
