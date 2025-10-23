namespace MySpace {
    int func1(int a) {
        static int x = 0;
        x = x + a;
        return x;
    }
}