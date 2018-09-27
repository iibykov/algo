#ifndef YEN_H
#define YEN_H

#include <QPair>

#include "Graph.h"
#include "Dijkstra.h"

class Yen
{
public:
    Yen(const Graph& graph);
    QVector<Way> shortestWays(Node* start, Node* end, int k = 1);
    QVector<Way> shortestWays(Node* start, Node* end, const Way &shortest, int k = 1);

private:
    Way createWay(const QVector<Node*> &path);
    void restoreEdges(const QVector< QPair<Node*, Node*> > edges);

private:
    Graph m_graph;
};

#endif // YEN_H
