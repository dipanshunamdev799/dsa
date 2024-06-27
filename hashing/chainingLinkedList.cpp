#include <list>
#include <iostream>
using namespace std;
struct HashMap{
    int BUCKET_SIZE;
    list<int>* BUCKET;
    HashMap(int x){
        BUCKET_SIZE = x;
        BUCKET = new list<int>[BUCKET_SIZE];
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
        BUCKET[slot].remove(x);
    }
};
typedef struct HashMap HashMap;
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
