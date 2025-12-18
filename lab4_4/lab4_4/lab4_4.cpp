#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// КЛАСС WEAPON
class Weapon {
private:
    string name;
    float damage;
    float weight;

public:
    // Конструкторы
    Weapon(string name, float damage, float weight) {
        this->name = name;
        this->damage = damage;
        this->weight = weight;
    }

    Weapon() : Weapon("Default Sword", 5.0f, 2.5f) {}

    // Деструктор
    ~Weapon() {
        cout << "Оружие \"" << name << "\" удаляется. ";
        cout << "Характеристики: урон=" << damage << ", вес=" << weight << "\n";
    }

    // GET-методы для всех полей
    string getName() const {
        return name;
    }

    float getDamage() const {
        return damage;
    }

    float getWeight() const {
        return weight;
    }

    // SET-метод для урона
    void setDamage(float newDamage) {
        if (newDamage >= 0) {
            damage = newDamage;
            cout << "Урон оружия \"" << name << "\" изменён на: " << damage << "\n";
        }
        else {
            cout << "Ошибка: урон не может быть отрицательным!" << "\n";
        }
    }

    // Другие методы
    bool isTooHeavy(float maxWeight) {
        return weight > maxWeight;
    }

    float totalWeight(Weapon& otherWeapon) {
        return weight + otherWeapon.weight;
    }

    float totalWeight(float additionalWeight) {
        return weight + additionalWeight;
    }

    float totalWeightNew(Weapon& otherWeapon) {
        return totalWeight(otherWeapon.weight);
    }

    void show() {
        cout << "Название: " << name << ", Урон: " << damage
            << ", Вес: " << weight << endl;
    }

    // Объявляем класс Characteristic дружественным
    friend class Characteristic;
};

// КЛАСС CHARACTERISTIC
class Characteristic {
private:
    float strength;

public:
    // Конструктор
    Characteristic(float strength) : strength(strength) {}

    // Метод GetDamage
    float GetDamage(const Weapon& weapon) {
        // Благодаря дружественности можем обращаться к приватному полю damage
        return strength + weapon.damage;
    }

    // GET-метод для силы
    float getStrength() const {
        return strength;
    }
};

// КЛАСС MYMATH
class MyMath {
private:
    // Статическое поле для подсчёта вызовов
    static int callCount;

public:
    // Статические методы
    static float Add(float a, float b) {
        callCount++;
        return a + b;
    }

    static float Sub(float a, float b) {
        callCount++;
        return a - b;
    }

    static float Mult(float a, float b) {
        callCount++;
        return a * b;
    }

    static float Div(float a, float b) {
        if (b == 0) {
            throw runtime_error("Деление на ноль!");
        }
        callCount++;
        return a / b;
    }

    // Метод для получения количества вызовов
    static int getCallCount() {
        return callCount;
    }

    // Метод для сброса счётчика
    static void resetCallCount() {
        callCount = 0;
    }
};

// Инициализация статического поля MyMath
int MyMath::callCount = 0;

// ГЛАВНАЯ ФУНКЦИЯ
int main() {
    setlocale(LC_CTYPE, "rus");
    cout << "=== ТЕСТИРОВАНИЕ КЛАССА WEAPON ===" << "\n";

    // Создаём оружие
    Weapon sword("Меч", 15.0f, 8.0f);

    // Проверяем GET-методы
    cout << "\n1. Проверка GET-методов:" << "\n";
    cout << "Название: " << sword.getName() << "\n";
    cout << "Урон: " << sword.getDamage() << "\n";
    cout << "Вес: " << sword.getWeight() << "\n";

    // Проверяем SET-метод
    cout << "\n2. Проверка SET-метода:" << "\n";
    sword.setDamage(20.0f);
    cout << "Новый урон: " << sword.getDamage() << "\n";

    // Пытаемся установить отрицательный урон
    sword.setDamage(-5.0f);
    cout << "Урон остался: " << sword.getDamage() << "\n";

    cout << "\n=== ТЕСТИРОВАНИЕ КЛАССА CHARACTERISTIC ===" << "\n";

    // Создаём характеристику и проверяем GetDamage
    Characteristic heroStrength(10.5f);
    cout << "\n3. Сила героя: " << heroStrength.getStrength() << "\n";

    // Вызываем GetDamage
    float totalDamage = heroStrength.GetDamage(sword);
    cout << "Общий урон (сила + оружие): " << totalDamage << " = "
        << heroStrength.getStrength() << " + " << sword.getDamage() << "\n";

    // Создадим ещё одно оружие для демонстрации
    Weapon bow("Лук", 8.0f, 3.0f);
    float bowDamage = heroStrength.GetDamage(bow);
    cout << "Урон с луком: " << bowDamage << " = "
        << heroStrength.getStrength() << " + " << bow.getDamage() << "\n";

    cout << "\n=== ТЕСТИРОВАНИЕ КЛАССА MYMATH ===" << "\n";

    // Сбрасываем счётчик
    MyMath::resetCallCount();

    // Проверяем все 4 метода
    cout << "\n4. Проверка статических методов MyMath:" << "\n";

    float a = 10.5f;
    float b = 2.5f;

    cout << a << " + " << b << " = " << MyMath::Add(a, b) << "\n";
    cout << a << " - " << b << " = " << MyMath::Sub(a, b) << "\n";
    cout << a << " * " << b << " = " << MyMath::Mult(a, b) << "\n";
    cout << a << " / " << b << " = " << MyMath::Div(a, b) << "\n";

    // Ещё несколько вызовов для демонстрации
    cout << "\nЕщё несколько операций:" << "\n";
    cout << "100 + 50 = " << MyMath::Add(100, 50) << "\n";
    cout << "20 * 3 = " << MyMath::Mult(20, 3) << "\n";

    // Проверяем значение статической переменной
    cout << "\n5. Проверка статической переменной:" << "\n";
    int calls = MyMath::getCallCount();
    cout << "Количество вызовов статических методов: " << calls << "\n";

    // Демонстрация работы с делением на 0
    cout << "\n6. Попытка деления на ноль:" << "\n";
    try {
        cout << "10 / 0 = " << MyMath::Div(10, 0) << "\n";
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << "\n";
    }

    // Проверяем счётчик после исключения
    cout << "Количество вызовов после исключения: " << MyMath::getCallCount() << "\n";

    cout << "\n=== ПРОВЕРКА ДРУГИХ МЕТОДОВ WEAPON ===" << "\n";

    // Проверка метода isTooHeavy
    cout << "\n7. Проверка веса оружия:" << "\n";
    if (sword.isTooHeavy(10.0f)) {
        cout << "Меч слишком тяжелый (вес " << sword.getWeight() << " > 10)" << "\n";
    }
    else {
        cout << "Меч можно поднять (вес " << sword.getWeight() << " <= 10)" << "\n";
    }

    if (bow.isTooHeavy(2.0f)) {
        cout << "Лук слишком тяжелый (вес " << bow.getWeight() << " > 2)" << "\n";
    }
    else {
        cout << "Лук можно поднять (вес " << bow.getWeight() << " <= 2)" << "\n";
    }

    // Проверка методов totalWeight
    cout << "\n8. Проверка методов totalWeight:" << "\n";
    Weapon axe("Топор", 12.0f, 15.0f);
    cout << "Вес меча + лука = " << sword.totalWeight(bow) << "\n";
    cout << "Вес меча + 5.5 = " << sword.totalWeight(5.5f) << "\n";
    cout << "Вес меча + топор (через переписанный метод) = " << sword.totalWeightNew(axe) << "\n";

    cout << "\n=== ЗАВЕРШЕНИЕ ПРОГРАММЫ (ВЫЗОВ ДЕСТРУКТОРОВ) ===" << "\n";

    return 0;
}