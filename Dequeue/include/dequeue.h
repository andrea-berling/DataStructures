#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "../../List/include/List.h"

template<typename T>
class Dequeue
{
    private:

        List<T> l;

    public:

        bool empty() const;
        // Returns true if empty
        
        void push(const T v) const;
        // Pushes v on top of the dequeue
        
        void push_back(const T v) const;
        // Pushes v at the end of the dequeue

        T pop() const;
        // Pops the element on top

        T pop_last() const;
        // Pops the element at the end

        T& top() const;
        // Returns the element on top

        T& last() const;
        // Returns the element at the end
};

#include "../src/dequeue.cpp"
#endif
