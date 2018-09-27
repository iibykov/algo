#include <QtAlgorithms>

#include "Yen.h"
#include "Node.h"


Yen::Yen(const Graph &graph):
    m_graph(graph)
{
}

// k : The number of shortest paths to find
QVector<Way> Yen::shortestWays(Node *start, Node *end, int k)
{
    // Determine the shortest path from the start to the end
    Dijkstra dijkstra(m_graph);
    Way shortest = dijkstra.shortestWay(start, end);

    return shortestWays(start, end, shortest, k);
}

QVector<Way> Yen::shortestWays(Node *start, Node *end, const Way &shortest, int k)
{
    Q_UNUSED(start);

    // Initialize the set to store the potential kth shortest path
    QVector<Way> ways, potentialWays;
    ways.push_back(shortest);

    for (int i = 0; i < k; ++i)
    {
        // The spur node ranges from the first node to the next to last node
        // in the previous k-shortest path
        for (int j = 0; j < ways[i].nodes.size() - 2; ++j)
        {
            // Spur node is retrieved from the previous k-shortest path
            Node *spurNode = ways[i].nodes[j];

            // The sequence of nodes from the source to the spur node of the previous k-shortest path
            QVector<Node*> rootPath(j + 1);
            qCopy( ways[i].nodes.begin(), ways[i].nodes.begin() + j, rootPath.begin());

            Graph graph = m_graph;
            QVector< QPair<Node*, Node*> > remotedEdges;
            foreach (Way way, ways)
            {
                // Remove the links that are part of the previous shortest paths which share the same root path
                if (qEqual(rootPath.begin(), rootPath.end(), way.nodes.begin()))
                {
                    graph.removeEdge(rootPath[j], rootPath[j + 1]);
                    remotedEdges << qMakePair(rootPath[j], rootPath[j + 1]);
                }
            }

            foreach (Node* node, rootPath)
            {
                if (node != spurNode)
                    graph.removeNode(node);
            }

            // Calculate the spur way from the spur node to the end node
            Dijkstra dijkstra(graph);
            Way spurWay = dijkstra.shortestWay(spurNode, end);
            Way totalWay = createWay(rootPath) + spurWay;

            // Add the potential k-shortest way to the heap.
            potentialWays << totalWay;

            // restore edges to Graph;
            // restore nodes in rootPath to Graph;
        }

        if (potentialWays.isEmpty())
            break;

        // Sort the potential k-shortest ways by length
        qSort(potentialWays.begin(), potentialWays.end());
        ways << potentialWays[0];
        potentialWays.remove(0);
    }

    return ways;
}

Way Yen::createWay(const QVector<Node *> &path)
{
    Way way;
    way.nodes = path;
    for(int i = 1; i < way.nodes.size(); ++i)
        way.length += way.nodes[i]->getWeight( way.nodes[i-1] );

    return way;
}

void Yen::restoreEdges(const QVector<QPair<Node *, Node *> > edges)
{
    for (int i = 0; i < edges.size(); ++i)
    {
        QPair<Node *, Node *> edge = edges[i];
        m_graph.addEdge(edge.first, edge.second);
    }
}
