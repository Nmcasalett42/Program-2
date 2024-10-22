#ifndef LinkedList_H
//define not work??

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(const T& data): data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;

public:
    LinkedList(): head(nullptr) {}

    void insert(const T& data) {
        ListNode<T>* newNode = new ListNode<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void remove(const T& data) {
        ListNode<T>* temp = head;
        ListNode<T>* prev = nullptr;

        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return; // Data not found
        if (prev == nullptr) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }

        delete temp;
    }

    void display() const {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    ~LinkedList() {
        ListNode<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
