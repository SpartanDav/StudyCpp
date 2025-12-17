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
};

int main() {
    setlocale(LC_CTYPE, "rus");
    // Создание объектов
    Weapon weapon1("Axe", 15.0f, 8.0f);
    Weapon weapon2;

    // Вывод weapon1
    std::cout << "Weapon 1:\n";
    std::cout << "Name: " << weapon1.name << "\n";
    std::cout << "Damage: " << weapon1.damage << "\n";
    std::cout << "Weight: " << weapon1.weight << "\n\n";

    // Вывод weapon2
    std::cout << "Weapon 2:\n";
    std::cout << "Name: " << weapon2.name << "\n";
    std::cout << "Damage: " << weapon2.damage << "\n";
    std::cout << "Weight: " << weapon2.weight << "\n";

    return 0;
}