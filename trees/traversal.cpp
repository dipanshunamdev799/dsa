#include<tree.h>
#include<iostream>
#include<stack>
#include <queue>
using namespace std;
class Traversal{
    static void inorder_DFS(Node* root){

        //Recursion
        // if(root==nullptr){
        //     cout<<"\n";
        //     return;
        // }
        // inorder_DFS(root->left);
        // cout<<root->val<<" ";
        // inorder_DFS(root->right);

        //Stack
        // stack<Node*> s;
        // Node* curr = root;
        // while(curr || !s.empty()){
        //     while(curr){
        //         s.push(curr);
        //         curr = curr->left;
        //     }
        //     if(!s.empty()){
        //         curr = s.top();
        //         cout<<curr->val<<" ";
        //         curr = curr->right;
        //         s.pop();
        //     }
        // }
        // cout<<"\n";
        

        //Morris traversal
        Node* curr = root;
        while(curr){
            if(curr->left==nullptr){
                cout<<curr->val<<" ";
                curr = curr->right;
            }else{
                Node* right = curr->left;
                while(right->right && right->right!=curr) right = right->right;
                if(right->right==curr){
                    right->right = nullptr;
                    cout<<curr->val<<" ";
                    curr = curr->right;
                }else{
                    right->right = curr;
                    curr = curr->left;
                }
            }
        }
        cout<<"\n";
    }
    static void preorder_DFS(Node* root){
        //Recursion
        // if(root==nullptr){
        //     cout<<"\n";
        //     return;
        // }
        // cout<<root->val<<" ";
        // preorder_DFS(root->left);
        // preorder_DFS(root->right);

        //Stack
        // Node* curr = root;
        // stack<Node*> s;
        // while(curr || !s.empty()){
        //     while(curr){
        //         cout<<curr->val;
        //         s.push(curr);
        //         curr = curr->left;
        //     }
        //     if(!s.empty()){
        //         curr = s.top()->right;
        //         s.pop();
        //     }
        // }
        // cout<<"\n";

        //Morris
        Node* curr = root;
        while(curr){
            if(curr->left==nullptr){
                cout<<curr->val<<" ";
                curr = curr->right;
            }else{
                Node* right = curr->left;
                while(right->right && right->right!=curr) right = right->right;
                if(right->right==curr){
                    right->right = nullptr;
                    curr = curr->right;
                }else{
                    right->right = curr;
                    cout<<curr->val<<" ";
                    curr = curr->left;
                }
            }
        }
        cout<<"\n";

    }
    static void postorder_DFS(Node* root){

        //Recursion
        // if(root==nullptr){
        //     cout<<"\n";
        //     return;
        // }
        // postorder_DFS(root->left);
        // postorder_DFS(root->right);
        // cout<<root->val<<" ";

        //Stack
        // stack<Node*> s;
        // stack<Node*> buffer;        
        // Node* curr = root;
        // while(curr || !s.empty()){
        //     while(curr){
        //         s.push(curr);
        //         curr = curr->right;
        //     }
        //     if(!s.empty()){
        //         curr = s.top();
        //         s.pop();
        //         curr = curr->left;
        //     }
        // }
        // while(!s.empty()){
        //     buffer.push(s.top());
        //     s.pop();
        // }
        // while(!buffer.empty()){
        //     cout<<buffer.top()<<" ";
        //     buffer.pop();
        // }
        // cout<<"\n";

        //Morris
        stack<Node*> buffer;
        Node* curr = root;
        while(curr){
            if(curr->right==nullptr){
                buffer.push(curr);
                curr = curr->left;
            }else{
                Node* left = curr->right;
                while(left->left && left->left!=curr) left = left->left;
                if(left->left==curr){
                    curr = curr->left;
                    left->left = nullptr;
                }else{
                    left->left = curr;
                    buffer.push(curr);
                    curr = curr->right;
                }
            }
        }
        cout<<"\n";
    }



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
    static void levelorder_BFS(Node* root){
        //Naive
        // int h = height(root);
        // for(int i=0; i<h; i++){
        //     printNodesAtDistanceK(root,i);
        // }
        // cout<<"\n";

        //Queue
        queue<Node*> q;
        if(root==nullptr) return;
        q.push(root);
        while(!q.empty()){
            Node* node= q.front();
            q.pop();
            cout<<node->val<<" ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout<<"\n";
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
