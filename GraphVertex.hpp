#pragma once

#include <string>
#include "AVLnodeAdjacency.hpp"
#include "AVLnodePosts.hpp"
#include "AVLtree.hpp"

class GraphVertex {
private:
    std::string data; //name
    int post_cnt;//total posts count
    int neighbour_cnt;//total friends count
    AVLtree<AVLnodeAdjacency, GraphVertex *, std::string> * neighbours; //AVL tree storing all friends
    AVLtree<AVLnodePosts , std :: string , int>* posts;//AVL tree storing the neighbours

public:
    //member functions
    GraphVertex(std::string &d);
    ~GraphVertex();

    std::string getData() ;
    void addNeighbor(GraphVertex* v);
    void addPost(std::string content);
    bool is_adjacent_to(GraphVertex* u) ;//check if it is adjacent to u , not needed for this assignment
    std::vector<std::string> Neighbours() ; // gives a sorted list as per requirement specified of names of its friends
    void PrintPosts(int& N) ; // prints last N posts
};