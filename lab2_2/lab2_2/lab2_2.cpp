#include <iostream>

int main()
{
    setlocale(LC_CTYPE, "rus");
    int a = -1;
    while (a < 1) {
        std::cout << "Введите ПОЛОЖИТЕЛЬНОЕ (больше нуля) целое натуральное число: ";
        std::cin >> a;
    }

    int c = 0;
    for (int i = 0; i <= a; i++) {
        c += i;
    }

    int numbers[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << "Сумма: " << c << "\n";


    for (int i = 0; i < 10; i++) {
        std::cout << numbers[i];
        std::cout << " ";
    }
    std::cout << "\n";

    int numbers2[5]{ 0, 2, 4, 6, 8 };

    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            std::cout << numbers2[i] << " ";
        }
    }
    std::cout << "\n";

    int numbers3[5]{ 1, 3, 5, 7, 9 };

    int g = 0;
    for (int i = 0; i < 5; i++) {
        if (i % 2 != 0) {
            g += numbers3[i];
        }
    }

    std::cout << "Сумма элементов массива, стоящих на нечетных позициях: " << g;
}