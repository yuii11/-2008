#include <iostream>

using namespace std;

// Перечисление для типов книг
enum BookType {
    FICTION = 1,   // Художественная литература
    TECHNICAL = 2  // Техническая литература
};

// Функция для подсчета и вывода количества каждого типа книг
void displayBookCounts(BookType* books, int size) {
    int fictionCount = 0;
    int technicalCount = 0;

    // Подсчет книг по типам
    for (int i = 0; i < size; ++i) {
        switch (books[i]) {
        case FICTION:
            fictionCount++;
            break;
        case TECHNICAL:
            technicalCount++;
            break;
        default:
            cout << "Неизвестный тип книги!" << endl;
            break;
        }
    }

    // Вывод количества книг каждого типа
    cout << "Количество художественной литературы: " << fictionCount << endl;
    cout << "Количество технической литературы: " << technicalCount << endl;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    int n;

    // Ввод количества книг в библиотеке
    cout << "Введите количество книг: ";
    cin >> n;

    // Динамическое выделение памяти для массива книг
    BookType* books = new BookType[n];

    // Заполнение массива типов книг
    cout << "Введите тип каждой книги (1 - художественная, 2 - техническая):" << endl;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            books[i] = FICTION;
        }
        else if (type == 2) {
            books[i] = TECHNICAL;
        }
        else {
            cout << "Неправильный тип книги. Попробуйте снова." << endl;
            --i; // Повторный ввод для текущей позиции
        }
    }

    // Вызов функции для вывода количества книг
    displayBookCounts(books, n);

    // Освобождение выделенной памяти
    delete[] books;

    return 0;
}
