#include <iostream>
#include <string>
using namespace std;


template<typename T>
class List 
{
public:
    List();
    ~List();
    void PopFront();
    void PushBack(T data);
    int GetSize() {
        return Size;
    }

    T& operator[](const int index);
    // T PopBack(); 

private:

    // template<typename T>
    class Node 
    {
    public:
        Node *pNext;
        T data;
        Node(T data=T(), Node*pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node *head;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    
}

template<typename T>
void List<T>::PushBack(T data)
{
    if (head == nullptr) 
    {
        head = new Node(data);
    } else {
        Node *current = this->head;
        while (current->pNext !=nullptr) 
        {
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    if(index > Size) {
        throw std::out_of_range("Out of range");
    }
    int counter = 0;
    Node *current = this->head;
    while (current !=nullptr) 
    {
        if (counter == index) 
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
    return current->data;
}

template<typename T>
void List<T>::PopFront() 
{
    Node* temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

int main() {

    List<int> lst;
    lst.PushBack(5);
    lst.PushBack(3);
    lst.PushBack(7);
    lst.PopFront();
    cout << lst[0];
    
    return 0;
}

