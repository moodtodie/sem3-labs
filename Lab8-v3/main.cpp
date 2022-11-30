#include <iostream>

using namespace std;

class Exception{
    string errorMsg;
public:
    Exception(const string& msg){ errorMsg = "Error: " + msg; }

    ~Exception() = default;

    string what(){ return errorMsg; }
};

/**
 * Цель работы:
    Создание консольной программы с реализацией объектов для хранения данных
    в динамической памяти на основе шаблонных классов, изучение указателей на объекты.

 * Общие требования к выполнению работы:
    Построить шаблонный класс, который будет описывать
    элемент хранимых данных,
    доступ к ним,
    сравнение элементов
    и т.п. по необходимости.

 * Дополнительно к контейнеру рекомендуется реализовать класс-итератор.

 * В функции main создать три экземпляра шаблонного класса-контейнера для разных типов данных.
    Работа с этими объектами должна демонстрироваться на следующих операциях:
    добавить – просмотреть – найти – удалить – найти – просмотреть.

 * Проверить обработку исключительных ситуаций (например, чтение из пустого стека, дублирование объектов и т.п.).
 */

template<typename T>
class Node {
public:
    T value;
    Node<T>* next = nullptr;
    Node(T value){ this->value = value; }
};

template<typename T>
class List {
    Node<T>* firstNode;
public:
    List(){ firstNode = nullptr; }

    void push(T value) {
        bool flag = false;
        try {
            if (find(value))
                flag = true;
        } catch (...){}
        if (flag)
            throw Exception("This value is already in the list.");

        auto* ptr = new Node<T>(value);
        if (isEmpty()) {
            firstNode = ptr;
            return;
        }
        Node<T>* lastNode = firstNode; // last(current)
        while (lastNode->next != nullptr)
            lastNode = lastNode->next;
        lastNode->next = ptr;
        lastNode = ptr;
    }

    T pop(int index= 0){
        if (isEmpty())
            throw Exception("List is empty.");
        if (index < 0)
            throw Exception("index - uses an invalid value.");

        Node<T>* ptr = firstNode;
        Node<T>* lastPtr = firstNode;
        int i = 0;
        while (ptr) {
            if (i == index)
                break;
            if (i++ > 0)
                lastPtr = lastPtr->next;
            ptr = ptr->next;
        }

        if (index != i || ptr == nullptr)
            throw Exception("index - uses an invalid value.");

        T tmp = ptr->value;
        if (index == 0)
            firstNode = ptr->next;
        else
            lastPtr->next = ptr->next;
        delete ptr;
        return tmp;
    }

    int find(T value){
        if (isEmpty())
            throw Exception("List is empty.");

        Node<T>* ptr = firstNode;
        int index = 0;
        while (ptr) {
            if (ptr->value == value)
                return index;
            index++;
            ptr = ptr->next;
        }
        throw Exception("Value not found.");
    }

    void print() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node<T>* ptr = firstNode;
        while (ptr) {
            cout << ptr->value << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    bool isEmpty(){ return firstNode == nullptr; }

    Node<T>* operator [] (const int index) {
        if (isEmpty())
            throw Exception("List is empty.");
        if (index < 0)
            throw Exception("index - uses an invalid value.");

        Node<T>* ptr = firstNode;
        int i = 0;
        while (ptr) {
            if (i == index)
                break;
            i++;
            ptr = ptr->next;
        }

        if (index != i || ptr == nullptr)
            throw Exception("index - uses an invalid value.");

        return ptr;
    }
};

int main() {
    List<int> list;
    try {
        list.push(3);
        list.push(16);
        list.push(-48);
        list.push(19);
        list.print();

        list.pop(list.find(3));
        list.print();

        list.push(50);
        list.print();
    } catch (Exception exception) {
        cout << exception.what() << endl;
    }
    return 0;
}
