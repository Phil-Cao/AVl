#pragma once
typedef int type;
typedef struct avlnode
{
	int height;
	int key;
	avlnode *left;
	avlnode *right;
}node,*avltree;

int height(avltree tree);
void preorder(avltree tree);
void inorder(avltree tree);
void postorder(avltree tree);

void printavltree(avltree tree, int key, int d);
node * recursion_search(avltree x, int key);
node * iterative_search(avltree x, int key);
node * avltree_max(avltree tree);
node * avltree_min(avltree tree);

node * avltree_insert(avltree tree, int key);
node * avltree_delete(avltree tree, int key);

void destroy(avltree tree);

//#endif