/* 
 * File:   BST.cpp
 * Author: kim
 * 
 * Created on November 9, 2014, 6:01 PM
 */

#include "BST.h"
#include <cstddef> // definition of NULL
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <queue> // for breadth first traversal

using namespace std;


bool BST::isEmpty() const {
    return (root == NULL);
    // returns true if root is NULL, false if root is not NULL

}

void BST::searchTree(const int searchKey) {
    search(root, searchKey); // start with root as tree pointer
}

// Recursively searches for an frequency in BST

void BST::search(TreeNode*& treePtr, const int& searchKey) {
    if (treePtr == NULL) // if the whole BST has been searched aka treePtr is NULL 
        // and there are no matches
    {
        cout << "Data not found" << endl;
    } else if (searchKey == treePtr->frequency) // if searchKey is the same as the frequency
        // pointed to by the pointer
    {
        cout << "The data is found" << endl;
    } else if (searchKey < treePtr->frequency) {
        search(treePtr->leftChildPtr, searchKey);
    } else // search the right subtree
    {
        search(treePtr->rightChildPtr, searchKey);
    }

}

void BST::searchTreeInsert(const int newFrequency, const string newWord) {
    insertItem(root, newFrequency, newWord); // start with root as tree pointer
}

// Recursively inserts an frequency into a BST

void BST::insertItem(TreeNode*& treePtr, const int& newFrequency,
        const string& newWord) {
    if (treePtr == NULL) // position of insertion is found; insert after leaf
    {
        treePtr = new TreeNode(newFrequency, NULL, NULL);
        treePtr->word = newWord;

    }// else search for the insertion position
    else if (newFrequency < treePtr->frequency) {
        insertItem(treePtr->leftChildPtr, newFrequency, newWord);
    } else // search the right subtree
    {
        insertItem(treePtr->rightChildPtr, newFrequency, newWord);
    }

}// end insertItem

void BST::searchTreeDelete(int searchKey) {
    deleteItem(root, searchKey); // start with root
}

// Recursively deletes an frequency from a BST

void BST::deleteItem(TreeNode*& treePtr, int searchKey) {

    if (treePtr == NULL) {
        cout << "delete failed, empty tree" << endl;
    } else if (searchKey == treePtr->frequency) {
        // frequency is found, frequency is in the root of some subtree
        deleteNodeItem(treePtr); // delete frequency
    }// else search for the frequency
    else if (searchKey < treePtr->frequency) {
        // search left subtree
        deleteItem(treePtr->leftChildPtr, searchKey);
    } else {
        // search right subtree
        deleteItem(treePtr->rightChildPtr, searchKey);
    }

} // end deleteItem


// Deletes the frequency in the root of a given tree
// There are four cases:
// 1. The root is a leaf
// 2. The root has a right child
// 3. The root has a left child
// 4. The root has two children

void BST::deleteNodeItem(TreeNode*& nodePtr) {
    TreeNode *delPtr;
    int replacementItem;

    // test for a leaf
    if ((nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL)) {
        delete nodePtr; // free the memory
        nodePtr = NULL; // make nodePtr point to NULL
    }// end if leaf

        // test for right child
    else if (nodePtr->leftChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr; // replacing frequency to be deleted
        // with right child
        delPtr->rightChildPtr = NULL; // deleting the frequency
        delete delPtr; // delete the temp pointer

    }// end if right child

        // test for left child
    else if (nodePtr->rightChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }// end if left child

        // there are two children
        // retrieve and delete the inorder successor
    else {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->frequency = replacementItem;
    } // end if two children

} // end deleteNodeItem

void BST::processLeftmost(TreeNode*& nodePtr, int& treeItem) {
    // if leftmost found
    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->frequency; // copying frequency to a temp
        TreeNode* delPtr = nodePtr; // make a temp delPtr and point to frequency to be deleted 
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }// else find leftmost
    else {
        processLeftmost(nodePtr->leftChildPtr, treeItem);
    }

} // end processLeftmost




// Traverse functions

void BST::preorderTraverse() {
    preorder(root);
}

void BST::preorder(TreeNode* treePtr) {
    if (treePtr != NULL) {
        cout << "word: " << treePtr->word << endl;
        cout << "frequency: " << treePtr->frequency << endl;
        cout << endl;
        preorder(treePtr->leftChildPtr);
        preorder(treePtr->rightChildPtr);
    } // end if

} // end preorder

void BST::inorderTraverse() {
    inorder(root);
}

void BST::inorder(TreeNode* treePtr) {
    if (treePtr != NULL) {
        inorder(treePtr->leftChildPtr);
        cout << "word: " << treePtr->word << endl;
        cout << "frequency: " << treePtr->frequency << endl;
        cout << endl;
        inorder(treePtr->rightChildPtr);
    } // end if
} // end inorder


void BST::inorderTraversewithHeight() {
    inorder(root, 0);
}

void BST::inorder(TreeNode* treePtr, int height) {
    if (treePtr != NULL) {
        inorder(treePtr->leftChildPtr, height+1);
//        cout << "indent by: " << height <<endl;
        for (int i = 0; i < height; i++) cout << "  ";
        cout << treePtr->word << "(" << treePtr->frequency << ")" <<endl;
//        cout << "word: " << treePtr->word << endl;
//        cout << "frequency: " << treePtr->frequency << endl;
//        cout << endl;
        inorder(treePtr->rightChildPtr, height+1);
    } // end if
} // end inorder

void BST::postorderTraverse() {
    postorder(root);
}

void BST::postorder(TreeNode* treePtr) {
    if (treePtr != NULL) {
        postorder(treePtr->leftChildPtr);
        postorder(treePtr->rightChildPtr);
        cout << "word: " << treePtr->word << endl;
        cout << "frequency: " << treePtr->frequency << endl;
        cout << endl;
    } // end if
} // end postorder

void BST::breadthfirstTraverse() {
    
    breadthfirst(root);
    
}


void BST::breadthfirst(TreeNode* treePtr) {
    queue<TreeNode*> queue; // temp queue holding tree node pointers
    TreeNode* traverse; // pointer to node being processed
    if (treePtr == NULL)
        return; // nothing to traverse
    queue.push(treePtr); // put something in queue intially, so that we enter
    // the body of the loop

    while (!queue.empty()) {
        traverse = queue.front(); // Point to first item enqueued 
        queue.pop(); // Pop out first item enqueued

        // Visit the node pointed to by traverse.
        cout << "Word: " << traverse->word << endl;
        cout << "Frequency: " << traverse->frequency << endl;
        cout << endl;
       
        // If there is a left child, add it for later processing
        if (traverse->leftChildPtr != NULL)
            queue.push(traverse->leftChildPtr);
        // If there is a right child, add it for later processing
        if (traverse->rightChildPtr != NULL)
            queue.push(traverse->rightChildPtr);
    } // end while

}
