#ifndef PRIORITYQUEUE_CPP
#define PRIORITYQUEUE_CPP
#include "../include/priorityqueue.h"

template<typename T>
int PriorityQueue<T>::l(int i)
{
    return 2*i + 1;
}

template<typename T>
int PriorityQueue<T>::r(int i)
{
    return 2*i + 2;
}

template<typename T>
int PriorityQueue<T>::p(int i)
{
    if (i == 0)
        return 0;
    else
        return (i % 2 == 0 ? i/2 - 1 : i/2);
}

template<typename T>
void PriorityQueue<T>::swap(PriorityItem<T>* H, int i, int j)
{
    PriorityItem<T> tmp = H[i];
    H[i] = H[j];
    H[j] = tmp;
    H[i].setPos(i);
    H[j].setPos(j);
}

template<typename T>
void PriorityQueue<T>::minHeapRestore(PriorityItem<T>* A, int i, int dim)
{
    int min = i;
    if(PriorityQueue::l(i) < dim && A[PriorityQueue::l(i)].getPriority() < A[min].getPriority())
        min = PriorityQueue::l(i);
    if(PriorityQueue::r(i) < dim && A[PriorityQueue::r(i)].getPriority() < A[min].getPriority())
        min = PriorityQueue::r(i);
    if(i != min)
    {
        swap(A,i,min);
        minHeapRestore(A,min,dim);
    }
}

template<typename T>
int PriorityItem<T>::getPriority()
{
    return priority;
}

template<typename T>
void PriorityItem<T>::setPriority(int p)
{
    priority = p;
}

template<typename T>
T PriorityItem<T>::getValue()
{
    return value;
}

template<typename T>
void PriorityItem<T>::setValue(const T value)
{
    this->value = value;
}

template<typename T>
int PriorityItem<T>::getPos()
{
    return pos;
}

template<typename T>
void PriorityItem<T>::setPos(const int p)
{
    pos = p;
}

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
    H = nullptr;
    capacity = 0;
    dim = -1;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(int n)
{
    H = new PriorityItem<T>[n];
    capacity = n;
    dim = 0;
}
// Creates a new priority queue

template<typename T>
bool PriorityQueue<T>::isEmpty()
{
    return dim == 0;
}
// Returns true if empty

template<typename T>
T PriorityQueue<T>::min()
{
    if(dim > 0)
        return H[0].getValue();
    else
    {
        T uninitialized;
        return uninitialized;
    }
}
// Returns the element with the highest prioriy

template<typename T>
T PriorityQueue<T>::deleteMin()
{
    if(dim > 0)
    {
        swap(H,0,dim-1);
        dim--;
        minHeapRestore(H,0,dim);
        return H[dim].getValue();
    }
    else
    {
        T u;
        return u;
    }
}
// Returns and removes the element with the highest prioriy

template<typename T>
PriorityItem<T> PriorityQueue<T>::insert(T x,int p)
{
    if(dim < capacity)
    {
        H[dim].setValue(x);
        H[dim].setPriority(p);
        H[dim].setPos(dim);
        int i = dim;
        while(i > 0 && H[i].getPriority() < H[PriorityQueue::p(i)].getPriority())
        {
            swap(H, i, PriorityQueue::p(i));
            i = PriorityQueue::p(i);
        }
        dim++;
        return H[i];
    }
    else
    {
        PriorityItem<T> u;
        return u;
    }

}
// Inserts the element x with priority p
// Returns a Prority item reference that identifies x in the queue

template<typename T>
void PriorityQueue<T>::decrease(PriorityItem<T>& x, int p)
{
    if(p < x.getPriority())
    {
        H[x.getPos()].setPriority(p);
        int i = x.getPos();
        while(i > 0 && H[i].getPriority() < H[PriorityQueue::p(i)].getPriority())
        {
            swap(H,i,PriorityQueue::p(i));
            i = PriorityQueue::p(i);
        }
    }
}
// Decreases the priority of y to p

#endif
