#include <unordered_map>
#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <unordered_set>

Graph::Graph() {
    VertexCount = 0;
}

Graph::~Graph() {
    //delete all nodes of graph
    for (const auto& u: VertexMap) {
        delete u.second;
    }
}

GraphVertex* Graph::getVertex(std::string& UserName){
    if (VertexMap.find(UserName) != VertexMap.end()) return VertexMap[UserName];
    return nullptr;
}

void Graph::getPosts(std::string &UserName, int &N){
    GraphVertex* u = getVertex(UserName);
    if (u == nullptr) std::cout<<"INVALID INPUT: \""<<UserName<<"\" not found!\n\n";
    else if (N < -1) std::cout<<"INVALID INPUT: N is out of range\n\n";
    else u -> PrintPosts(N);
}

void Graph::PrintNeighbors(std::string& UserName){
    GraphVertex* u = getVertex(UserName);
    if (u == nullptr) {
        std::cout<<"INVALID INPUT: \""<<UserName<<"\" not found!\n\n";
        return;
    }

    const std::vector<std::string> names = u -> Neighbours();
    std::cout<<"\""<<UserName<<"\" has "<<names.size() <<" friends"<<"\n";
    int i = 0;
    for (const std::string& name : names) {
        std::cout << ++i << ". "<< name << "\n";
    }
    std::cout<<"\n\n";
}

std::vector<std::string> Graph::getNeighbors(std::string& UserName) {
    GraphVertex* u = getVertex(UserName);
    return u -> Neighbours();
}

void Graph::addVertex(std::string& UserName) {
    if (VertexMap.find(UserName) != VertexMap.end()) {
        std::cout << "\""<<UserName <<"\""<< " exists already\n\n";
        return;
    }
    
    GraphVertex* vertex = new GraphVertex(UserName);
    VertexMap[UserName] = vertex;
    VertexCount++;
    std::cout << "\""<<UserName << "\" added to network successfully!\n\n";
}

void Graph::AddPost(const std::string& UserName, std::string str) {
    if (VertexMap.find(UserName) != VertexMap.end()) {
        VertexMap[UserName]->addPost(str);
        std::cout << "Post added successfully" <<"\n\n";
    }
    else {
        std::cout<<"INVALID INPUT: \"" <<UserName<<"\" Not Found"<<"\n\n";
    }
}

void Graph::addEdge (std::string& UserName1,std::string & UserName2) {
    if (UserName1 == UserName2) {
        std::cout<<"INVALID INPUT: Both are the same persons\n\n";
        return;
    }
    GraphVertex* u = nullptr , * v = nullptr;
    if(VertexMap.find(UserName1) == VertexMap.end())
        std::cout<<"INVALID INPUT: \"" <<UserName1<< "\" not found!\n";
    else u = VertexMap[UserName1];

    if(VertexMap.find(UserName2) == VertexMap.end())
        std::cout<<"INVALID INPUT: \"" <<UserName2<< "\" not found!\n";
    else v = VertexMap[UserName2];

    if ((u != nullptr) and (v != nullptr)){
        u -> addNeighbor(v);
        v -> addNeighbor(u);
        std::cout<< "\"" << UserName1 <<"\" and \""<<UserName2<<"\" are now friends";
    }

    std::cout<<"\n\n";
}

int Graph::BFS(std::string &UserName1, std::string &UserName2){
    if (UserName1 == UserName2) return 0;
    GraphVertex* u = getVertex(UserName1);
    GraphVertex* v = getVertex(UserName2);
    if ((u == nullptr) or (v == nullptr)) return -1;

    std::unordered_set<std::string> passed;
    std::queue<std::pair<std::string,int>> q;
    q.emplace(UserName1,0);
    passed.emplace(UserName1);
    while (!q.empty()) {
        std::pair<std::string,int> p = q.front();
        q.pop();
        std::vector<std::string> neighbors = getNeighbors(p.first);
        for (std::string &neighbor : neighbors) {
            if (neighbor == UserName2) { //bfs successful
                return p.second+1;
            }
            if (passed.find(neighbor) == passed.end()) {
                passed.emplace(neighbor);
                q.emplace(neighbor, p.second+1);
            }
        }
    }
    return -1;//no path
}