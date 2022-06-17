#pragma once

#include <initializer_list>
using std::initializer_list;

template<class T>
class LinkedList
{
public:
    struct Node
    {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;

        Node(const T& _value) : value(_value) {}
    };

    struct Iterator
    {
        Node* node = nullptr;

        Iterator() : node(nullptr) {}
        Iterator(Node* _node) : node(_node) {}

        // Increment operators
        Iterator& operator++() { return Next(); }
        Iterator operator++(int) { return Next(); }

        // Decrement operators
        Iterator& operator--() { return Prev(); }
        Iterator operator--(int) { return Prev(); }

        // Iterator getter
        Iterator& operator+(const int _shiftAmount)
        {
            Iterator iter = *this;
            for (size_t i = 0; i < _shiftAmount - 1; i++)
            {
                iter = iter.Next();
            }

            return iter;
        }

        Iterator& operator-(const int _shiftAmount)
        {
            Iterator iter = *this;
            for (size_t i = _shiftAmount - 1; i > 0; i--)
            {
                iter = iter.Prev();
            }

            return iter;
        }

        // Equality check operators
        bool operator==(const Iterator& _rhs) { return node == _rhs.node; }
        bool operator!=(const Iterator& _rhs) { return node != _rhs.node; }

        // Dereference operator
        T& operator*() { return node->value; }
        T* operator->() { return &node->value; }

        Iterator& Next() {
            if (node != nullptr)
                node = node->next;

            return *this;
        }

        Iterator& Prev() {
            if (node != nullptr)
                node = node->prev;

            return *this;
        }

    };

    LinkedList()
    {
    }

    LinkedList(initializer_list<T> _list)
    {
        for (auto iter = _list.begin(); iter != _list.end(); iter++)
        {
            PushBack(*iter);
        }
    }

    ~LinkedList()
    {
    }

    void PushBack(const T& _value)
    {
        Node* newNode = new Node(_value);
        m_count++;

        if (IsEmpty()) {
            m_first = newNode;
            m_last = newNode;
        }

        else {
            m_last->next = newNode;
            newNode->prev = m_last;
            m_last = newNode;
        }
    }

    void PopBack()
    {
        if (IsEmpty())
            return;

        Node* last = m_last;
        m_last = m_last->prev;
        if (m_last != nullptr)
            m_last->next = nullptr;

        else
            m_first = nullptr;

        delete last;
        m_count--;
    }

    void PushFront(T value)
    {
        if (IsEmpty())
            PushBack(value);

        else
        {
            Node* newNode = new Node(value);
            m_first->prev = newNode;
            newNode->next = m_first;
            m_first = newNode;

            m_count++;
        }

    }

    void PopFront()
    {
        // TODO:
        if (IsEmpty())
            return;

        if (m_count == 1) {
            PopBack();
            return;
        }

        Node* temp = m_first;
        m_first = m_first->next;

        delete temp;
        m_count--;

    }

    void Clear()
    {
        while (m_count > 0)
        {
            PopBack();

        }

    }

    Iterator Remove(Iterator _iter) {
        Node* nodeToRemove = _iter.node;

        // TODO:

        return Iterator(nodeToRemove->next); // maybe
    }

    Iterator Insert(Iterator _iter, const T& _value) {
        Node* currentNode = _iter.node;

        Node* newNode = new Node();
        newNode->value = _value;

        // TODO: create a new Node
        // adjust the next and previous as appropriate
        // so that the new Node is inserted "before" the currentNode

        // return an iterator to the newly created node
        return Iterator(newNode);
    }

    bool IsEmpty()
    {
        return m_first == nullptr && m_last == nullptr;
    }

    unsigned int Count()
    {
        return m_count;
    }

    Node* FirstNode() { return m_first; }
    Node* LastNode() { return m_last; }

    Iterator begin() { return Iterator(m_first); }
    Iterator end() { return Iterator(nullptr); }

protected:
private:
    unsigned int m_count = 0;
    Node* m_first = nullptr;
    Node* m_last = nullptr;
};