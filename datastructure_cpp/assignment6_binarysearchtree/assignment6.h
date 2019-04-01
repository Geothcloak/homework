//Justin Roesner
//z1858242
//csci 340
//assignement  6 header file
//due 3/27/19

#ifndef ASSIGNMENT6
#define ASSIGNMENT6
#include "assignment5.cc"

class BST : public binTree {
    public:
        BST() : binTree() {}
        void insert( int );
        bool search( int );
        bool remove( int );
        int sumLeaves();
    private:
        void insert( Node*&, int );
        bool search( Node*&, int );
        bool remove( Node*&, int );
        int sumLeaves(Node*&);
};

//private function insert that calls the public insert
void BST::insert(int x) {
    insert(root, x);
}

//private function search that calls the public search
bool BST::search(int x) {
    return search(root, x);
}

//private remove insert that calls the public remove
bool BST::remove(int x) {
    return remove(root, x);
}

//private function sumLeaves that calls the public sumLeaves
int BST::sumLeaves() {
    return sumLeaves(root);
}

#endif
