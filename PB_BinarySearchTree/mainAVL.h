#ifndef MAINAVL_H_
#define MAINAVL_H_

#include <iostream>
#include <stdlib.h>
using namespace std;

#include <cassert>

class avlTreeNode {
public:
  long key;
  avlTreeNode *leftSide;
  avlTreeNode *rightSide;
  avlTreeNode *parentOfTree;
  int leftSideHeight;
  int rightSideHeight;

  public:
  avlTreeNode () : key(0), leftSide(NULL), rightSide(NULL), parentOfTree(NULL), leftSideHeight(0), rightSideHeight(0) {}
  avlTreeNode (long k) : key(k), leftSide(NULL), rightSide(NULL), parentOfTree(NULL), leftSideHeight(0), rightSideHeight(0) {}
  avlTreeNode (long k, avlTreeNode *l, avlTreeNode *r) : key(k), leftSide(l), rightSide(r), parentOfTree(NULL), leftSideHeight(0), rightSideHeight(0) {}
  avlTreeNode (long k, avlTreeNode *l, avlTreeNode *r, avlTreeNode *p) : key(k), leftSide(l), rightSide(r), parentOfTree(p), leftSideHeight(0), rightSideHeight(0) {}

  friend class mainAVL;
};

class mainAVL {
  avlTreeNode* root;
  avlTreeNode* searchNode (avlTreeNode* x, long key);
 // bool deleteNode (avlTreeNode* x, long key);
  avlTreeNode* rotateLeft(avlTreeNode* x);
  avlTreeNode* rotateRight(avlTreeNode* x);
  avlTreeNode* doubleRotateLeft(avlTreeNode* x);
  avlTreeNode* doubleRotateRight(avlTreeNode* x);

  public:
  mainAVL () : root(NULL) {}
  void print();
  avlTreeNode* searchNode (long key);
 // void deleteNode (long key);
  avlTreeNode* getRootNode();
  avlTreeNode* balanceTree (avlTreeNode* x);
  bool checkForNodeUpdates(avlTreeNode* x, long key);
  avlTreeNode* findSuccessorNode (avlTreeNode* x);
  void inOrderTraversal (avlTreeNode* x);
  int height();
  int max();
};

#endif
