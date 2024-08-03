#include "mainAVL.h"
#include "InsertNode.h"

bool InsertNode::insertNode(avlTreeNode *x, long val) {
	bool needsUpdate;
	mainAVL mainavl;

	/*Here we are checking if a node with a given key value already exists in an AVL tree.
	If the node does not exist, it creates a new node with the given key value and it will insert it as root of the tree.*/
	if (x == NULL) {
		avlTreeNode *n = new avlTreeNode(val);
		root = n;
		return false;
	}
	if (val == x->key) {
		cout << val << " is already contained in tree." << endl;
		return false;
	}

	if (val < x->key) {
		if (x->leftSide != NULL) {
			needsUpdate = insertNode(x->leftSide, val);
			if (needsUpdate)
				x->leftSideHeight++;
			if (x->leftSideHeight - x->rightSideHeight > 1)
				balanceTree(x);
			return (needsUpdate && x->leftSideHeight > x->rightSideHeight);
		} else {
			avlTreeNode *n = new avlTreeNode(val, NULL, NULL, x);
			x->leftSide = n;
			x->leftSideHeight++;
			return (x->rightSide == NULL);
		}

	}
	//checks if a key value is greater than the current node's key value, recursively inserts it on the right child, updates the right side height, and balances the tree if necessary.
	else {
		if (x->rightSide != NULL) {
			needsUpdate = insertNode(x->rightSide, val);
			if (needsUpdate)
				x->rightSideHeight++;
			if (x->rightSideHeight - x->leftSideHeight > 1)
				balanceTree(x);
			return (needsUpdate && x->rightSideHeight > x->leftSideHeight);
		} else {
			avlTreeNode *n = new avlTreeNode(val, NULL, NULL, x);
			x->rightSide = n;
			x->rightSideHeight++;
			return (x->leftSide == NULL);
		}
	}

	cout << val << "End of insertNode" << endl;
}

void InsertNode::insertNode(long key) {
	insertNode(root, key);
}

void InsertNode::inOrderTraversal(avlTreeNode *trav) {
	if (trav->leftSide != NULL) {
		inOrderTraversal(trav->leftSide);
	}
	cout << trav->key << " (LH: " << trav->leftSideHeight << ", RH: "
						<< trav->rightSideHeight << ")" << endl;
	if (trav->rightSide != NULL) {
		inOrderTraversal(trav->rightSide);
	}
}

avlTreeNode* InsertNode::getRootNode() {
	return root;
}

void InsertNode::print() {
	if (root != NULL) {
		cout << "InOderTraversal" << endl;
		inOrderTraversal(root);
	}
	else {
		cout << "No elements found" << endl;
	}
	cout << endl;
}

// =====================================================================================

avlTreeNode* InsertNode::balanceTree(avlTreeNode *bt) {
	if ((*bt).leftSideHeight > (*bt).rightSideHeight) {
		if (((*bt).leftSide)->leftSideHeight >= ((*bt).leftSide)->rightSideHeight) {
			bt = rotateLeft(bt);
		} else {
			bt = doubleRotateLeft(bt);
		}
	} else {
		if (((*bt).rightSide)->rightSideHeight >= ((*bt).rightSide)->leftSideHeight) {
			bt = rotateRight(bt);
		} else {
			bt = doubleRotateRight(bt);
		}
	}
	return bt;
}

avlTreeNode* InsertNode::rotateLeft(avlTreeNode *rl) {
	//cout << "Rotating left subtree" << endl;
	avlTreeNode *child = (*rl).leftSide;
	(*rl).leftSide = (*child).rightSide;
	if ((*child).rightSide != NULL) {
		((*child).rightSide)->parentOfTree = rl;
	}
	(*child).rightSide = rl;
	if ((*rl).parentOfTree != NULL) {
		(*child).parentOfTree = (*rl).parentOfTree;
		if (((*rl).parentOfTree)->rightSide == rl) {
			((*rl).parentOfTree)->rightSide = child;
		} else {
			((*rl).parentOfTree)->leftSide = child;
		}
	} else {
		(*child).parentOfTree = NULL;
		root = child;
	}
	(*rl).parentOfTree = child;
	(*rl).leftSideHeight = (*child).rightSideHeight;
	if ((*rl).leftSideHeight > (*rl).rightSideHeight) {
		(*child).rightSideHeight = (*rl).leftSideHeight + 1;
	} else {
		(*child).rightSideHeight = (*rl).rightSideHeight + 1;
	}
	return child;
}

avlTreeNode* InsertNode::doubleRotateLeft(avlTreeNode *drl) {
	//cout << "Inside double rotate left" << endl;
	avlTreeNode *val = (*drl).leftSide->rightSide;
	rotateRight((*drl).leftSide);
	rotateLeft(drl);
	return val;
}
avlTreeNode* InsertNode::rotateRight(avlTreeNode *rr) {
    //cout << "Rotating right subtree" << endl;
    avlTreeNode *child = (*rr).rightSide;
    (*rr).rightSide = (*child).leftSide;
    if ((*child).leftSide!= NULL) {
        ((*child).leftSide)->parentOfTree = rr;
    }
    (*child).leftSide = rr;
    if ((*rr).parentOfTree!= NULL) {
        (*child).parentOfTree = (*rr).parentOfTree;
        if (((*rr).parentOfTree)->rightSide == rr) {
            ((*rr).parentOfTree)->rightSide = child;
        } else {
            ((*rr).parentOfTree)->leftSide = child;
        }
    } else {
        (*child).parentOfTree = NULL;
        root = child;
    }
    (*rr).parentOfTree = child;
    (*rr).rightSideHeight = (*child).leftSideHeight;
    if ((*rr).rightSideHeight > (*rr).leftSideHeight) {
        (*child).leftSideHeight = (*rr).rightSideHeight + 1;
    } else {
        (*child).leftSideHeight = (*rr).leftSideHeight + 1;
    }
    return child;
}

avlTreeNode* InsertNode::doubleRotateRight(avlTreeNode *drr) {
	//cout << "Inside double rotate right" << endl;
	avlTreeNode *val = (drr->rightSide)->leftSide;
	rotateLeft(drr->rightSide);
	rotateRight(drr);
	return val;
}
//==================================================================================
void InsertNode::deleteNode(long key) {
   deleteNode(root, key);
}
bool InsertNode::deleteNode(avlTreeNode *tn, long val) {
   bool updateNecessary;
   mainAVL mainavl;
   if(tn == NULL) {
     cout << val << " is not available in the tree." << endl;
     return false;
   }
   else if(val < tn->key) {
     updateNecessary = deleteNode(tn->leftSide, val);
     if(updateNecessary) (*tn).leftSideHeight--;
     if((*tn).rightSideHeight-(*tn).leftSideHeight>1) {
       tn = mainavl.balanceTree(tn);
       if(tn->parentOfTree!= NULL && (tn->parentOfTree)->leftSide==tn) {
         if((*tn).leftSideHeight > (*tn).rightSideHeight)
        	 return (updateNecessary && (*tn).leftSideHeight!= (tn->parentOfTree)->leftSideHeight-1);
         else
        	 return (updateNecessary && (*tn).rightSideHeight!= (tn->parentOfTree)->leftSideHeight-1);
       }
       else if(tn->parentOfTree!= NULL && (tn->parentOfTree)->rightSide==tn) {
         if((*tn).leftSideHeight > (*tn).rightSideHeight) return (updateNecessary && (*tn).leftSideHeight!= (tn->parentOfTree)->rightSideHeight-1);
         else
        	 return (updateNecessary && (*tn).rightSideHeight!= (tn->parentOfTree)->rightSideHeight-1);
       }
       else
    	   return true;
     }
     return (updateNecessary && (*tn).leftSideHeight+1 > (*tn).rightSideHeight);
   }
   else if(val > tn->key) {
	   updateNecessary = deleteNode(tn->rightSide, val);
     if(updateNecessary) (*tn).rightSideHeight--;
     if((*tn).leftSideHeight-(*tn).rightSideHeight>1) {
       tn = mainavl.balanceTree(tn);
       if(tn->parentOfTree!= NULL && (tn->parentOfTree)->leftSide==tn) {
         if((*tn).leftSideHeight > (*tn).rightSideHeight) return (updateNecessary && (*tn).leftSideHeight!= (tn->parentOfTree)->leftSideHeight-1);
         else  return (updateNecessary && (*tn).rightSideHeight!= (tn->parentOfTree)->leftSideHeight-1);
       }
       else if(tn->parentOfTree!= NULL && (tn->parentOfTree)->rightSide==tn) {
         if((*tn).leftSideHeight > (*tn).rightSideHeight) return (updateNecessary && (*tn).leftSideHeight!= (tn->parentOfTree)->rightSideHeight-1);
         else  return (updateNecessary && (*tn).rightSideHeight!= (tn->parentOfTree)->rightSideHeight-1);
       }
       else return true;
     }
     return (updateNecessary && (*tn).rightSideHeight+1 > (*tn).leftSideHeight);
   }
   else {
	   /*performs a right rotation on an AVL tree node x with two children, updates the necessary node references and heights, and balances the tree if necessary.
	   If the rotation results in an imbalance, the tree is rebalanced by calling the balanceTree() function.*/
      if(tn->rightSide != NULL && tn->leftSide != NULL) {
         avlTreeNode *successorToNode = mainavl.findSuccessorNode(tn);
	 updateNecessary = mainavl.checkForNodeUpdates(tn, successorToNode->key);
         if(successorToNode->parentOfTree != tn) {
	    if(successorToNode->rightSide != NULL) {
               (successorToNode->rightSide)->parentOfTree = successorToNode->parentOfTree;
               (successorToNode->parentOfTree)->leftSide = successorToNode->rightSide;
	    }
	    else (successorToNode->parentOfTree)->leftSide = NULL;
	    successorToNode->rightSide = tn->rightSide;
	    (tn->rightSide)->parentOfTree = successorToNode;
	 }
	 successorToNode->leftSide = tn->leftSide;
	 successorToNode->leftSideHeight = tn->leftSideHeight;
	 successorToNode->rightSideHeight = tn->rightSideHeight;
	 (tn->leftSide)->parentOfTree = successorToNode;
	 if(tn == root) {
	    successorToNode->parentOfTree = NULL;
	    root = successorToNode;
	 }
	 else if((tn->parentOfTree)->leftSide == tn) {
	    successorToNode->parentOfTree = tn->parentOfTree;
	    (tn->parentOfTree)->leftSide = successorToNode;
	 }
	 else {
	    successorToNode->parentOfTree = tn->parentOfTree;
	    (tn->parentOfTree)->rightSide = successorToNode;
	 }
	 free(tn);
	 if(successorToNode->leftSideHeight-successorToNode->rightSideHeight > 1) {
		 cout <<"inside the tree balance" << endl;
	    successorToNode = mainavl.balanceTree(successorToNode);
            if(successorToNode->parentOfTree != NULL && (successorToNode->parentOfTree)->leftSide == successorToNode) {
               if(successorToNode->leftSideHeight > successorToNode->rightSideHeight) return (successorToNode->leftSideHeight != (successorToNode->parentOfTree)->leftSideHeight-1);
               else return (successorToNode->rightSideHeight != (successorToNode->parentOfTree)->leftSideHeight-1);
            }
            if(successorToNode->parentOfTree != NULL && (successorToNode->parentOfTree)->rightSide == successorToNode) {
               if(successorToNode->leftSideHeight > successorToNode->rightSideHeight) return (successorToNode->rightSideHeight != (successorToNode->parentOfTree)->rightSideHeight-1);
               else return (successorToNode->rightSideHeight != (successorToNode->parentOfTree)->rightSideHeight-1);
            }
	 }
	 return
			 (updateNecessary && successorToNode->rightSideHeight+1 > successorToNode->leftSideHeight);
      }
      //This code performs a left rotation on an AVL tree node x with one child on the left, updates the necessary node references and heights, and frees the memory of the node x.
      //If the node x is the root node, the root pointer is updated to point to the left child.
      else if(tn->rightSide == NULL && tn->leftSide != NULL) {
         if(tn->parentOfTree != NULL) {
	    if((tn->parentOfTree)->rightSide == tn) {
	       (tn->parentOfTree)->rightSide = tn->leftSide;
	       (tn->leftSide)->parentOfTree = tn->parentOfTree;
	    }
	    else {
	       (tn->parentOfTree)->leftSide = tn->leftSide;
	       (tn->leftSide)->parentOfTree = tn->parentOfTree;
	    }
	    free(tn);
	    return true;
	 }
	 else {
	    root = tn->leftSide;
	    (tn->leftSide)->parentOfTree = NULL;
	    free(tn);
	    return true;
         }
      }
      else if(tn->rightSide != NULL && tn->leftSide == NULL) {
         if(tn->parentOfTree != NULL) {
	    if((tn->parentOfTree)->rightSide == tn) {
	       (tn->parentOfTree)->rightSide = tn->rightSide;
	       (tn->rightSide)->parentOfTree = tn->parentOfTree;
	    }
	    else {
	       (tn->parentOfTree)->leftSide = tn->rightSide;
	       (tn->rightSide)->parentOfTree = tn->parentOfTree;
	    }
	    free(tn);
	    return true;
	 }
	 else {
	    root = tn->rightSide;
	    (tn->rightSide)->parentOfTree = NULL;
	    free(tn);
	    return true;
	 }
      }
      //This code performs a deletion of an AVL tree node x with no children, updates the necessary node references and frees the memory of the node x.
      //If the node x is the root node, the root pointer is updated to NULL.
      else {
         if(tn->parentOfTree == NULL) root = NULL;
         else if((tn->parentOfTree)->rightSide == tn) {
	    (tn->parentOfTree)->rightSide = NULL;
	    free(tn);
	    return true;
	 }
	 else {
	    (tn->parentOfTree)->leftSide = NULL;
	    free(tn);
	    return true;
	 }
      }
   }

   cout << "end of delete " <<endl;
}

//Searches for a node with a given key value in an AVL tree and returns a pointer to the node if it exists, or NULL if it does not.
avlTreeNode* InsertNode::searchNode (avlTreeNode *x, long val) {
	cout << "Inside searchNode " << endl;
   if(x == NULL) return NULL;
   else if(val == x->key) return x;
   else if(val < x->key) return searchNode(x->leftSide, val);
   else return searchNode(x->rightSide, val);
}

avlTreeNode* InsertNode::searchNode (long key) {
  return searchNode (root, key);
}

//Deletes all nodes in an AVL tree by recursively traversing the tree and freeing the memory of each node.
void InsertNode::deleteAll() {
	cout << "Deleting all the elements in the tree" << endl;
	if (root != NULL) {
		deleteAllNodes(root);
	}
	cout << endl;
}

void InsertNode::deleteAllNodes(avlTreeNode *x) {
	if (x == nullptr) {
		root = NULL;
	        return;
	    }
	deleteAllNodes(x->leftSide);
	deleteAllNodes(x->rightSide);
	    delete x;
}
