// 2_1_lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    setlocale(LC_CTYPE, "rus");
    std::cout << "Введите первое число: ";
    float a;
    std::cin >> a;
    std::cout << "Введите второе число: ";
    float b;
    std::cin >> b;
    float c = (a + b) / 2;
    std::cout << "Среднее арифметическое этих чисел = " << c << "\n\n";

    std::cout << "Введите любой из четырех знаков операции (+, -, * или /): ";
    char d;
    std::cin >> d;

    /*if (d == '+') {
        c = a + b;
    }
    else if (d == '-') {
        c = a - b;
    }
    else if (d == '*') {
        c = a * b;
    }
    else {
        c = a / b;
    }*/

    switch (d)
    {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        case '*':
            c = a * b;
            break;
        default:
            c = a / b;
    }

    std::cout << a << ' ' << d << ' ' << b << " = " << c;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
