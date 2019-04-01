//Justin Roesner
//z1858242
//csci 340
//assignement 6 public functions
//due 3/27/19

#include <iostream>
#include "assignment5.cc"
#include "assignment6.h"
using namespace std;

//insert into BST
void BST::insert(Node *& node, int key) {
    //if node is not null continue
    if (node != NULL){
        //if key is less than data in current node go left
        if (key < node->data){
            insert(node->left, key);
        }
        //if key is greater than data in current node go right
        else if (key > node->data){
            insert(node->right, key);
        }
    }
    else{
        //node is null here so assign a new node with the key
        Node* newNode = new Node;
        node = newNode;
        newNode->data = key;
    }
}

//search the bst return true or false if found
bool BST::search(Node *& node, int key) {
    //if current node is null return false
    if (node == NULL){
        return false;
    }
    //if node we are on == key return true
    if (node->data == key){
        return true;
    }
    //if data is less than key search the right side
    if (node->data < key){
        return search(node->right, key);
    }
    //if data is greater than key search the left side
    else{
        return search(node->left, key);
    }
}

//remove a node from the bst
bool BST::remove(Node *& node, int key) {
    //node == NULL return false
    if (!node) {
        return false;
    }
    //if data is greater than key traverse left
    if (node->data > key){
        remove(node->left, key);
    }
    //if data is less than key traverse right
    if (node->data < key){
        remove(node->right, key);
    }
    //if we find the node but the node has both children
    if (node->left != NULL && node->right != NULL){
        // find n's immediate predcessor
        Node*& temp = node;

        temp = temp->left;
        while (temp->right != NULL){
                temp = temp->right;
        }

        //copy pred's data to n
        node->data = temp->data;

        //recursive call to remove (n left link, preds data
        remove(temp, temp->data);
        return true;

    }
    //if we find the node and it is a leaf
    else if (node->left == NULL && node->right == NULL){
        //delete n
        node->data = 0;
        // n = null
        node = NULL;
        return true;
    }
    //if we find the node and it has only one child
    else{
            Node*& temp = node;

            if (node->left != NULL){
                node = temp->left;
            }
            else{
                node = temp->right;
            }
            temp = NULL;
            return true;
        }
    }

//sum the leaves inside bst
int BST::sumLeaves(Node *& node) {
    int sum = 0;

    //if we are at a leaf return the leafs data
    if (node->left != NULL && node->right != NULL){
        sum = node->data;
        return sum;
    }
    //if we have a left child traverse left
    if (node->left != NULL){
        sum += sumLeaves(node->left);
    }
    //if we have a right child traverse right
    if (node->right != NULL){
        sum += sumLeaves(node->right);
    }
    return sum;
}

//assignment 5 bintree definitions
/*
binTree::binTree(){
    root=NULL;
}

//find the size of the tree
unsigned binTree::size(Node* node) const{
    if (node == NULL)
        return 0;
    else{
        return(size(node->left) + 1 + size(node->right));
    }
}

//find the height of the tree
unsigned binTree::height(Node* node) const{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int left = height(node->left);
        int right = height(node->right);

        if (left > right)
        {
            return (left +1);
        }
        else
        {
            return (right + 1);
        }

    }
}

//insert a new node into the tree

void binTree::insert(Node*& node, int key){
    if(key < node->data){
        if(node->left != NULL){
            insert(node->left, key);
        }
        else
        {
            node->left = new Node;
            node->left->data=key;
            node->left->left=NULL;
            node->left->right=NULL;
        }
    }
    else if(key >= node->data)
    {
        if(node->right != NULL)
        {
            insert(node->right, key);
        }
        else
        {
            node->right = new Node;
            node->right->data = key;
            node->right->left = NULL;
            node->right->right = NULL;
        }
    }
}


//inorder traversal
void binTree::inorder(Node *current, void(* visit)(int)){
    if (current != NULL)
    {
        inorder(current->left, visit);
        cout << current->data;
        inorder(current->right, visit);
    }
}

//preorder traversal
void binTree::preorder(Node *current, void(* visit)(int)){
    if (current != NULL)
    {
        cout << current->data;
        preorder(current->left, visit);
        preorder(current->right, visit);
    }
}

//postorder traversal
void binTree::postorder(Node *current, void(* visit)(int)){
    if (current != NULL)
    {
        postorder(current->left, visit);
        postorder(current->right, visit);
        cout << current->data;
    }
}
 */