//Justin Roesner
//z1858242
//csci 340
//assignement 5 driver file
//due 3/15/19

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

#define BINTREE_MAIN
#ifdef BINTREE_MAIN

//default constructor for binTree
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

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}



int main() {

    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
