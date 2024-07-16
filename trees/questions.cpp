#include <tree.h>
#include<iostream>
using namespace std;
class Questions{
    static int height(Node* root){
        //If only root is there then height = 1
        if(root==nullptr) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    static void printNodesAtDistanceK(Node* root,int k){
        //Levels = 0,1,2,3.... NOT FROM ZERO
        if(root==nullptr) return;
        if(k==0){
            cout<<root->val<<" ";
        }else{
            printNodesAtDistanceK(root->left,k-1);
            printNodesAtDistanceK(root->right,k-1);
        }
    }
    static int size(Node* root){
        if(root==nullptr) return 0;
        return 1 + size(root->left) + size(root->right);
    }
    static int getMax(Node* root){
        if(root==nullptr) return INT8_MIN;
        return max(root->val,max(getMax(root->left),getMax(root->right)));
    }
    static int maxLevel;
    static void leftView1(Node* root,int level=1){
        //Pre Order : NODE LST RST
        if(root==nullptr){
            return;
        }
        if(maxLevel<level){
            cout<<root->val<<" ";
            maxLevel = level;
        }
        leftView1(root->left);
        leftView1(root->right);
    }
    static void leftView2(Node* root){
        
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
