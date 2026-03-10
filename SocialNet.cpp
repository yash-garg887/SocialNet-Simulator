#include "SocialNet.hpp"
#include <algorithm>
#include<iostream>
#include <unordered_set>

SocialNet::SocialNet() {
    graph = new Graph();
}

SocialNet::~SocialNet() {
    delete graph;
}

void SocialNet::ADD_USER(std::string &username) {
    graph -> addVertex(username);
}

void SocialNet::ADD_FRIEND(std::string &UserName1, std::string &UserName2) {
    graph -> addEdge(UserName1, UserName2);
}

void SocialNet::LIST_FRIENDS(std::string& UserName) {
    graph -> PrintNeighbors(UserName);
}

void SocialNet::SUGGEST_FRIENDS(std::string &UserName, int N) {
    //its friend's friends

    GraphVertex* user = graph -> getVertex(UserName);
    if (user == nullptr) {
        std::cout<<"INVALID INPUT: \""<<UserName<<"\" not found!\n\n";
        return;
    }

    if (N < 0) {
        std::cout << "INVALID INPUT: N is out of range!\n\n";
        return;
    }

    std::cout<<"Suggestions are:\n";

    if (N == 0) {
        std::cout<<"\n";
        return;
    }

    std::vector<std::pair<int , std::string>> recommendations;//first is mutuals
    std::unordered_set<std::string> recommended;
    //first make a list of user's friends
    std::unordered_set<std::string> friends_set;
    std::vector<std::string> friends_list = graph -> getNeighbors(UserName);
    for (const std::string& name : friends_list) {
        friends_set.insert(name);
    }

    //now traverse over friends list and check their friends
    for (std::string &name : friends_list) {
        //get its friends , then check their friends , count the number of elements common
        //in between their friends and set friends

        std::vector<std::string> f_friends = graph -> getNeighbors(name);

        //now traverse this f_friend's friends to get mutual count
        for (std::string& name2: f_friends) {
            if (friends_set.find(name2) != friends_set.end()) continue;//is already friend
            if (name2 == UserName) continue;
            if (recommended.find(name2) != recommended.end()) continue;
            std::vector<std::string> f_f_friends = graph -> getNeighbors(name2);
            int mutual = 0;
            for (std::string &name3 : f_f_friends)
                mutual += (friends_set.find(name3) != friends_set.end());
            recommendations.emplace_back(mutual, name2);
            recommended.insert(name2);
        }
    }

    std::sort(recommendations.begin(), recommendations.end(), [](const auto& a, const auto& b){
    // 1. Prioritize the mutual friends number
    if (a.first != b.first)
        return a.first > b.first; // Ascending integer order

    // 2. If equal number of mutual friends, use the names (a.second)
    return a.second < b.second; // Ascending alphabetical order
        });

    int m  = (N <= recommendations.size() ? N : recommendations.size());
    // int m  = std::min(recommendations.size() ,N);
    for (int i = 0; i < m; i++)
        std::cout << i+1 <<". \""<<recommendations[i].second <<"\" ("<<recommendations[i].first<< " mutual friends)\n";
    std::cout<<"\n\n";
}

void SocialNet::DEGREES_OF_SEPARATION(std::string &UserName1, std::string &UserName2) const {
    int num = graph ->BFS(UserName1,UserName2);
    if (num == -1) std::cout<<"-1\n\n";
    else {
        std::cout << "\"" <<UserName1 <<"\" and \"" <<UserName2 <<"\" are "<<num<<" distance apart\n\n";
    }
}

void SocialNet::ADD_POST(std::string &username, std::string &post_content) {
    graph -> AddPost(username , post_content);
}

void SocialNet::OUTPUT_POST(std::string &username, int N) {
    graph -> getPosts(username,N);
}