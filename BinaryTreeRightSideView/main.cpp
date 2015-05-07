//
//  main.cpp
//  BinaryTreeRightSideView
//
//  Created by 黄美强 on 15/5/6.
//  Copyright (c) 2015年 黄 美强. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    queue<TreeNode> que;
    if(root == NULL)
        return result;
    TreeNode* work;
    work = root;
    que.push(*work);
    int countA = 1;
    int countB = 0;
    while(!que.empty()){
        *work = que.front();
        if(work->left != NULL){
            que.push(*(work->left));
            countB++;
        }
        if(work->right != NULL){
            que.push(*(work->right));
            countB++;
        }
        if(countA == 1){
            result.push_back(work->val);
            countA = countB;
            countB = 0;
        }else{
            countA--;
        }
        que.pop();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
