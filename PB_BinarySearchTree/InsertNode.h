#ifndef INSERTNODE_H_
#define INSERTNODE_H_

#include "mainAVL.h"

class InsertNode {
	avlTreeNode* root;
	bool insertNode (avlTreeNode* x, long key);

	public:
	void insertNode (long key);
	avlTreeNode* getRootNode();
	void print();
	void inOrderTraversal (avlTreeNode* x);
	 avlTreeNode* rotateLeft(avlTreeNode* x);
	 avlTreeNode* rotateRight(avlTreeNode* x);
	 avlTreeNode* doubleRotateLeft(avlTreeNode* x);
	 avlTreeNode* doubleRotateRight(avlTreeNode* x);
	 avlTreeNode* balanceTree (avlTreeNode* x);
	 bool deleteNode (avlTreeNode* x, long key);
	 void deleteNode (long key);
	 avlTreeNode* searchNode (long key);
	 avlTreeNode* searchNode (avlTreeNode* x, long key);
	 void deleteAll();
	 void deleteAllNodes(avlTreeNode *x);
};

#endif
