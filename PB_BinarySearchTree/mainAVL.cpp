#include "mainAVL.h"

avlTreeNode* mainAVL::balanceTree(avlTreeNode *tn) {
	cout << "Inside balanceTree" << endl;
	if ((*tn).leftSideHeight > (*tn).rightSideHeight) {
		if (((*tn).leftSide)->leftSideHeight >= ((*tn).leftSide)->rightSideHeight) {
			tn = rotateLeft(tn);
		} else {
			tn = doubleRotateLeft(tn);
		}
	} else {
		if (((*tn).rightSide)->rightSideHeight >= ((*tn).rightSide)->leftSideHeight) {
			tn = rotateRight(tn);
		} else {
			tn = doubleRotateRight(tn);
		}
	}
	return tn;
}
//
avlTreeNode* mainAVL::rotateLeft(avlTreeNode *tn) {
	cout << "Rotating left subtree" << endl;
	avlTreeNode *childNode = (*tn).leftSide;
	(*tn).leftSide = (*childNode).rightSide;
	if ((*childNode).rightSide != NULL) {
		((*childNode).rightSide)->parentOfTree = tn;
	}
	(*childNode).rightSide = tn;
	if ((*tn).parentOfTree != NULL) {
		(*childNode).parentOfTree = (*tn).parentOfTree;
		if (((*tn).parentOfTree)->rightSide == tn) {
			((*tn).parentOfTree)->rightSide = childNode;
		} else {
			((*tn).parentOfTree)->leftSide = childNode;
		}
	} else {
		(*childNode).parentOfTree = NULL;
		root = childNode;
	}
	(*tn).parentOfTree = childNode;
	(*tn).leftSideHeight = (*childNode).rightSideHeight;
	if ((*tn).leftSideHeight > (*tn).rightSideHeight) {
		(*childNode).rightSideHeight = (*tn).leftSideHeight + 1;
	} else {
		(*childNode).rightSideHeight = (*tn).rightSideHeight + 1;
	}
	return childNode;
}

avlTreeNode* mainAVL::doubleRotateLeft(avlTreeNode *x) {
	cout << "Inside double rotate left" << endl;
	avlTreeNode *val = (*x).leftSide->rightSide;
	rotateRight((*x).leftSide);
	rotateLeft(x);
	return val;
}

avlTreeNode* mainAVL::rotateRight(avlTreeNode *tn) {
    cout << "Rotating right subtree" << endl;
    avlTreeNode *childNode = (*tn).rightSide;
    (*tn).rightSide = (*childNode).leftSide;
    if ((*childNode).leftSide!= NULL) {
        ((*childNode).leftSide)->parentOfTree = tn;
    }
    (*childNode).leftSide = tn;
    if ((*tn).parentOfTree!= NULL) {
        (*childNode).parentOfTree = (*tn).parentOfTree;
        if (((*tn).parentOfTree)->rightSide == tn) {
            ((*tn).parentOfTree)->rightSide = childNode;
        } else {
            ((*tn).parentOfTree)->leftSide = childNode;
        }
    } else {
        (*childNode).parentOfTree = NULL;
        root = childNode;
    }
    (*tn).parentOfTree = childNode;
    (*tn).rightSideHeight = (*childNode).leftSideHeight;
    if ((*tn).rightSideHeight > (*tn).leftSideHeight) {
        (*childNode).leftSideHeight = (*tn).rightSideHeight + 1;
    } else {
        (*childNode).leftSideHeight = (*tn).leftSideHeight + 1;
    }
    return childNode;
}

avlTreeNode* mainAVL::doubleRotateRight(avlTreeNode *tn) {
	cout << "Inside double rotate right" << endl;
	avlTreeNode *val = (tn->rightSide)->leftSide;
	rotateLeft(tn->rightSide);
	rotateRight(tn);
	return val;
}

avlTreeNode* mainAVL::findSuccessorNode(avlTreeNode *tn) {
	tn = tn->rightSide;
	while (tn->leftSide != NULL) {
		tn = tn->leftSide;
	}
	return tn;
}


bool mainAVL::checkForNodeUpdates(avlTreeNode *tn, long val) {
	bool needsUpdate;
	if (val < tn->key) {
		needsUpdate = checkForNodeUpdates(tn->leftSide, val);
		if (needsUpdate)
			(*tn).leftSideHeight--;
		if ((*tn).rightSideHeight - (*tn).leftSideHeight > 1) {
			tn = balanceTree(tn);
			if (tn->parentOfTree != NULL && (tn->parentOfTree)->leftSide == tn) {
				if ((*tn).leftSideHeight > (*tn).rightSideHeight)
					return (needsUpdate
							&& (*tn).leftSideHeight
									!= (tn->parentOfTree)->leftSideHeight - 1);
				else
					return (needsUpdate
							&& (*tn).rightSideHeight
									!= (tn->parentOfTree)->leftSideHeight - 1);
			} else if (tn->parentOfTree != NULL && (tn->parentOfTree)->rightSide == tn) {
				if ((*tn).leftSideHeight > (*tn).rightSideHeight)
					return (needsUpdate
							&& (*tn).leftSideHeight
									!= (tn->parentOfTree)->rightSideHeight - 1);
				else
					return (needsUpdate
							&& (*tn).rightSideHeight
									!= (tn->parentOfTree)->rightSideHeight - 1);
			} else
				return true;
		}
		return (needsUpdate && (*tn).leftSideHeight + 1 > (*tn).rightSideHeight);
	} else if (val > tn->key) {
		needsUpdate = checkForNodeUpdates(tn->rightSide, val);
		if (needsUpdate)
			(*tn).rightSideHeight--;
		return needsUpdate;
	} else
		return true;
}
