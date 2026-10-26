#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::srand(std::time(nullptr));

    int N = 5;
    int** Y = new int* [N];
    for (int i = 0; i < N; i++) {
        Y[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y[i][j] = std::rand() % 90 + 10;
        }
    }

    std::cout << "Завдання 2" << std::endl;
    std::cout << "Початкова матриця Y:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(5) << Y[i][j];
        }
        std::cout << std::endl;
    }

    int max_diag = Y[0][0];
    for (int i = 1; i < N; i++) {
        if (Y[i][i] > max_diag) {
            max_diag = Y[i][i];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            Y[i][j] = max_diag;
        }
    }

    std::cout << "\nМаксимальний елемент головної діагоналі: " << max_diag << std::endl;
    std::cout << "Модифікована матриця Y:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(5) << Y[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] Y[i];
    }

    delete[] Y;

    return 0;
}