#pragma once
using namespace std;

template< typename T >
class List {
public:
    // Добавляем узел в список
    void add(const T& t);

    // Удаляем последний добавленный узел из списка
    void remove();

    // Получаем головной элемент списка
    T head() const;

    // Получаем итератор на начало списка
    Iterator begin() const;

    // Получаем итератор на конец списка
    Iterator end() const;

    // Получаем размер списка
    size_t size() const;

private:
    // Структура узла односвязного списка
    struct Node {
        Node() : m_next(NULL) { }

        Node(const T& t) : m_t(t), m_next(NULL) { }

        // Значение узла
        T m_t;

        // Указатель на следующий узел
        Node* m_next;
    };

    // Голова односвязного списка
    Node* m_head;
};

template< typename T >
class Iterator {
private:
    // Объявляем структуру узла для использования в классе Iterator
    struct Node;
public:
    Iterator(Node* node) : m_node(node) { }

    // Получение значения текущего узла 
    T operator*() const {
        if (m_node) {
            return m_node->m_t;
        } // Иначе достигнут конец списка. Здесь уместно возбудить исключение
        return T();
    }

    // Переход к следующему узлу
    void operator++() {
        if (m_node) {
            m_node = m_node->m_next;
        } // Иначе достигнут конец списка. Здесь уместно возбудить исключение
    }

private:
    Node* m_node;
};