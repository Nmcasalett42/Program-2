#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class SmartPointer {
private:
    T* ptr;

public:
    // Constructor
    SmartPointer(T* p = nullptr) : ptr(p) {}

    // Destructor
    ~SmartPointer() {
        delete ptr;
    }

    // Overload dereference operator
    T& operator*() {
        return *ptr;
    }

    // Overload arrow operator
    T* operator->() {
        return ptr;
    }

    // Disable copy constructor and assignment operator
    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;
};

#endif
