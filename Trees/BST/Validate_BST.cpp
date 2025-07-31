
#include<iostream>
using namespace std ;

class TreeNode{
  public:
  int val ;
  TreeNode* left ;
  TreeNode* right ; 

   TreeNode(int val){
   this->val=val ;
    this->left=NULL ;
    this->right=NULL ;
  }
};

bool solve(TreeNode* root, long long minV ,long long maxV){
    if(root==NULL){
        return true ;
    }

    if(root->val<=minV || root->val>=maxV){
        return false ;
    }

    //now recursively check left and right subtree
    return solve(root->left,minV,root->val) && solve(root->right,root->val,maxV) ; 
}

bool isValidBst(TreeNode* root){
    return solve(root,LLONG_MAX,LLONG_MIN) ; 
}