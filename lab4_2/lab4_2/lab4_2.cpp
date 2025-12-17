#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
    string name;
    float damage;
    float weight;

    // Конструктор с 3 параметрами
    Weapon(string name, float damage, float weight) {
        this->name = name;
        this->damage = damage;
        this->weight = weight;
    }

    // Конструктор без параметров, вызывающий предыдущий
    Weapon() : Weapon("Default Sword", 0.5, 7.3) {}

    // ДЕСТРУКТОР (задание 1)
    ~Weapon() {
        cout << "Оружие \"" << name << "\" удаляется. ";
        cout << "Характеристики: урон=" << damage << ", вес=" << weight << "\n";
    }

    // Метод проверки веса (задание 5)
    bool isTooHeavy(float maxWeight) {
        return weight > maxWeight;
    }

    // Метод для суммы веса двух оружий (задание 6)
    float totalWeight(Weapon& otherWeapon) {
        return weight + otherWeapon.weight;
    }

    // Перегрузка метода totalWeight (задание 7)
    float totalWeight(float additionalWeight) {
        return weight + additionalWeight;
    }

    // Переписанный метод с использованием перегрузки (задание 8)
    float totalWeightNew(Weapon& otherWeapon) {
        return totalWeight(otherWeapon.weight);  // Используем перегрузку
    }

    // Метод для вывода информации
    void show() {
        cout << "Название: " << name << ", Урон: " << damage << ", Вес: " << weight << "\n";
    }
};

int main() {
    setlocale(LC_CTYPE, "rus");
    cout << "=== Задание 2: Создание обычного объекта ===" << "\n";
    Weapon sword("Меч", 15.0f, 8.0f);
    sword.show();
    cout << "\n";

    cout << "=== Задание 3: Создание динамического объекта ===" << "\n";
    Weapon* axe = new Weapon("Топор", 20.0f, 12.0f);
    axe->show();
    cout << "\n";

    cout << "=== Задание 5: Проверка веса ===" << "\n";
    cout << "Может ли персонаж с силой 10 поднять меч (вес 8)? ";
    if (sword.isTooHeavy(10.0f)) {
        cout << "Нет, слишком тяжело!" << "\n";
    }
    else {
        cout << "Да, может!" << "\n";
    }

    cout << "Может ли персонаж с силой 5 поднять топор (вес 12)? ";
    if (axe->isTooHeavy(5.0f)) {
        cout << "Нет, слишком тяжело!" << "\n";
    }
    else {
        cout << "Да, может!" << "\n";
    }
    cout << "\n";

    cout << "=== Задание 6-7-8: Суммирование весов ===" << "\n";
    Weapon bow("Лук", 8.0f, 3.0f);

    // Сумма весов двух оружий (метод из задания 6)
    float sum1 = sword.totalWeight(bow);
    cout << "Суммарный вес меча (" << sword.weight << ") и лука ("<< bow.weight << ") = " << sum1 << "\n";

    // Сумма веса оружия и числа (перегрузка из задания 7)
    float sum2 = sword.totalWeight(5.5f);
    cout << "Вес меча (" << sword.weight << ") + 5.5 = " << sum2 << "\n";

    // Использование переписанного метода (задание 8)
    float sum3 = sword.totalWeightNew(bow);
    cout << "Используя переписанный метод: меч (" << sword.weight << ") + лук (" << bow.weight << ") = " << sum3 << "\n";
    cout << "\n";

    cout << "=== Задание 4: Удаление объектов (вызов деструкторов) ===" << "\n";
    cout << "Удаляем динамический объект:" << "\n";
    delete axe;  // Явный вызов деструктора для динамического объекта
    cout << "\n";

    cout << "Автоматический вызов деструктора для обычных объектов в конце main():" << "\n";
    // Деструкторы для sword и bow вызовутся автоматически при выходе из main()

    return 0;
}