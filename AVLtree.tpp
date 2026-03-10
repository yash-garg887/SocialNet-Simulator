#pragma once
#include <iostream>
#include <vector>

//private members
template<typename Nodetype , typename Datatype , typename Keytype>
int AVLtree<Nodetype , Datatype , Keytype >::getHeight(Nodetype *v) {
    if (v == nullptr) return -1;
    return v -> height;
}

template<typename Nodetype , typename Datatype , typename Keytype>
int AVLtree<Nodetype , Datatype , Keytype >::getBalance(Nodetype *v) {
    if (v == nullptr) return 0;
    return getHeight(v->left) - getHeight(v->right);
}

template<typename Nodetype , typename Datatype , typename Keytype>
Datatype AVLtree<Nodetype , Datatype , Keytype >::getData(Nodetype *v) {
    return v -> getData();
}

template<typename Nodetype , typename Datatype , typename Keytype>
Nodetype* AVLtree<Nodetype,Datatype,Keytype>::RightRotate(Nodetype* n) {{
        Nodetype* l = n->left;
        Nodetype* T2 = l -> right;

        l -> right = n;
        n -> left = T2;

        n -> height = 1 + std::max(getHeight(n->left), getHeight(n->right));
        l -> height = 1 + std::max(getHeight(l->left), getHeight(l->right));

        return l;
    }
}

template<typename Nodetype , typename Datatype , typename Keytype>
Nodetype* AVLtree<Nodetype , Datatype , Keytype >::LeftRotate(Nodetype* n) {
    Nodetype* r = n->right;
    Nodetype* T2 = r->left;

    r->left = n;
    n -> right = T2;

    n -> height = 1 + std::max(getHeight(n->left), getHeight(n->right));
    r -> height = 1 + std::max(getHeight(r->left), getHeight(r->right));

    return r;
}

template<typename Nodetype , typename Datatype , typename Keytype>
Nodetype* AVLtree<Nodetype , Datatype , Keytype >::insertHelper(Nodetype *node, Nodetype *to_insert) {
    if (node == nullptr) return to_insert;
    Keytype k1 = node -> getKey();
    Keytype k2 = to_insert -> getKey();
    if (k1 < k2){
        node -> right = insertHelper(node->right, to_insert);
    }

    else if (k1 > k2) {
        node -> left = insertHelper(node->left, to_insert);
    }

    else return node;

    node-> height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    const int balance = getBalance(node);

    if (balance > 1) {//left heavy
        if (getBalance(node->left) >= 0)
            return RightRotate(node);
        node -> left = LeftRotate(node -> left);
        return RightRotate(node);
    }
    if (balance < -1) {
        if (getBalance(node->right) <= 0) return LeftRotate(node);
        node -> right = RightRotate(node -> right);
        return LeftRotate(node);
    }

    return node;
}



template<typename Nodetype , typename Datatype , typename Keytype>
void AVLtree<Nodetype , Datatype , Keytype >::inorderHelper(Nodetype *node,std::vector<Datatype>& traversal , int& N) {
    if ((node == nullptr) or (N == 0)) return;
    inorderHelper(node->left,traversal,N);
    if (N > 0) {
        traversal.push_back(node -> getData());
        N--;
    }
    if (N > 0) inorderHelper(node->right,traversal,N);
}

template<typename Nodetype , typename Datatype , typename Keytype>
void AVLtree<Nodetype , Datatype , Keytype >::deleteTree(Nodetype *node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

//public members

template<typename Nodetype , typename Datatype , typename Keytype>
AVLtree<Nodetype , Datatype , Keytype >::AVLtree() {
    root = NULL;
}

template<typename Nodetype , typename Datatype , typename Keytype>
AVLtree<Nodetype , Datatype , Keytype >::~AVLtree(){
    deleteTree(root);
}

template<typename Nodetype , typename Datatype , typename Keytype>
void AVLtree<Nodetype , Datatype , Keytype >::insert(Nodetype* d) {
    root = insertHelper(root, d);
}

template<typename Nodetype , typename Datatype , typename Keytype>
bool AVLtree<Nodetype , Datatype , Keytype >::search(Keytype key) {
    Nodetype* cur = root;
    while (cur != nullptr) {
        Keytype k = cur -> getKey();
        if (k == key) return true;
        if (k > key)
            cur = cur -> left;
        else
            cur = cur -> right;
    }
    return false;
}

template<typename Nodetype , typename Datatype , typename Keytype>
std::vector<Datatype> AVLtree<Nodetype , Datatype , Keytype>::inorderTraversal(int N) {
    std::vector<Datatype> traversal = {};
    inorderHelper(root,traversal ,N);
    return traversal;
}