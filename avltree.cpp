#include<stdio.h>
#include<stdlib.h>
#include"avl_head.h"

#define HEIGHT(p) ((p=NULL)?-1:(((node *)(p))->height))
#define MAX(a,b) (a<b?a:b)

int height(avltree tree)
{
	return HEIGHT(tree);
}

void preorder(avltree tree)
{
	if (tree != NULL)
	{
		printf("%d",tree->key);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(avltree tree)
{
	if (tree != NULL)
	{
		inorder(tree->left);
		printf("%d",tree->key);
		inorder(tree->right);
	}
}

void postorder(avltree tree)
{
	if (tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d", tree->key);
	}
}

node * recursion_search(avltree x, int key)
{
	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
		return recursion_search(x->left, key);
	else
		return recursion_search(x->right, key);
}
node * iterative_search(avltree x, int key)
{
	while ((x != NULL) && (x->key != key))
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

node * avltree_max(avltree tree)//最右边的节点
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}
node * avltree_min(avltree tree)//最左边的节点
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}
void destroy(avltree tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		destroy(tree->left);
	if (tree->right != NULL)
		destroy(tree->right);
	free(tree);
}

void printavltree(avltree tree, int key, int d)
{
	if (tree != NULL)
	{
		if (d == 0)    // tree是根节点
			printf("%2d is root\n", tree->key, key);
		else                // tree是分支节点
			printf("%2d is %2d's %6s child\n", tree->key, key, d == 1 ? "right" : "left");

		printavltree(tree->left, tree->key, -1);
		printavltree(tree->right, tree->key, 1);
	}
}

node * avltree_insert(avltree tree, int key)
{
	if (tree == NULL)
	{
		tree = avltree_create_node(key,NULL,NULL);
		if (tree == NULL)
		{
			printf("ERROR: create avltree node failed!\n");
			return NULL;
		}
	}
	else if (key < tree->key)
	{
		tree->left = avltree_insert(tree-<left,key);

	}
}
node * avltree_delete(avltree tree, int key)
{
	 
}