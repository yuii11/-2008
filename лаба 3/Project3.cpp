#include <iostream>
#include <vector>
#include <memory>

class Part {
protected:
    Part() { std::cout << "Part created\n"; }

public:
    virtual ~Part() = default;
    virtual void show() const = 0; // чисто виртуальный метод
};

class Assembly : public Part {
protected:
    Assembly() { std::cout << "Assembly created\n"; }

public:
    void show() const override {
        std::cout << "This is an assembly.\n";
    }

    // Статический метод для создания объектов Assembly
    static std::unique_ptr<Part> create() {
        return std::unique_ptr<Part>(new Assembly());
    }
};

int main() {
    std::vector<std::unique_ptr<Part>> storage;

    // Добавляем объект Assembly в хранилище через статический метод create
    storage.emplace_back(Assembly::create());

    for (const auto& item : storage) {
        item->show();
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

// Базовый класс
class Base {
public:
    virtual ~Base() = default; // Виртуальный деструктор
    virtual void show() const = 0; // Чисто виртуальная функция
};

// Производный класс 1
class Derived1 : public Base {
public:
    void show() const override {
        std::cout << "This is Derived1 class.\n";
    }
};

// Производный класс 2
class Derived2 : public Base {
public:
    void show() const override {
        std::cout << "This is Derived2 class.\n";
    }
};

// Производный класс 3
class Derived3 : public Base {
public:
    void show() const override {
        std::cout << "This is Derived3 class.\n";
    }
};

// Функция для добавления объектов в вектор
void add(std::vector<std::unique_ptr<Base>>& storage, std::unique_ptr<Base> obj) {
    storage.push_back(std::move(obj)); // Добавление объекта в вектор
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Инициализация генератора случайных чисел
    std::vector<std::unique_ptr<Base>> storage; // Вектор для хранения указателей на объекты

    // Случайное создание объектов и добавление их в хранилище
    for (int i = 0; i < 10; ++i) {
        int randomType = std::rand() % 3; // Генерация случайного числа от 0 до 2
        if (randomType == 0) {
            add(storage, std::make_unique<Derived1>()); // Добавление объекта Derived1
        }
        else if (randomType == 1) {
            add(storage, std::make_unique<Derived2>()); // Добавление объекта Derived2
        }
        else {
            add(storage, std::make_unique<Derived3>()); // Добавление объекта Derived3
        }
    }

    // Демонстрация различного поведения объектов
    for (const auto& obj : storage) {
        obj->show(); // Вызов метода show для каждого объекта
    }

    // Память освобождается автоматически благодаря unique_ptr

    return 0; // Завершение программы
}
