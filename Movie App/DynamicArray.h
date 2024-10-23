//
// Created by Teodora Schiau on 22.03.2024.
//

#ifndef OOP_A4_5_916_SCHIAU_TEODORA_DYNAMICARRAY_H
#define OOP_A4_5_916_SCHIAU_TEODORA_DYNAMICARRAY_H
#pragma once
#include <cstdlib>

template <class TElem>
class DynamicArray{
private:
    TElem* elements;
    int size;
    int capacity;

    ///resize the capacity of the dynamic array
    void resize()
    {
        TElem* NewElements;
        this->capacity= this->capacity*2;
        NewElements = new TElem[this->capacity];
        for(int i=0;i<this->size;i++)
            NewElements[i]=this->elements[i];
        delete[] this->elements;
        this->elements = NewElements;
    }

public:
    ///constructor
    DynamicArray(){}

    ///constructor
    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        this->size =0;
        this->elements = new TElem[capacity];
    }

    ///destructor - destroys the elements of an dynamic array
    ~DynamicArray()
    {
        delete[] this->elements;
    }

    /// function that add an element to the dynamic array
    /// \param elem
    void add_element(const TElem& elem)
    {
        if(this->size == this->capacity)
            resize();
        this->elements[size]= elem;
        this->size++;
    }

    /// function that deletes an element being specified only the position of the element
    /// \param position of the element in the array
    void delete_element(int position)
    {
        int i;
        for(i=position;i<this->size-1;i++)
            this->elements[i]= this->elements[i+1];
        this->size--;
    }

    /// function that update the element of the array
    /// \param elem the new element
    /// \param position the position of the old element
    void update(const TElem& elem, int position)
    {
        this->elements[position]=elem;
    }

    /// function that returns the length of an array
    /// \return
    int get_size()
    {
        return this->size;
    }


    TElem& operator[](int position)
    {
        return this->elements[position];
    }

    DynamicArray& operator = (const DynamicArray &a){
        if(this == &a)
            return *this;

        memcpy(this->elements, a.elements, sizeof(TElem)*a.capacity);
        return *this;

    }
};
#endif //OOP_A4_5_916_SCHIAU_TEODORA_DYNAMICARRAY_H
