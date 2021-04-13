#ifndef SHAREPOINTER_H
#define SHAREPOINTER_H

#include <cstdlib>
#include "Pointer.h"
#include "Exception.h"

namespace DataLib
{

template < typename T >
class SharePointer : public Pointer<T>
{
protected:
    int* m_ref;

    void assign(const SharePointer<T>& obj)
    {
        this->m_ref = obj.m_ref;
        this->m_pointer = obj.m_pointer;

        if(this->m_ref)
        {
            (*this->m_ref)++;
        }
    }

public:
    SharePointer(T* p = NULL) : m_ref(NULL)
    {
        if(p)
        {
            this->m_ref = static_cast<int*>(std::malloc(sizeof(int)));

            if(this->m_ref)
            {
                *(this->m_ref) = 1;
                this->m_pointer = p;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create SharePointer obj...");
            }
        }
    }

    SharePointer(const SharePointer<T>& obj) : Pointer<T>(NULL)
    {
        assign(obj);
    }

    SharePointer<T>& operator = (const SharePointer<T>& obj)
    {
        if(this != &obj)
        {
            clear();

            assign(obj);
        }

        return *this;
    }

    void clear()
    {
        T* toDel = this->m_pointer;
        int *ref = this->m_ref;

        this->m_pointer = NULL;
        this->m_ref = NULL;

        if(ref)
        {
            (*ref)--;

            if(*ref == 0)
            {
                free(ref);

                delete toDel;
            }
        }
    }

    ~SharePointer()
    {
        clear();
    }
};

template < typename T >
bool operator == (const SharePointer<T>& l, const SharePointer<T>& r)
{
    return (l.get() == r.get());
}

template < typename T >
bool operator != (const SharePointer<T>& l, const SharePointer<T>& r)
{
    return !(l == r);
}

}

#endif // SHAREPOINTER_H
