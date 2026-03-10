#pragma once
#include <string>

class GraphVertex;

struct AVLnodeAdjacency {//to store the adjacent vertices of a vertex
    std::string key; //name of the neighbour
    GraphVertex* data;

    int height;
    AVLnodeAdjacency * left;
    AVLnodeAdjacency * right;

    AVLnodeAdjacency(GraphVertex* d);

    std::string getKey() const;
    GraphVertex *getData() const;
};