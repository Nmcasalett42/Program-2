#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

using namespace std;

template <typename T>
class SmartPointer 
{
private:
    T* pointer;

public:
    // Constructor that allocates a new pointer
    SmartPointer(T* ptr = nullptr) : pointer(ptr) {}

    // Copy constructor that makes a deep copy
    SmartPointer(const SmartPointer& other) 
    {
        pointer = new T(*other.pointer);
    }

    // Assignment operator that makes a deep copy
    SmartPointer& operator=(const SmartPointer& other) 
    {
        if (this != &other) 
        {
            delete pointer;
            pointer = new T(*other.pointer);
        }
        return *this;
    }

    // Move constructor
    SmartPointer(SmartPointer&& other) noexcept : pointer(other.pointer) 
    {
        other.pointer = nullptr;
    }

    // Move assignment operator
    SmartPointer& operator=(SmartPointer&& other) noexcept 
    {
        if (this != &other) 
        {
            delete pointer;
            pointer = other.pointer;
            other.pointer = nullptr;
        }
        return *this;
    }

    // Destructor
    ~SmartPointer() 
    {
        delete pointer;
    }

    // Dereference operator
    T& operator*() const { return *pointer; }

    // Arrow operator
    T* operator->() const { return pointer; }

    // Comparison operators
    bool operator==(const SmartPointer& other) const { return *pointer == *other.pointer; }
    bool operator!=(const SmartPointer& other) const { return !(*this == other); }
};
#endif