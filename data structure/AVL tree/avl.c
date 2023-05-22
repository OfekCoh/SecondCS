
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

// Do not change this. You can use but do not touch.
int _max( int x, int y ){
    return (x < y) ? y : x;
}

// Do not change this. You can use but do not touch.
int _abs( int x ){
    return (x < 0) ? -x : x;
}

// Operations implementation
void submitters() // print submitters
{
	printf("name student1 : Ofek Cohen\n");
	printf("id student1: 319001533\n");
	printf("name student2 : Roy Vazana\n");
	printf("id student2: 209521152\n");
};

int getHeight(AVLNodePtr root) // return the height of the root or -1 if NULL
{
    if(root) return root->height;
    else return -1;
}

void adjustHeight(AVLNodePtr x)
{
    if(!x) return;
    x->height= (_max(getHeight(x->child[0]), getHeight(x->child[1]))) +1; //update the heights
}

AVLNodePtr RightRotate(AVLNodePtr x) // right rotates a node
{
    AVLNodePtr y=x->child[0]; // save the node
    y->parent=x->parent; // update the parent of y
    if(y->parent) y->parent->child[y->parent->child[1]==x] = y; // update the parent's child to be y
    x->child[0]= y->child[1]; // rotate the children
    if(x->child[0]) x->child[0]->parent=x; // update the parent of x's child
    y->child[1]=x; // rotate the children
    x->parent=y; // update the parent of x
    adjustHeight(x); //update the heights
    adjustHeight(y); //update the heights
    return y;
}

AVLNodePtr LeftRotate(AVLNodePtr x) // left rotate a node
{
    AVLNodePtr y=x->child[1]; // save the node
    y->parent=x->parent; // update the parent of y
    if(y->parent) y->parent->child[(y->parent->child[1])==x] = y; // update the parent's child to be y
    x->child[1]= y->child[0]; // rotate the children
    if(x->child[1]) x->child[1]->parent=x; // update the parent of x's child
    y->child[0]=x; // rotate the children
    x->parent=y; // update the parent of x
    adjustHeight(x); //update the heights
    adjustHeight(y); //update the heights
    return y;
}

AVLNodePtr avl_balance(AVLNodePtr root)
{
    if(!root) return NULL; // nothing to do
    AVLNodePtr temp;
    adjustHeight(root);
    if( _abs((getHeight(root->child[0]))-(getHeight(root->child[1])))<2) return root; // node is balanced
    else if( (getHeight(root->child[0])) < (getHeight(root->child[1])) ) // root is right heavy
    {
        temp= root->child[1];
        if((getHeight(temp->child[0])) > (getHeight(temp->child[1]))) temp=RightRotate(temp); // case 3: temp is left heavy
        return LeftRotate(root);
    }
    else // root is left heavy 
    {
        temp= root->child[0];
        if((getHeight(temp->child[0])) < (getHeight(temp->child[1]))) temp=LeftRotate(temp); // case 3: temp is right heavy
        return RightRotate(root);
    }
}

AVLNodePtr new_avl_node( int x, int y)
{
    AVLNodePtr new=(AVLNodePtr)malloc(sizeof(AVLNode));
    if(!new) return NULL;
    new->key=x;
    new->y=y;
    new->rank=0;
    new->height=0;
    new->parent=NULL;
    new->child[0]=NULL;
    new->child[1]=NULL;
    return new;
}

AVLNodePtr avl_insert( AVLNodePtr root, int x, int y )                                   
{
    if(!root) return new_avl_node(x,y); // theres no tree so we make a first node and return it
    if( x == root->key) return root; // if x exists dont add it
    else if( x > (root->key)) // need to go right
    {
        root->child[1]=avl_insert(root->child[1],x,y); //recursive call 
        root->child[1]->parent=root; // update the parent
        root->height= (root->child[1]->height) +1 ; // update the height
    }
    else // need to go left
    {
        root->child[0]=avl_insert(root->child[0],x,y); //recursive call 
        root->child[0]->parent=root; // update the parent
        root->height= (root->child[0]->height) +1; // update the height
    }
    return root=avl_balance(root); // need to mainten AVL terms
}

AVLNodePtr avl_search( AVLNodePtr root, int x , int y)
{
    if(!root) return NULL; // the node is not found
    if(root->key==x && root->y==y) return root; // we found the node 
    if ( x > root->key) return avl_search(root->child[1],x,y); // need to go right
    else return avl_search(root->child[0],x,y); // need to go left
}



void swap_min_delete (AVLNodePtr node, AVLNodePtr min) // swaps a node with the min and deletes it
{
    if(min->parent != node ) 
    {
        min->parent->child[0]=min->child[1]; // updates min parent
        if(min->child[1]) min->child[1]->parent=min->parent; // updates min's single child
        min->parent=node->parent; // update min's new parent
        if(min->parent) min->parent->child[min->parent->child[1]==node]=min; // update the right child of min's new parent
        min->child[0]=node->child[0]; // update min children
        if(min->child[0]) min->child[0]->parent=min; // update min to be the parent
        min->child[1]=node->child[1]; 
        min->child[1]->parent=min; 
    }
    else // min->parent = node
    {
        min->parent=node->parent;
        if(min->parent) min->parent->child[min->parent->child[1]==node]=min; // update the right child of min's new parent
        min->child[0]=node->child[0]; // update min child
        if(min->child[0]) min->child[0]->parent=min; // update min to be the parent
    }

    free(node); // delete the node
    return;
}

AVLNodePtr find_min( AVLNodePtr root) // return pointer to min node in tree
{
    if(!(root->child[0])) return root; // found the min
    return find_min(root->child[0]);
}

AVLNodePtr help_balance(AVLNodePtr root, int x) // find the node with key x and balance from it to the root
{
    if(root->key==x) return avl_balance(root); // found it
    else if(x>root->key) root->child[1]= help_balance(root->child[1],x); // need to go right
    else root->child[0]=help_balance(root->child[0],x); // need to go left
    return avl_balance(root);
}

AVLNodePtr avl_delete( AVLNodePtr root, int x, int y )
{
    int start_x=0; // save the node we need to start the balance from 
    AVLNodePtr node=avl_search(root,x,y), min, temp; 
    if(!node) return root; // if node doesnt exist
    if(node->height==0)  // node doesnt have kids 
    {
        if(node->parent==NULL) // the tree is just one node 
        {
            free(node);
            return NULL;
        }
        node->parent->child[node->parent->child[1]==node]=NULL; // update the father child to be null
        start_x=node->parent->key; // save the node
        free(node);
        return help_balance(root,start_x); // we will start balancing the tree from the parent and up
    }
    else if( !(node->child[0]) || !(node->child[1]) ) // node has only one child
    {
        if(node->child[0]) temp=node->child[0]; // temp = the existing child
        else temp=node->child[1];
        temp->parent=node->parent;  //update temp new parent
        if(node->parent) // node has a parent 
        {
            node->parent->child[node->parent->child[1]==node]=temp;
            start_x=node->parent->key;
            free(node);
            return help_balance(root,start_x); //balance the wanted path
        }
        else // temp is the new root
        {
            free(node);
            return temp;
        }
    }
    else // node has 2 children
    {
        min=find_min(node->child[1]); // find the min in right subtree
        if(min->child[1]) start_x=min->child[1]->key;  // we will start the balance from that x
        else if(min->parent != node) start_x=min->parent->key; // we wil start the balance from the old min parent
        else start_x= min->key;
        if(node==root) root=min;
        swap_min_delete(node,min); // swap and delete the node
        return help_balance(root,start_x); //balance the wanted path
    }
}

void delete_avl_tree( AVLNodePtr root )
{
    if(!root) return;
    delete_avl_tree(root->child[0]); // go left 
    delete_avl_tree(root->child[1]); // go right
    free(root);    
}

void keysInRange (AVLNodePtr root, int x1, int x2, int* count, int flag, AVLNodePtr* array) // inOrder run and check keys in range
{
    if(!root) return;
    keysInRange(root->child[0],x1,x2,count,flag,array);
    if(root->key >= x1 && root->key <= x2) 
    {
        if(flag) array[(*count)]=root; // flag says the array was made and ready to be filled
        (*count)++;
    }
    keysInRange(root->child[1],x1,x2,count,flag,array);
}

int delete_third( AVLNodePtr root, int x1, int x2 )
{
    int i,j,count=0; // counter of how many keys are in that range
    AVLNodePtr* array; // array that will hold all nodes that in range
    keysInRange(root,x1,x2,&count,0,array); // the func will fill the counter
    array=(AVLNodePtr*)malloc(count*sizeof(AVLNodePtr)); //malloc the array with correct size 
    keysInRange(root,x1,x2,&count,1,array); // the func will fill the array by sorted order of keys
    i=count/3; // we want to delete the middle third of the array so we start here
    j=2*i; // the middle third of the array ends here
    for( i ; i<j ; i++ ) root=avl_delete(root,array[i]->key,array[i]->y); // delete the middle third 
    free(array); // free the array 
    return count;
}

