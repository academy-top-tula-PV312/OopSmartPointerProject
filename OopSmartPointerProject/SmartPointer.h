#pragma once
#include <iostream>

template <typename T>
class SmartPointer
{
    T* pointer;
public:
    SmartPointer(T* pointer = nullptr)
        : pointer{ pointer } 
    {
        std::cout << "SmartPointer construct\n";
    }

    SmartPointer(const SmartPointer& other)
    {
        pointer = new T;
        *pointer = *other.pointer;
        std::cout << "SmartPointer construct copy\n";
    }

    SmartPointer(SmartPointer&& other) noexcept
        : pointer{ other.pointer }
    {
        other.pointer = nullptr;
        std::cout << "SmartPointer construct move\n";
    }

    SmartPointer& operator=(const SmartPointer& other)
    {
        if (&other == this)
            return *this;

        delete[] pointer;

        pointer = new T;
        *pointer = *other.pointer;

        std::cout << "SmartPointer assigment copy\n";
        return *this;
    }

    SmartPointer& operator=(SmartPointer&& other) noexcept
    {
        if (&other == this)
            return *this;

        delete[] pointer;

        pointer = other.pointer;
        other.pointer = nullptr;

        std::cout << "SmartPointer assigment move\n";
        return *this;
    }

    ~SmartPointer() 
    { 
        delete pointer; 
        std::cout << "SmartPointer destruct\n";
    }

    T& operator*() const { return *pointer; }
    T* operator->() const { return pointer; }

    T* GetPointer() { return pointer; }
};

class Resource
{
    int* ptr;
public:
    Resource() : ptr{ new int }
    {
        std::cout << "Resource construct\n";
    }

    Resource(int value) : ptr{ new int }
    {
        *ptr = value;
        std::cout << "Resource construct\n";
    }

    Resource(const Resource& other) : ptr{ new int }
    {
        *ptr = *other.ptr;
        std::cout << "Resource construct copy\n";
    }

    Resource& operator=(const Resource& other)
    {
        if (&other == this)
            return *this;

        delete ptr;
        ptr = new int;
        *ptr = *other.ptr;

        std::cout << "Resource assigment copy\n";
        return *this;
    }

    int& Value() { return *ptr; }

    ~Resource()
    {
        std::cout << "Resource destruct\n";
        delete ptr;
    }
};

template <typename T>
class ShareSmartPointer
{
    T* pointer;
    static int count;
public:
    ShareSmartPointer(T* pointer = nullptr)
        : pointer{ pointer } {}

    ShareSmartPointer(const ShareSmartPointer& other)
    {
        pointer = other.pointer;
        count++;
    }

    ShareSmartPointer(ShareSmartPointer&& other) noexcept
        : pointer{ other.pointer }
    {
        other.pointer = nullptr;
    }

    ShareSmartPointer& operator=(const ShareSmartPointer& other)
    {
        if (&other == this)
            return *this;

        delete[] pointer;

        pointer = other.pointer;
        count++;

        return *this;
    }

    ShareSmartPointer& operator=(ShareSmartPointer&& other) noexcept
    {
        if (&other == this)
            return *this;

        delete[] pointer;

        pointer = other.pointer;
        other.pointer = nullptr;

        return *this;
    }

    ~ShareSmartPointer()
    {
        if (count == 1)
            delete pointer;
        count--;
    }

    T& operator*() const { return *pointer; }
    T* operator->() const { return pointer; }

    T* GetPointer() { return pointer; }
};
