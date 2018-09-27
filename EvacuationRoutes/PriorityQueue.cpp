#include "PriorityQueue.h"


MarkedNode PriorityQueue::pop()
{
    MarkedNode marked = m_nodes.back();
    m_nodes.pop_back();
    return marked;
}

void PriorityQueue::push(Node *node, int mark, Node *prev)
{
    QVector<MarkedNode>::iterator it = m_nodes.begin();
    MarkedNode marked(node, mark, prev);

    // From higher to lower
    while (it != m_nodes.end() && mark < it->mark)
        it++;

    if (it == m_nodes.end())
        m_nodes.push_back(marked);
    else
        m_nodes.insert(it, marked);
}

bool PriorityQueue::empty() const
{
    return m_nodes.empty();
}
