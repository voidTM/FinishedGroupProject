/* 
 * File:   BST.h
 * Author: kim
 *
 * Created on November 9, 2014, 6:01 PM
 */

#ifndef BST_H
#define	BST_H
#include "TreeNode.h"

class BST {
private:
    TreeNode* root; // pointer to the root of tree

protected:
    void search(TreeNode*& treePtr, const int& searchKey);
    void insertItem(TreeNode*& treePtr, const int& newFrequency, const string& newWord);
    void deleteItem(TreeNode*& treePtr, int searchKey);
    void deleteNodeItem(TreeNode*& nodePtr);
    void processLeftmost(TreeNode*& nodePtr, int& treeItem);
   
 
    // Traversals don't need the TreeNode pointer by reference because we don't want
    // to modify anything
    void preorder(TreeNode* treePtr);
    void inorder(TreeNode* treePtr);
    void postorder(TreeNode* treePtr);
    void breadthfirst(TreeNode* treePtr); 

public:

    // Default constructor
    // Make an empty binary search tree with root equal to NULL
    BST() {
        root = NULL;
    };

    // Binary search tree operations
    bool isEmpty() const; // Check if BST is empty
    void searchTree(const int searchKey); // searches tree for an item
    void searchTreeInsert(const int newFrequency, const string newWord); // searches tree for appropiate
                                                 // place to enter item and enters
                                                 // an item into BST
    void searchTreeDelete(int searchKey); // Deletes and item from BST
                                             // given search key
    
    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();
    void breadthfirstTraverse(); 
    void inorderTraversewithHeight();
    void inorder(TreeNode* treePtr, int height);
    
    friend class HashClass;
   
};

#endif	/* BST_H */

