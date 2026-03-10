#pragma once

#include <vector>

template<typename Nodetype , typename Datatype , typename Keytype >//keytype is for search property
class AVLtree {
private:
    Nodetype* root;

    int getHeight(Nodetype* v);
    int getBalance(Nodetype* v);
    Datatype getData(Nodetype* v);//return data stored in the vertex element of v
    Nodetype* RightRotate(Nodetype* n) ;
    Nodetype* LeftRotate(Nodetype* n);
    Nodetype* insertHelper(Nodetype* node , Nodetype* to_insert);
    void deleteTree(Nodetype* node);//recursive
    void inorderHelper(Nodetype *node, std::vector<Datatype> &data, int & N);
    //we are not deleting anything so no need to implement delete
public:
    AVLtree();
    ~AVLtree();
    void insert(Nodetype* d);
    bool search(Keytype key);//searches if there is a node with data d
    std::vector<Datatype> inorderTraversal(int N);//to get first N elements of inorder traversal
};

#include "AVLtree.tpp"