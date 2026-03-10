#pragma once
#include <string>

struct AVLnodePosts { //to store posts of a user
    std::string data;//post content
    int key; //negative of time to sort as per the reverse chronological order

    int height;
    AVLnodePosts * left;
    AVLnodePosts * right;

    AVLnodePosts(const std::string & d , int k);

    int getKey() const;
    std::string getData() const;
};