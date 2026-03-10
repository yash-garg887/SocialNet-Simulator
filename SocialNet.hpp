#pragma once
#include "Graph.hpp"

//this should make a Graph object within itself
//and should support all the query functions

class SocialNet {
    Graph* graph; //maintains network as a graph
public:
    SocialNet();
    ~SocialNet();

    void ADD_USER(std::string &username);
    void ADD_FRIEND(std::string& username1,std::string & username2);
    void LIST_FRIENDS(std::string &username);

    void SUGGEST_FRIENDS(std::string& UserName,int N);
    
    void DEGREES_OF_SEPARATION(std::string &UserName1, std::string &UserName2) const;

    void ADD_POST (std::string & username, std::string & post_content);
    void OUTPUT_POST(std::string &username, int N);
};