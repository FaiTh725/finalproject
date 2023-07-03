#ifndef VECTOR_H
#define VECTOR_H

#include "Student.h"

template<typename T>
class Vector
{

private:

    int size;
    T *arr;

public:

    Vector() :size(0), arr(nullptr) {}
    Vector(int s) { size = s; arr = new T[size]; /*for (int i = 0; i < size;i++) arr[i] = NULL;*/ }
    Vector(Vector<T> &other);
    ~Vector();

    T& operator[](int ind);
    Vector<T> operator=(Vector<T> other);
    //Vector<Student> operator =(Vector<Student> other);

    void PushBack(T value);
    void PushFront(T value);

    void PopBack();
    void PopFront();

    void Insert(T value,int ind);
    void Erase(int ind);

    int Size() { return size; }
    void Resize(int new_size);

    void Clear();

    void Show();

};


template<typename T>
Vector<T>::Vector(Vector<T> &other)
{
    size = other.Size();
    arr = new T[size];
    for (int i=0;i<size;i++)
    {
        arr[i] = other.arr[i];
    }
}

template<typename T>
Vector<T>::~Vector()
{
    delete arr;
}

template<typename T>
void Vector<T>::PushBack(T value)
{
    size++;
    T *new_arr = new T[size];

    for (int i=0;i<size-1;i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[size - 1] = value;
    arr = new_arr;

}


template<typename T>
void Vector<T>::PushFront(T value)
{
    size++;
    T* new_arr = new T[size];
    new_arr[0] = value;
    for (int i=1;i<size;i++)
    {
        new_arr[i] = arr[i - 1];
    }
    arr = new_arr;
}

template<typename T>
void Vector<T>::PopBack()
{
    if (size==0)
    {
        return;
    }
    size--;

}

template<typename T>
void Vector<T>::PopFront()
{
    if (size==0)
    {
        return;
    }
    T* new_arr = new T[size - 1];
    for (int i=1;i<size;i++)
    {
        new_arr[i - 1] = arr[i];
    }
    size--;
    arr = new_arr;

}


template<typename T>
void Vector<T>::Insert(T value, int ind)
{
    if (ind >= size || ind < 0)
    {
        return;
    }
    size++;
    T* new_arr = new T[size];
    for (int i = 0; i < ind; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[ind] = value;
    for (int i = ind + 1; i < size; i++)
    {
        new_arr[i] = arr[i - 1];
    }
    arr = new_arr;
}

template<typename T>
void Vector<T>::Erase(int ind)
{
    if (ind >= size || ind < 0)
    {
        return;
    }

    size--;
    T* new_arr = new T[size];

    for (int i = 0; i < ind; i++)
    {
        new_arr[i] = arr[i];
    }

    for (int i = ind + 1; i < size + 1; i++)
    {
        new_arr[i - 1] = arr[i];
    }

    arr = new_arr;
}


template<typename T>
void Vector<T>::Clear()
{
    size = 0;
    delete arr;
    arr = nullptr;
}

template<typename T>
void Vector<T>::Resize(int new_size)
{
    if (new_size < 0)
    {
        return;
    }

    T* new_arr = new T[new_size];

    if (new_size > size)
    {
        for (int i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }

        for (int i = size; i < new_size; i++)
        {
            new_arr[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < new_size; i++)
        {
            new_arr[i] = arr[i];
        }
    }


    size = new_size;
    arr = new_arr;
}



template<typename T>
T& Vector<T>::operator[](int ind)
{
    //if (size > ind) { return; }
    return arr[ind];
}

template<typename T>
Vector<T> Vector<T>::operator=(Vector<T> other)
{

    size = other.size;
    arr = new T[size];
    for (int i=0;i<size;i++)
    {
        arr[i] = other.arr[i];
    }
    return *this;
}

#endif // VECTOR_H
