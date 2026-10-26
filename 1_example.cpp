#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::srand(std::time(nullptr));

    int size = 10;
    int* X = new int[size];

    for (int i = 0; i < size; i++) {
        X[i] = std::rand() % 50;
    }

    std::cout << " Завдання 1 " << std::endl;
    std::cout << std::left << std::setw(15) << "array " << " address " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "ptrarray[" << i << "] = "
            << std::setw(6) << X[i]
            << ", " << static_cast<void*>(&X[i]) << std::endl;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (X[i] % 2 != 0 && X[i] > X[0]) {
            count++;
        }
    }

    std::cout << "\nКількість непарних елементів, більших за перший (" << X[0] << "): " << count << std::endl;

    delete[] X;

    return 0;
}