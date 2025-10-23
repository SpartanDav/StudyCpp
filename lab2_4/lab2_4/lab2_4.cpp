#include <iostream>
#include "Header.h"


using std::cout;
using std::cin;
using std::endl;

#define summm(a, b) a + b;

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << MySpace::func1(10) << '\n';
    cout << MySpace::func1(10) << '\n';
    cout << MySpace::func1(80) << '\n';
    cout << summm(34, 6);
    cout << '\n';
    cout << "Для закрытия консоли, введите любой символ и нажмите Enter";
    int a = 0;
    cin >> a;

}