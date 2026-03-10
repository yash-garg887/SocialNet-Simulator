#include "GraphVertex.hpp"
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

GraphVertex::GraphVertex(std::string& d) {
    data = d;
    post_cnt= 0;
    neighbour_cnt = 0;
    neighbours = new AVLtree<AVLnodeAdjacency , GraphVertex* , std:: string>();
    posts = new AVLtree<AVLnodePosts , std:: string , int>();
}

GraphVertex::~GraphVertex() {
    delete neighbours;
    delete posts;
}

std::string GraphVertex::getData() {
    return data;
}

void GraphVertex::addNeighbor(GraphVertex* v) {
    AVLnodeAdjacency* temp = new AVLnodeAdjacency(v);
    neighbours -> insert(temp);
    neighbour_cnt ++;
}

void GraphVertex::addPost(std::string content) {
    post_cnt ++;
    AVLnodePosts* post = new AVLnodePosts(content , -post_cnt);
    posts -> insert(post);
}

bool GraphVertex::is_adjacent_to(GraphVertex* u){
    //go in avl tree to search whether a node exists with
    std:: string d = u->getData();
    return neighbours -> search(d);
}

std::vector<std::string> GraphVertex :: Neighbours(){
    std::vector<GraphVertex*> vertex = neighbours -> inorderTraversal(neighbour_cnt);
    //fetch their names
    vector<std::string> names;
    for ( auto v : vertex) {
        names.push_back(v->getData());
    }
    return names;//sorted
}

void GraphVertex::PrintPosts(int &N) {
    if(N == -1) N = post_cnt;//output all posts
    const std::vector<std::string> Posts = posts -> inorderTraversal(N);
    int i = 1;
    std::cout <<"\""<<data<<"\" has total " <<post_cnt<< " posts!, out of which last "<<min(N,post_cnt) << " posts are\n";
    for (const auto& str : Posts) {
        cout <<i++ <<". " <<str << '\n';
    }
    cout << "\n\n";
}