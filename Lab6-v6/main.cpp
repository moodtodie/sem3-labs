#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

/*
 *     Цель работы:
 * Создание консольной программы для реализации обработки ошибок с использованием механизма обработки исключительных ситуаций,
 * создание специальных классов обработки исключительных ситуаций,
 * рассмотрение замены обработчиков функций terminate() и unexpected() собственными функциями.
 *
 *    Общие требования к выполнению работы:
 * 1. Создать обычный или шаблонный класс согласно заданию. Данные в классе хранить в статическом массиве.
 *    Набор методов класса должен обеспечить основные операции с элементами объекта (добавление, удаление, поиск, просмотр и т.п.)
 *    и операции над однотипными объектами (сравнение, присвоение и т.п.).
 * 2. Обработку всех ошибочных ситуаций реализовать с использованием схемы обработки исключительных ситуаций.
 *    Реализовать собственный класс обработки исключительной ситуации.
 * 3. Рассмотреть замену обработчиков функций terminate() и unexpected() собственными функциями.
 * 4. В функции main выполнить действия с экземпляром класса, которые продемонстрируют работу методов, в том числе и реакцию на возникновение ошибок.
 */


class SetException {
private:
    string m_error;
public:
    SetException(string Exception) {
        m_error = "Error: " + Exception;
    }

    ~SetException() = default;

    string what() { return m_error; }
};

/// ------------------------------------------------------------

void myTerm() {
    cout << "The program was terminated." << endl;
    exit(-1);
}

/// ------------------------------------------------------------

template<typename T>  /// Set (mathematics)
class Set {
public:
    Set() {   // Constructor
        for (int i = 0; i < sizeof(array) / sizeof(*array); ++i)
            array[i] = NULL;

        isEmpty = true;
    }

    ~Set() = default;

    void add(T x) {
        cout << "Add " << x << " to set." << endl;

        if (pointer < sizeof(array) / sizeof(*array)) {
            array[pointer++] = x;
            isEmpty = false;
        } else
            throw SetException("Not enough free space");
    }

    void remove(int index) {
        cout << "Remove element #" << index << endl;
        if (isEmpty)
            throw SetException("Set is empty.");

        if (index < 0 || index > pointer) {
            throw SetException("Invalid index");
        }

        if (index != sizeof(array) / sizeof(*array) - 1)
            for (int i = index; i < sizeof(array) / sizeof(*array) - 1; ++i)
                array[i] = array[i + 1];

        array[sizeof(array) / sizeof(*array) - 1] = NULL;
        pointer--;
        if (pointer < 0)
            isEmpty = true;
    }

    void find(T x) {
        cout << "Find element: " << x << endl;
        for (int i = 0; i < sizeof(array) / sizeof(*array); ++i)
            if (array[i] == x) {
                cout << i << " index of element." << endl;
                return;
            }
        cout << "Element not found." << endl;
    }

    void view() {
        cout << "Viewing the set." << endl;

        if (isEmpty)
            throw SetException("Set is empty.");

        for (int i = 0; i < sizeof(array) / sizeof(*array); ++i) {
            if (array[i] != NULL)
                cout << i + 1 << ") Set[" << i << "] = " << array[i] << endl;
        }
    }

    void sort() {
        if (isEmpty){
            cout << "Set sorting..." << endl;
            throw SetException("Set is empty.");
        }

        for (int i = 0; i < sizeof(array) / sizeof(*array); i++)
            for (int j = 0; j < sizeof(array) / sizeof(*array) - 1; j++)
                if (array[j] > array[j + 1]) {
                    T b = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = b;
                }

        for (int i = 0; i < sizeof(array) / sizeof(*array); i++)
            if (array[i] == NULL && i < pointer)
                this->remove(i);
        cout << "Set sorted." << endl;
    }

private:
    int pointer = 0;
    T array[5];
    bool isEmpty = true;
};

int main() {
    set_terminate(myTerm);

    Set<double> A;

    cout << endl;

    try {
        A.view();
        A.remove(0);
    }
    catch (SetException exception) {
        cout << exception.what() << endl;
    }
    catch (...) {
        std::unexpected();
    }

    cout << endl;

    try {
        A.add(3.54);
        A.add(23.4);
        A.add(5.68);
        A.add(11.2);
        A.add(12.5);
        cout << endl;
        A.view();
        cout << endl;
        A.add(3.4);
    }
    catch (SetException exception) {
        cout << exception.what() << endl;
    }
    catch (...) {
        unexpected();
    }

    terminate();
    return 0;
}