#pragma once
#include <unordered_map> //implemented with hash tables
#include "GraphVertex.hpp"

class Graph {
private:
    int VertexCount;
    std::unordered_map<std::string , GraphVertex*> VertexMap;
public:
    Graph();
    ~Graph();

    GraphVertex* getVertex(std::string &UserName) ;//give the vertex element corresponding to username
    void getPosts(std::string &UserName , int &N) ; // prints last N posts of user , if they have N much
    void PrintNeighbors(std::string &UserName) ; //prints sorted list of neighbours of username
    std::vector<std::string> getNeighbors(std::string &UserName);//give a sorted list of neighbours of username
    void addVertex(std::string &UserName);//add a vertex element with data as username
    void AddPost(const std::string &UserName, std::string str);
    void addEdge(std::string& UserName1,std::string & UserName2);//applies friendship in between username1 and username 2
    int BFS(std::string &UserName1,std::string &UserName2);//to get the shortest Distance
    //delete vertex is not needed for this assignment
};