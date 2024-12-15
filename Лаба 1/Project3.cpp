#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    int n;

    // Ввод размера массива
    cout << "Введите размер массива: ";
    cin >> n;

    // Создание массива
    int* arr = new int[n];  // динамическое выделение памяти

    // Заполнение массива
    cout << "Введите " << n << " целых чисел: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Вывод содержимого массива
    cout << "Содержимое массива: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Адрес начала массива: " << arr << endl;

    for (int i = 0; i < n; ++i) {
        cout << "Элемент " << i << " находится по адресу: " << &arr[i]
            << " (расстояние от начала: " << (reinterpret_cast<char>(&arr[i]) - reinterpret_cast<char>(arr)) << " байт)"
            << endl;
    }
    delete[] arr;

    return 0;
}
