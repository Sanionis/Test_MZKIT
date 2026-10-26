#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, y, a, b, c, log_a;
    int set_choice;

    printf("Введіть значення x: ");
    if (scanf_s("%lf", &x) != 1) {
        printf("Помилка введення даних.\n");
        return 1;
    }

    printf("Оберіть набір параметрів (1, 2 або 3):\n");
    printf("1: a = 0.1,  b = 9.8,   c = 11.12\n");
    printf("2: a = 10,   b = 10.05, c = 6.2\n");
    printf("3: a = 100,  b = 3.03,  c = 7.12\n");
    printf("Ваш вибір: ");
    scanf_s("%d", &set_choice);

    switch (set_choice) {
    case 1:
        a = 0.1; b = 9.8; c = 11.12;
        break;
    case 2:
        a = 10.0; b = 10.05; c = 6.2;
        break;
    case 3:
        a = 100.0; b = 3.03; c = 7.12;
        break;
    default:
        printf("Некоректний вибір параметрів.\n");
        return 1;
    }

    log_a = log10(a);

    if (log_a < x) {
        y = cbrt(b * b + sqrt(fabs(x + c)));
    }
    else if (fabs(log_a - x) < 1e-7) {
        y = cos(x - b - c);
    }
    else {
        y = sin(x + a - b);
}
    printf("Результат y = %f\n", y);
    return 0;
}
// test commit