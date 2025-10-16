#include <iostream>

int func1(int e = 1);
int func2(int g = 0, int h = 0, int& i, int& j);

int main()
{
    int array[2][3] = { {1,2,4}, {5,6,7}};
    int a = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            a += array[i][j];
        }
    }
    std::cout << a << '\n';

    // ----------------------------------------------

    int array2[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        array2[i] = array[0][i] + array[1][i];
        std::cout << array2[i] << ' ';
    }
    std::cout << '\n';

    // ----------------------------------------------

    float b = 20.84;
    float& c = b;
    float& d = b;
    b = 1234.5678;
    std::cout << b << ", " << c << ", " << d << '\n';

    //----------------------------------------------
    
    std::cout << func1(3) << '\n';

    //----------------------------------------------

    int i = 5;
    int j = 6;
    func2(1, 2, i, j);
    std::cout << i << " " << j << '\n';

    //----------------------------------------------

    int k = 576;
    std::cout << k << '\n';
    for (int i = 0; i < 3; i++) {
        int l = 434;
        std::cout << k << ", " << l << ", ";
    }
    std::cout << '\n';
}




int func1(int e) {
    if (e <= 0) {
        return 0;
    }
    else {
        int f = 0;
        for (int i = 0; i <= e; i++) {
            f += i;
        }
        return f;
    }
}


int func2(int g, int h, int& i, int& j) {
    i = g + h;
    j = g * h;
    return 0;
}




