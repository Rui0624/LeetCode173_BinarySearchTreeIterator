//
//  main.cpp
//  LeetCode173_BinarySearchTreeIterator
//
//  Created by Rui on 1/9/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class BSTIterator {
public:
    stack<TreeNode*> s; //create a stack to store the nodes
    
    //initilize the iterator, make the all left nodes into the stack
    BSTIterator(TreeNode *root) {
        while(root)
        {
            s.push(root);
            root = root ->left;
        }
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* n = s.top();
        s.pop(); // pop and get the smallest element in the stack
        int res = n->val;
        
        //push the right child node of the node poped
        if(n->right){
            n = n -> right;
            while(n)
            {
                s.push(n);
                n = n->left;
            }
        }
        return res;
    }
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
