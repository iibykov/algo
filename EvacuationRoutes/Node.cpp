#include "Node.h"


Node::Node(const QString &name) :
    m_name(name)
{}

const QString &Node::getName() const
{
    return m_name;
}

int Node::getWeight(Node *neighbour) const
{
    if (m_weights.find(neighbour) == m_weights.end())
        return -1;

    return m_weights[neighbour];
}

node_iterator Node::nb_begin() const
{
    return m_neighbours.begin();
}

node_iterator Node::nb_end() const
{
    return m_neighbours.end();
}

void Node::addNeighbour(Node *neighbour, int weight)
{
    m_neighbours << neighbour;
    m_weights[neighbour] = weight;
}

void Node::removeNeighbour(Node *neighbour)
{
    m_neighbours.remove(neighbour);
    m_weights.remove(neighbour);
}
