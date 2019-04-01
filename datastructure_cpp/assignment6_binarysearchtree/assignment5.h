//Justin Roesner
//z1858242
//csci 340
//assignement 5 header file
//due 3/15/19

#ifndef ASSIGNMENT5
#define ASSIGNMENT5

class binTree;
/*
class BST{
    friend class Node;
};
 */

//node that holds data
class Node {
    public:
        int data;
        Node *left;
        Node *right;

    friend class binTree;
};

class binTree {
    public:
        binTree();
        virtual void insert( int );
        unsigned height() const;
        unsigned size() const;
        void inorder( void(*)(int) );
        void preorder( void(*)(int) );
        void postorder( void(*)(int) );

    protected:
        Node* root;

    private:
        void insert( Node*&, int );
        unsigned height( Node* ) const;
        unsigned size( Node* ) const;
        void inorder( Node*, void(*)(int) );
        void preorder( Node*, void(*)(int) );
        void postorder( Node*, void(*)(int) );
};

//insert new node into tree

void binTree::insert(int key){
	if(root != NULL)
	{
		insert(root, key);
	}
	else
	{
		root = new Node();
		root->data = key;
		root->left = NULL;
		root->right = NULL;
	}
}

//call the private function from this one
unsigned binTree::size() const{
    return size(root);
}

//call the private function from this one
unsigned binTree::height() const{
    return height(root);
}

//call the private function from this one
void binTree::inorder( void(* visit)(int) ){
    inorder(root, visit);
}

//call the private function from this one
void binTree::preorder( void(* visit)(int) ){
    preorder(root, visit);
}

//call the private function from this one
void binTree::postorder( void(* visit)(int) ){
    postorder(root, visit);
}

#endif
