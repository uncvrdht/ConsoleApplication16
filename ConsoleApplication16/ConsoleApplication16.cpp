#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* back;
    size_t size;

public:
    Deque() : front(nullptr), back(nullptr), size(0) {}

    void PushFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (IsEmpty()) {
            front = back = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void PushBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (IsEmpty()) {
            front = back = newNode;
        }
        else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    void PopFront() {
        if (IsEmpty()) {
            return;
        }

        Node<T>* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        }
        else {
            back = nullptr;
        }
        delete temp;
        size--;
    }

    void PopBack() {
        if (IsEmpty()) {
            return;
        }

        Node<T>* temp = back;
        back = back->prev;
        if (back != nullptr) {
            back->next = nullptr;
        }
        else {
            front = nullptr;
        }
        delete temp;
        size--;
    }

    T Front() const {
        return front->data;
    }

    T Back() const {
        return back->data;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    size_t Size() const {
        return size;
    }
};

class Stack {
private:
    Node<int>* top;
    size_t size;

public:
    Stack() : top(nullptr), size(0) {}

    void Push(int value) {
        Node<int>* newNode = new Node<int>(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void Pop() {
        if (IsEmpty()) {
            return;
        }

        Node<int>* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void PushBack(int value) {
        Push(value);
    }

    void PopFront() {
        Pop();
    }

    bool IsEmpty() const {
        return size == 0;
    }

    size_t Size() const {
        return size;
    }
};

int main() {
    Deque<int> deque;

    deque.PushBack(1);
    deque.PushFront(2);
    deque.PushBack(3);

     cout << "Deque size: " << deque.Size() <<  endl;

     cout << "Front element: " << (deque.IsEmpty() ? -1 : deque.Front()) <<  endl;
     cout << "Back element: " << (deque.IsEmpty() ? -1 : deque.Back()) <<  endl;

    deque.PopFront();
    deque.PopBack();

     cout << "Deque size after popping front and back: " << deque.Size() <<  endl;

    Stack stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

     cout << "Stack size: " << stack.Size() <<  endl;

    stack.PopFront();

     cout << "Stack size after popping front: " << stack.Size() <<  endl;

    return 0;
}
