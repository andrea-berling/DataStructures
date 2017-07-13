#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "../../List/include/List.h"

template<typename T>
class Dequeue
{
    private:

        List<T> l;

    public:

        bool empty();
        // Returns true if empty
        
        void push(T v);
        // Pushes v on top of the dequeue
        
        void push_back(T v);
        // Pushes v at the end of the dequeue

        T pop();
        // Pops the element on top

        T pop_last();
        // Pops the element at the end

        T& top();
        // Returns the element on top

        T& last();
        // Returns the element at the end
};

#include "../src/dequeue.cpp"
#endif
