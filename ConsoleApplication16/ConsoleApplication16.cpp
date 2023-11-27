#include <iostream>
using namespace std;

class Deque
{
private:
    int* data;
    int max_count;
    int real_count;

public:
    Deque(int max_count)
    {
        this->max_count = max_count;
        data = new int[max_count];
        real_count = 0;
    }

    ~Deque()
    {
        if (data != nullptr)
            delete[] data;
    }

    void Clear()
    {
        real_count = 0;
    }

    bool IsEmpty() const
    {
        return real_count == 0;
    }

    bool IsFull() const
    {
        return real_count == max_count;
    }

    void PushFront(int value)
    {
        if (!IsFull())
        {
            for (int i = real_count; i > 0; i--)
                data[i] = data[i - 1];

            data[0] = value;
            real_count++;
        }
    }

    int PopFront()
    {
        if (!IsEmpty())
        {
            int first = data[0];
            for (int i = 1; i < real_count; i++)
                data[i - 1] = data[i];

            real_count--;
            return first;
        }
        else
        {
            throw "Deque is empty!";
        }
    }

    void PushBack(int value)
    {
        if (!IsFull())
            data[real_count++] = value;
    }

    int PopBack()
    {
        if (!IsEmpty())
        {
            int last = data[real_count - 1];
            real_count--;
            return last;
        }
        else
        {
            throw "Deque is empty!";
        }
    }

    void Print() const
    {
        cout << "---------------------------------------\n";
        for (int i = 0; i < real_count; i++)
            cout << data[i] << "  ";
        cout << "\n";
        cout << "---------------------------------------\n";
    }
};

class Stack : public Deque
{
public:
    Stack(int max_count) : Deque(max_count) {}

    void Push(int value)
    {
        PushBack(value);
    }

    int Pop()
    {
        return PopBack();
    }

    void Print() const
    {
        Deque::Print();
    }
};

int main()
{
    Deque deque(25);

    for (int i = 0; i < 5; i++)
        deque.PushBack(rand() % 90 + 10);

    deque.Print();

    deque.PopFront();

    deque.Print();

    for (int i = 0; i < 2; i++)
        deque.PushBack(rand() % 90 + 10);

    deque.Print();

    for (int i = 0; i < 3; i++)
        deque.PopFront();

    deque.Print();

    Stack stack(25);

    for (int i = 0; i < 5; i++)
        stack.Push(rand() % 90 + 10);

    stack.Print();

    stack.PopFront();

    stack.Print();

    for (int i = 0; i < 2; i++)
        stack.Push(rand() % 90 + 10);

    stack.Print();

    for (int i = 0; i < 3; i++)
        stack.PopBack();

    stack.Print();

    return 0;
}
/*
Deque реализует методы PushFront, PopFront, PushBack и PopBack.

Stack унаследован от Deque.

Не использованы шаблоны, размерности size_t и списки.
*/