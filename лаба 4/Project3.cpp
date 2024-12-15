#include <iostream>
#include <stdexcept>
#include <vector>

// Базовый класс для ошибок
class Error {
public:
    virtual void showMessage() const {
        std::cout << "General program error\n";
    }
    virtual ~Error() = default;
};
// Ошибка доступа к памяти
class MemoryAccessError : public Error {
public:
    void showMessage() const override {
        std::cout << "Memory access error\n";
    }
};
// Математическая ошибка
class MathError : public Error {
public:
    void showMessage() const override {
        std::cout << "Mathematical error\n";
    }
};
// Ошибка деления на ноль
class DivisionByZeroError : public MathError {
public:
    void showMessage() const override {
        std::cout << "Division by zero error\n";
    }
};
// Ошибка переполнения
class OverflowError : public MathError {
public:
    void showMessage() const override {
        std::cout << "Overflow error\n";
    }
};

// Шаблонный класс для хранения массива указателей на объекты произвольного типа
template <typename T>
class PointerArray {
private:
    std::vector<T*> items;
public:
    // Добавить элемент в массив
    void add(T* item) {
        items.push_back(item);
    }

    // Перегрузка операции []
    T* operator[](std::size_t index) {
        if (index >= items.size()) {
            throw std::out_of_range("Index out of range");
        }
        return items[index];
    }

    // Деструктор для очистки памяти
    ~PointerArray() {
        for (T* item : items) {
            delete item;
        }
    }
};
int main() {
    try {
        // Демонстрация работы с PointerArray для классов ошибок
        PointerArray<Error> errors;

        errors.add(new MemoryAccessError());
        errors.add(new MathError());
        errors.add(new DivisionByZeroError());
        errors.add(new OverflowError());

        // Выводим сообщения об ошибках
        for (std::size_t i = 0; i < 4; ++i) {
            errors[i]->showMessage();
        }
        // Попытка обращения к несуществующему индексу для проверки выброса исключения
        errors[10]->showMessage(); // Это вызовет std::out_of_range
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}


#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <stdexcept> // Для обработки исключений

class Base {
public:
    virtual ~Base() = default;
    virtual void show() const = 0;
};

class Derived : public Base {
public:
    void show() const override {
        std::cout << "This is Derived class.\n";
    }
};

void add(std::vector<std::unique_ptr<Base>>& storage, std::unique_ptr<Base> obj) {
    storage.push_back(std::move(obj));
}

int main() {
    try {
        // Случай, вызывающий std::length_error
        std::vector<std::unique_ptr<Base>> storage;

        // Попытка зарезервировать слишком большой размер
        storage.reserve(static_cast<std::size_t>(-1)); // Превышает максимально допустимый размер вектора

        // Демонстрация обычного поведения
        for (int i = 0; i < 10; ++i) {
            if (std::rand() % 2 == 0) {
                add(storage, std::make_unique<Derived>());
            }
            else {
                add(storage, std::make_unique<Derived>());
            }
        }

        for (const auto& obj : storage) {
            obj->show();
        }
    }
    catch (const std::length_error& e) {
        std::cerr << "Caught std::length_error: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
