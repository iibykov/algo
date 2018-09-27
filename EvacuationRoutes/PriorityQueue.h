#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <QVector>

class Node;

struct MarkedNode
{
    MarkedNode(Node* anode = 0, int amark = 0, Node* aprev = 0):
        node(anode), mark(amark), prev(aprev) {}

    Node* node;
    int mark;
    Node* prev;
};


class PriorityQueue
{
public:
     MarkedNode pop();
     void push(Node* node, int mark, Node* prev);
     bool empty() const;

private:
     QVector<MarkedNode> m_nodes;
};

#endif // PRIORITYQUEUE_H
