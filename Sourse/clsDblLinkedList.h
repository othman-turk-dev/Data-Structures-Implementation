#pragma once
#include<iostream>

using namespace std;

template <class T>
class clsDblLinkedList 
{
protected:
    int _Size = 0;

public:
    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {
        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        _Size++;
    }

    Node* Find(T value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }

    void PrintList()
    {
        Node* Current = head;

        while (Current != NULL)
        {
            cout << Current->value << " ";
            Current = Current->next;
        }
    }

    void InsertAfter(Node* Current ,T value)
    {
        
        Node* newNode = new Node();
        newNode->value = value;
        newNode->prev = Current;
        newNode->next = Current->next;

        if (Current->next != NULL)
        {
            (Current->next)->prev = newNode;
        }
        Current->next = newNode;
        _Size++;

    }

    void InsertAtEnd(T value)
    {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            Node* curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
        _Size++;

    }

    void DeleteNode(Node* NodeToDelete)
    {
        if (head == NULL || NodeToDelete == NULL)
            return;

        if (head == NodeToDelete)
            head = NodeToDelete->next;

        if (NodeToDelete->next != NULL)
            NodeToDelete->next->prev = NodeToDelete->prev;

        if (NodeToDelete->prev != NULL)
            NodeToDelete->prev->next = NodeToDelete->next;

        delete NodeToDelete;
        _Size--;

    }

    void DeleteFirstNode()
    {
        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL)
        {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
        _Size--;

    }

    void DeleteLastNode() 
    {
        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;

        delete temp;
        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return _Size == 0;
    }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void  Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    Node* GetNode(int Index)
    {
        int Counter = 0;

        if (Index > _Size - 1 || Index < 0)
            return NULL;

        Node* Current = head;
        while (Current != NULL && (Current->next != NULL)) 
        {

            if (Counter == Index)
                break;

            Current = Current->next;
            Counter++;
        }

        return Current;
    }

    T GetItem(int Item)
    {
        Node* Node = GetNode(Item);
        if (Node == NULL)
            return NULL;
        else
            return Node->value;
    }

    bool UpdateItem(int Index, T ValueToUpdate)
    {
        Node* N1 = GetNode(Index);

        if (N1 != NULL)
        {
            N1->value = ValueToUpdate;
            return true;
        }
        else
            return false;
    }

    bool InsertAfter(int Index, T value)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        else 
            return false;
    }

};

