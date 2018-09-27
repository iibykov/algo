#include "Graph.h"
#include "Node.h"

Graph::Graph()
{

}

void Graph::addNode(Node *node)
{
    m_nodes << node;
}

void Graph::removeNode(Node *node)
{
    for (QSet<Node*>::iterator it = m_nodes.begin();
         it != m_nodes.end(); it++)
    {
        (*it)->removeNeighbour(node);
    }
}

void Graph::addEdge(Node *begin, Node *end, int weight)
{
    if (m_nodes.find(begin) == m_nodes.end())
        return;
    if (m_nodes.find(end) == m_nodes.end())
        return;

    begin->addNeighbour(end, weight);
    end->addNeighbour(begin, weight);
}

void Graph::removeEdge(Node *begin, Node *end)
{
    begin->removeNeighbour(end);
    end->removeNeighbour(begin);
}

node_iterator Graph::begin() const
{
    return m_nodes.begin();
}

node_iterator Graph::end() const
{
    return m_nodes.end();
}
