#pragma once
#include <stdexcept>


template <typename T>
class Stack
{
public:
    Stack() : top(nullptr), size(0) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T data)
    {
        Node* newNode = new Node(std::move(data));
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }

        T data = std::move(top->data);
        Node* oldTop = top;
        top = top->next;
        delete oldTop;
        size--;

        return data;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    T& gettop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }

        return top->data;
    }

    size_t getSize() const
    {
        return size;
    }

private:
    struct Node
    {
        T data;
        Node* next;

        Node(T data) : data(std::move(data)), next(nullptr) {}
    };

    Node* top;
    size_t size;
};