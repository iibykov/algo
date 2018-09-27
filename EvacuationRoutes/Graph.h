#ifndef GRAPH_H
#define GRAPH_H

#include<QSet>

class Node;

typedef QSet<Node*>::const_iterator node_iterator;

class Graph
{
public:
    Graph();

    void addNode(Node* node);
    void removeNode(Node* node);

    void addEdge(Node* begin, Node* end, int weight = 1);
    void removeEdge(Node* begin, Node* end);

    node_iterator begin() const;
    node_iterator end() const;

private:
    QSet<Node*> m_nodes;
};

#endif // GRAPH_H
