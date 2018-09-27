#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QMap>
#include <QSet>

#include "Graph.h"

class Node
{
public:
    Node(const QString& name);

    const QString& getName() const;
    int getWeight(Node* neighbour) const;

    node_iterator nb_begin() const;
    node_iterator nb_end() const;

    friend class Graph;

private:
    void addNeighbour(Node* neighbour, int weight);
    void removeNeighbour(Node* neighbour);

private:
    QString     m_name;
    QSet<Node*> m_neighbours;
    QMap<Node*, int> m_weights;
};

#endif // NODE_H
