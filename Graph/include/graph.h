#ifndef GRAPH_H
#define GRAPH_H
#include "../Set/include/set.h"

template<typename T>
class Node
{
    private:

        T value;
        int weight;

    public:

        Node();
        // Default constructor 

        Node(T value);
        // Constructor for a node with unitary weight

        Node(T value, int weight);
        // Constructor for a weighted node
        
        void setValue(T value);
        // value setter
        
        T getValue();
        // value setter

        void setWeight(int value);
        // weight setter
        
        int getWeight();
        // weight setter
};

template<typename T>
class Edge
{
    private:

        Node<T> u, v;
        int weight;

    public:

        Node();
        // Default constructor 

        Node(Node<T> u, Node<T> v);
        // Constructor for an edge with unitary weight

        Node(Node<T> u, Node<T> v, int weight);
        // Constructor for a weighted edge
        
        void setFirstNode(Node<T> u);
        // first node setter
        
        void setSecondNode(Node<T> u);
        // second node setter
       
        Node<T> getFirstNode();
        // first node getter
        
        Node<T> getSecondNode();
        // second node getter

        void setWeight(int value);
        // weight setter
        
        int getWeight();
        // weight setter
};

template<typename T>
class Graph
{
    private:

        Set<Node<T>> nodes;
        Set<Edge<T>> edges;
       
    public:
        
        Graph();
        // default constructor; creates an empty graph

        bool insertNode(Node<T> u);
        // inserts a node in the graph, if absent, and returns true; returns false if the node is already present

        bool insertEdge(Node<T> u, Node<T> v);
        // inserts an edge in the graph, if absent, and returns true; returns false if the edge is already present

        bool insertEdge(Node<T> u, Node<T> v, bool oriented);
        // inserts an edge in the graph, if absent, and returns true; returns false if the edge is already present
        
        bool deleteNode(Node<T> u);
        // deletes a node in the graph, if present, and returns true; returns false if the node is already absent

        bool deleteEdge(Node<T> u);
        // deletes an edge in the graph, if present, and returns true; returns false if the edge is already absent

        Set<Node<T>> adj(Node<T> u);
        // Returns the set of the nodes adjacent to u

        Set<Node<T>> V();
        // Returns the set of all nodes in the graph;

};

#endif
