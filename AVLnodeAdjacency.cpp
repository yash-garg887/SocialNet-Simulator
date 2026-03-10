#include "AVLnodeAdjacency.hpp"
#include "GraphVertex.hpp"

AVLnodeAdjacency::AVLnodeAdjacency(GraphVertex *d) : height(0), left(nullptr), right(nullptr) {
    data = d;
    key = d->getData();
}

std::string AVLnodeAdjacency::getKey() const{
    return key;
}

GraphVertex* AVLnodeAdjacency::getData() const{
    return data;
}