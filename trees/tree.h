struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    Node(int x){
        left = right = nullptr;
        val = x;
    }
    Node(){
        left=right=nullptr;
        val = 0;
    }
};
typedef struct Node Node;