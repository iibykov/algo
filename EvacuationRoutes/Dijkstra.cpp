#include "Dijkstra.h"
#include "Node.h"
#include "Graph.h"

#include <QMap>

Dijkstra::Dijkstra(const Graph &graph):
    m_graph(graph)
{}

Way Dijkstra::shortestWay(Node *start, Node *end)
{
    PriorityQueue nodes;
    nodes.push(start, 0, nullptr);

    QMap<Node*, MarkedNode> visited;
    while (!nodes.empty())
    {
        MarkedNode next = nodes.pop();
        visited[next.node] = next;

        if (end == next.node)
            return unroll(visited, start, end);

        for (node_iterator it = next.node->nb_begin();
             it != next.node->nb_end(); ++it)
        {
            int weight = (*it)->getWeight(next.node) + next.mark;

            if (visited.find(*it) == visited.end())
                nodes.push(*it, weight, next.node);
        }
    }
    return Way();
}


Way Dijkstra::unroll(QMap<Node*, MarkedNode> visited, Node* start, Node* curr)
{
    Way way;
    way.length = visited[curr].mark;

    while (curr != start)
    {
        way.nodes.push_back(curr);
        curr = visited[curr].prev;
    }

    way.nodes.push_back(start);
    return way;
}

std::ostream &operator<<(std::ostream &out, Way &way)
{
    if (way.length < 0)
    {
        out << "Way not found";
    }
    else
    {
        out << "Length " << way.length << ": ";
        for (QVector<Node*>::iterator it = way.nodes.begin();
             it != way.nodes.end(); ++it)
        {
            out << (*it)->getName().toStdString() << " ";
        }
    }

    return out;
}

