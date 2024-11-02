#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <functional>

using namespace std;

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    //Constructor
    ListNode(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    size_t size;

public:
    //Constructor
    LinkedList(): head(nullptr), tail(nullptr), size(0) {}

    //adds new elements to end of list
    void insert(const T& data) {
        ListNode<T>* newNode = new ListNode<T>(data);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    //removes element from list
    void remove(const T& data) {
        ListNode<T>* temp = head;
        ListNode<T>* prev = nullptr;

        while (temp != nullptr && !(temp->data == data)) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (prev == nullptr) head = temp->next;
        else prev->next = temp->next;

        if (temp == tail) tail = prev;

        delete temp;
        --size;
    }

    //display elements
    void display() const {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    //sorts list ascending or decending
    void sort(bool ascending = true) {
        if (head == nullptr || head->next == nullptr) return;

        for (ListNode<T>* i = head; i != nullptr; i = i->next) {
            for (ListNode<T>* j = i->next; j != nullptr; j = j->next) {
                if (ascending ? (i->data > j->data) : (i->data < j->data)) {
                    swap(i->data, j->data);
                }
            }
        }
    }

    //Deconstructor
    ~LinkedList() {
        ListNode<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    size_t getSize() const { return size; }
};
#endif