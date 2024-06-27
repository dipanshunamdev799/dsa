#include <iostream>
#include <vector>
using namespace std;
struct HashMap{
    int BUCKET_SIZE;
    vector<int>* BUCKET;
    HashMap(int x){
        BUCKET_SIZE = x;
        BUCKET = new vector<int>[BUCKET_SIZE];
    }
    bool search(int x){
        int slot = x%BUCKET_SIZE;
        for(auto y: BUCKET[slot]){
            if(y==x) return true;
        }
        return false;
    }
    void insert(int x){
        int slot = x%BUCKET_SIZE;
        for(auto y: BUCKET[slot]){
            if(y==x) return;
        }
        BUCKET[slot].push_back(x);
    }
    void del(int x){
        int slot = x%BUCKET_SIZE;
        int n = BUCKET[slot].size();
        for(int i=0; i<n; i++){
            if(BUCKET[slot][i] == x){
                BUCKET[slot].erase(BUCKET[slot].begin()+i);
                return;
            }
        }
    }
};
typedef struct HashMap HashMap;
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
