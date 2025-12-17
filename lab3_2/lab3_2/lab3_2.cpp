#include <iostream>


// 1. Функция, возвращающая сумму всех элементов массива
int sumArray(int* start, int* end) {
    int sum = 0;
    while (start != end) {
        sum += *start;
        start++;
    }
    return sum;
}

// 3. Функции суммы и разности
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// 4-5. Функция, возвращающая указатель на функцию в зависимости от char
int (*getOperation(char op))(int, int) {
    if (op == '+') {
        return &add;
    }
    else if (op == '-') {
        return &subtract;
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    // ===== Часть 1-2: Работа с массивом =====
    std::cout << "=== Часть 1-2: Сумма элементов массива ===" << '\n';

    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Передаем указатели на начало и конец массива
    int total = sumArray(arr, arr + size);
    std::cout << "Сумма элементов массива: " << total << '\n';
    std::cout << '\n';

    // ===== Часть 3-6: Работа с указателями на функции =====
    std::cout << "=== Часть 3-6: Указатели на функции ===" << '\n';

    // Тестируем сумму
    int (*operationPtr)(int, int) = getOperation('+');
    if (operationPtr != nullptr) {
        int result = operationPtr(10, 5);
        std::cout << "10 + 5 = " << result << std::endl;
    }

    // Тестируем разность
    operationPtr = getOperation('-');
    if (operationPtr != nullptr) {
        int result = operationPtr(10, 5);
        std::cout << "10 - 5 = " << result << std::endl;
    }
    std::cout << std::endl;

    // ===== Часть 7-8: Динамический указатель float =====
    std::cout << "=== Часть 7-8: Динамический указатель ===" << '\n';

    // 7. Создаем динамический указатель типа float
    float* dynamicFloat = new float(3.14);

    // Выводим значение в консоль
    std::cout << "Значение динамического указателя: " << *dynamicFloat << '\n';
    std::cout << "Адрес указателя: " << dynamicFloat << std::endl;

    // 8. Удаляем из памяти
    delete dynamicFloat;

    std::cout << "Память освобождена." << '\n';

    return 0;
}