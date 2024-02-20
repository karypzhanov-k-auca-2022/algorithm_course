#include "Graph.h"

void Graph::addPath(int x, int y) {
    path[x].push_back(y);
    path[y].push_back(x);
}