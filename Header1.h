#pragma once
using namespace std;

template< typename T >
class List {
public:
    // ��������� ���� � ������
    void add(const T& t);

    // ������� ��������� ����������� ���� �� ������
    void remove();

    // �������� �������� ������� ������
    T head() const;

    // �������� �������� �� ������ ������
    Iterator begin() const;

    // �������� �������� �� ����� ������
    Iterator end() const;

    // �������� ������ ������
    size_t size() const;

private:
    // ��������� ���� ������������ ������
    struct Node {
        Node() : m_next(NULL) { }

        Node(const T& t) : m_t(t), m_next(NULL) { }

        // �������� ����
        T m_t;

        // ��������� �� ��������� ����
        Node* m_next;
    };

    // ������ ������������ ������
    Node* m_head;
};

template< typename T >
class Iterator {
private:
    // ��������� ��������� ���� ��� ������������� � ������ Iterator
    struct Node;
public:
    Iterator(Node* node) : m_node(node) { }

    // ��������� �������� �������� ���� 
    T operator*() const {
        if (m_node) {
            return m_node->m_t;
        } // ����� ��������� ����� ������. ����� ������� ��������� ����������
        return T();
    }

    // ������� � ���������� ����
    void operator++() {
        if (m_node) {
            m_node = m_node->m_next;
        } // ����� ��������� ����� ������. ����� ������� ��������� ����������
    }

private:
    Node* m_node;
};