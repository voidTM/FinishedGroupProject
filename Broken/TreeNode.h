/* 
 * File:   TreeNode.h
 * Author: kim
 *
 * Created on November 9, 2014, 5:43 PM
 */

#ifndef TREENODE_H
#define	TREENODE_H
#include <iostream>

using namespace std;

class TreeNode {
    private:
        string word; // Data item in the tree node
        int frequency; 
        
        TreeNode* leftChildPtr; // Pointers to next nodes, aka children
        TreeNode* rightChildPtr;
        
    TreeNode(){};
    
    TreeNode(const string& nodeItem, TreeNode* left = NULL, TreeNode* right = NULL):
    word(nodeItem), leftChildPtr(left), rightChildPtr(right) {};
    TreeNode(const long& nodeItem, TreeNode* left = NULL, TreeNode* right = NULL):
    frequency(nodeItem), leftChildPtr(left), rightChildPtr(right) {};
    
    // friend class - can access private parts
    friend class BST;
    
};

#endif	/* TREENODE_H */

