#include "AVLnodePosts.hpp"

AVLnodePosts::AVLnodePosts(const std::string & d , const int k) {
    data = d;
    key = k;
    left = right = nullptr;
    height = 0;
}

int AVLnodePosts::getKey() const {
    return key;
}

std::string AVLnodePosts::getData() const{
    return data;
}