#include <iostream>
#include <string>
using namespace std;
class Publication {
protected:
    string title;  // Название публикации
    float price;   // Цена публикации
public:
    // Конструктор
    Publication(const string& t = "", float p = 0.0) : title(t), price(p) {}
    // Метод для ввода данных
    virtual void getData() {
        cout << "Введите название публикации: ";
        getline(cin, title);
        cout << "Введите цену публикации: ";
        cin >> price;
        cin.ignore(); // Убираем символ новой строки из буфера
    }
    // Метод для вывода данных
    virtual void putData() const {
        cout << "Название: " << title << ", Цена: " << price << endl;
    }
    // Виртуальный деструктор для безопасного разрушения наследуемых объектов
    virtual ~Publication() {}
};
class Book : public Publication {
private:
    int pageCount; // Количество страниц в книге
public:
    // Конструктор
    Book(const string& t = "", float p = 0.0, int pc = 0) : Publication(t, p), pageCount(pc) {}
    // Переопределяем метод getData
    void getData() override {
        Publication::getData(); // Получаем данные от родительского класса
        cout << "Введите количество страниц: ";
        cin >> pageCount;
        cin.ignore(); // Убираем символ новой строки из буфера
    }
    // Переопределяем метод putData
    void putData() const override {
        Publication::putData(); // Выводим данные от родительского класса
        cout << "Количество страниц: " << pageCount << endl;
    }
};
class Audio : public Publication {
private:
    int duration; // Длительность записи в минутах

public:
    // Конструктор
    Audio(const string& t = "", float p = 0.0, int d = 0) : Publication(t, p), duration(d) {}
    // Переопределяем метод getData
    void getData() override {
        Publication::getData(); // Получаем данные от родительского класса
        cout << "Введите длительность записи (в минутах): ";
        cin >> duration;
        cin.ignore(); // Убираем символ новой строки из буфера
    }
    // Переопределяем метод putData
    void putData() const override {
        Publication::putData(); // Выводим данные от родительского класса
        cout << "Длительность записи: " << duration << " минут" << endl;
    }
};
int main() {
    setlocale(LC_CTYPE, "rus");
    Book book;
    cout << "Введите данные книги:" << endl;
    book.getData();
    cout << "\nДанные о книге:" << endl;
    book.putData();
    Audio audio;
    cout << "\nВведите данные аудиозаписи:" << endl;
    audio.getData();
    cout << "\nДанные об аудиозаписи:" << endl;
    audio.putData();

    return 0;
}






#include <iostream>
#include <string>

using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;  // Название публикации
    float price;   // Цена публикации

public:
    Publication(const string& t = "", float p = 0.0) : title(t), price(p) {}

    virtual void getData() {
        cout << "Введите название публикации: ";
        cin.ignore();  // Убираем оставшийся символ новой строки
        getline(cin, title);
        cout << "Введите цену публикации: ";
        cin >> price;
    }

    virtual void putData() const {
        cout << "Название: " << title << ", Цена: " << price << endl;
    }

    virtual ~Publication() {}
};

// Базовый класс Sales
class Sales {
protected:
    float sales[3];  // Продажи за три месяца

public:
    void getSalesData() {
        cout << "Введите данные о продажах за последние три месяца:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putSalesData() const {
        cout << "Продажи за последние три месяца:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << endl;
        }
    }
};

// Класс Book наследует как Publication, так и Sales
class Book : public Publication, public Sales {
private:
    int pageCount;  // Количество страниц

public:
    Book(const string& t = "", float p = 0.0, int pc = 0) : Publication(t, p), pageCount(pc) {}

    void getData() override {
        Publication::getData();
        cout << "Введите количество страниц: ";
        cin >> pageCount;
        getSalesData();  // Вводим данные о продажах
    }

    void putData() const override {
        Publication::putData();
        cout << "Количество страниц: " << pageCount << endl;
        putSalesData();  // Выводим данные о продажах
    }
};

// Класс Audio наследует как Publication, так и Sales
class Audio : public Publication, public Sales {
private:
    int duration;  // Длительность записи в минутах

public:
    Audio(const string& t = "", float p = 0.0, int d = 0) : Publication(t, p), duration(d) {}

    void getData() override {
        Publication::getData();
        cout << "Введите длительность записи (в минутах): ";
        cin >> duration;
        getSalesData();  // Вводим данные о продажах
    }

    void putData() const override {
        Publication::putData();
        cout << "Длительность записи: " << duration << " минут" << endl;
        putSalesData();  // Выводим данные о продажах
    }
};

int main() {
    setlocale(LC_CTYPE, "rus");
    // Пример работы с классом Book
    Book book;
    cout << "Введите данные книги:\n";
    book.getData();
    cout << "\nДанные о книге:\n";
    book.putData();

    // Пример работы с классом Audio
    Audio audio;
    cout << "\nВведите данные аудиозаписи:\n";
    audio.getData();
    cout << "\nДанные об аудиозаписи:\n";
    audio.putData();

    return 0;
}    }

// Вызов функции для вывода количества книг
displayBookCounts(books, n);

// Освобождение выделенной памяти
delete[] books;

return 0;
}
