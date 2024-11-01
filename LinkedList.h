#pragma once
#include <iostream>
#include <functional>

using namespace std;

template <typename T>
class ListNode 
{
public:
    T data;
    ListNode* next;

    ListNode(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList 
{
private:
    ListNode<T>* head;

    // Helper function for sorting
    void sort(bool ascending, function<bool(const T&, const T&)> compare) 
    {
        if (head == nullptr || head->next == nullptr) return;

        for (ListNode<T>* i = head; i != nullptr; i = i->next) {
            for (ListNode<T>* j = i->next; j != nullptr; j = j->next) 
            {
                bool condition = ascending ? compare(i->data, j->data) : compare(j->data, i->data);
                if (!condition) 
                {
                    swap(i->data, j->data);
                }
            }
        }
    }

public:
    LinkedList() : head(nullptr) {}

    void insert(const T& data) 
    {
        ListNode<T>* newNode = new ListNode<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void remove(const T& data) 
    {
        ListNode<T>* temp = head;
        ListNode<T>* prev = nullptr;

        while (temp != nullptr && !(temp->data == data)) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;
        if (prev == nullptr) head = temp->next;
        else prev->next = temp->next;

        delete temp;
    }

    void display() const 
    {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void sortAscending() { sort(true, [](const T& a, const T& b) { return a < b; }); }
    void sortDescending() { sort(false, [](const T& a, const T& b) { return a < b; }); }
    void sortCustom(function<bool(const T&, const T&)> compare) { sort(true, compare); }

    ~LinkedList() {
        ListNode<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};