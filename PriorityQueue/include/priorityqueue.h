#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityItem
{
    private:

        int priority;
        T value;
        int pos;

    public:
        
        int getPriority();

        void setPriority(int p);

        T getValue();

        void setValue(const T value);

        int getPos();

        void setPos(const int p);
};

template<typename T>
class PriorityQueue
{
    private:

        int capacity;
        int dim;
        PriorityItem<T> *H;
        static int p(int i);
        static int l(int i);
        static int r(int i);
        static void swap(PriorityItem<T>* H, int i, int j);
        static void minHeapRestore(PriorityItem<T>* A, int i, int dim);

    public:

        PriorityQueue();
        // Default constructor

        ~PriorityQueue();
        // Destructor
        
        PriorityQueue(int n);
        // Creates a new priority queue
        
        bool isEmpty();
        // Returns true if empty

        T min();
        // Returns the element with the highest prioriy
        
        T deleteMin();
        // Returns and removes the element with the highest prioriy

        PriorityItem<T> insert(T x,int p);
        // Inserts the element x with priority p
        // Returns a Prority item reference that identifies x in the queue

        void decrease(PriorityItem<T>& x, int p);
        // Decreases the priority of x to p

        void decrease(T x, int p);
        // Decreases the priority of x to p

};

#include "../src/priorityqueue.cpp"

#endif
