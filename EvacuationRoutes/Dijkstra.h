#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include "PriorityQueue.h"

#include <QVector>

class Node;

struct Way
{
    Way() : length(-1) {}

    Way &operator+= (const Way& rhs)
    {
        this->nodes += rhs.nodes;
        this->length += rhs.length;

        return *this;
    }

    friend Way operator+(Way lhs, const Way& rhs)
    {
        lhs += rhs;
        return lhs;
    }

    bool operator<(const Way &rhs) const { return length < rhs.length; }

    QVector<Node*> nodes;
    int length;
};


std::ostream& operator<<(std::ostream& out, Way& way);

class Dijkstra
{
public:
    Dijkstra(const Graph& graph);
    Way shortestWay(Node* start, Node* end);

private:
    static Way unroll(QMap<Node*, MarkedNode> visited, Node *start, Node *curr);

private:
    const Graph& m_graph;
};

#endif // DIJKSTRA_H
