#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        clear();
    }

    void insert(int value)
    {
        Node *NewNode = new Node(value);
        if (head == nullptr)
        {
            head = NewNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = NewNode;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            std::cout << "[]" << std::endl;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void eliminate(int value)
    {
        if (head == nullptr)
            std::cout << "\033[31ERROR: List is empty!!!033[0m\n";

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {
            Node *tschuss = temp->next;
            temp->next = temp->next->next;
            delete tschuss;
        }
    }
    void clear()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;       
        }
    }
};

int main()
{
    LinkedList list;
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(33);
    list.insert(5);
    list.eliminate(5);
    list.display();
    return 0;
};