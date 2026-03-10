#include<iostream>
#include "SocialNet.hpp"

using namespace std;

void lowerit(std::string& str) { //converts all upper case letters to lower case
    for (auto& i : str) {
        if ( i >= 'A' && i <= 'Z' )
            i = (char)(i-'A' +'a');
    }
}

int main() {
    std::cout<<"Welcome to the Fakebook"<<'\n';
    std::cout<<"When you are done with your queries , enter \"!stop\" to terminate the program"<<'\n';
    SocialNet Fakebook; // makes an object of SocialNet class
    while (true) {
        std::string operation;
        std::cin >> operation;
        if (operation == "!stop") {
            std::cout<<"Goodbye!"<<'\n';
            break;
        }

        if (operation == "ADD_USER") {
            std::string username;
            std::cin >> username;
            lowerit(username);
            Fakebook.ADD_USER(username);
        }

        else if (operation == "ADD_FRIEND") {
            std::string username1;
            std::string username2;
            std::cin >> username1 >> username2;
            lowerit(username1);
            lowerit(username2);
            Fakebook.ADD_FRIEND(username1, username2);
        }

        else if (operation == "LIST_FRIENDS") {
            std::string username;
            std::cin >> username;
            lowerit(username);
            Fakebook.LIST_FRIENDS(username);
        }

        else if (operation == "SUGGEST_FRIENDS") {
            std::string username;
            int N;
            std::cin >> username;
            std::cin >> N;
            lowerit(username);
            Fakebook.SUGGEST_FRIENDS(username, N);
        }

        else if (operation == "DEGREES_OF_SEPARATION") {
            std::string username1;
            std::string username2;
            std::cin >> username1 >> username2;
            lowerit(username1);
            lowerit(username2);
            Fakebook.DEGREES_OF_SEPARATION(username1, username2);
        }

        else if (operation == "ADD_POST") {
            std::string username;
            std::string PostContent;
            std::cin >> username;
            // This reads the entire rest of the line.
            // std::ws skips the leftover newline from std::cin.
            std::getline(std::cin >> std::ws, PostContent);
            lowerit(username);
            Fakebook.ADD_POST(username, PostContent);
        }

        else if (operation == "OUTPUT_POSTS") {
            std::string username;
            int N;
            std::cin >> username;
            std::cin >> N;
            lowerit(username);
            Fakebook.OUTPUT_POST(username, N);
        }

        else {
            std::cout<<"INVALID OPERATION\n\n";
        }
    }
}