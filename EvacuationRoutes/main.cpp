#include <iostream>

#include "Node.h"
#include "Dijkstra.h"
#include "Yen.h"

int main()
{
    Node n0("n0"), n1("n1"), n2("n2"), n3("n3"), n4("n4"), n5("n5");

    Graph graph;

    graph.addNode(&n0);
    graph.addNode(&n1);
    graph.addNode(&n2);
    graph.addNode(&n3);
    graph.addNode(&n4);
    graph.addNode(&n5);

    graph.addEdge(&n0, &n1, 10);
    graph.addEdge(&n0, &n2, 20);
    graph.addEdge(&n1, &n3, 10);
    graph.addEdge(&n2, &n4, 25);
    graph.addEdge(&n3, &n4, 1);
    graph.addEdge(&n3, &n5, 17);
    graph.addEdge(&n4, &n5, 20);
    graph.addEdge(&n0, &n5, 39);

    Dijkstra dkstr(graph);
    Way shortest = dkstr.shortestWay(&n0, &n5);
    std::cout << "Dijkstra: ";
    std::cout << shortest << std::endl;

    Yen yen(graph);
    QVector<Way> ways = yen.shortestWays(&n0, &n5, shortest, 2);
    std::cout << "Yen: ";
    foreach (Way way, ways)
    {
        std::cout << way << std::endl;
    }

    return 0;
}
