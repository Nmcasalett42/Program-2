#include <iostream>

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(const T& data) {
        ListNode<T>* newNode = new ListNode<T>(data);
        newNode->next = head;
        head = newNode;
    }

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

        delete temp;
    }

    void display() const {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }

    bool isEmpty() const { return head == nullptr; }

    ~LinkedList() {
        ListNode<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};