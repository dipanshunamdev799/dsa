#include <bits/stdc++.h>
using namespace std;
void convertToBinary(int n){
    //TC : log(n)
    //SC : log(n)
    if(n==0){
        cout<<'\n';
        return;
    }
    convertToBinary(n>>1);
    cout<< (n&1);
}
void convertToDecimal(string s){
    int ans = 0;
    int var = 1;
    for(auto x: s){
        if(x=='1'){
            ans+= var;
        }
        var = var<<1;
    }
    cout<< ans <<endl;
}
void convertToDecimal(int n){
    int ans = 0;
    int var =1 ;
    while(n){
        if(n%10){
            ans+= var;
        }
        n = n/10;
        var = var<<1;
    }
    cout<<ans<<endl;
}
void bitsCount(int n){
    int ans = 0;
    while(n){
        n = n >>1;
        ans++;
    }
    cout<<ans<<endl;
}
void setBitsCount(int n){
    int ans = 0;
    while(n){
        if(n&1) ans++;
        n = n>>1;
    }
    cout<<ans<<endl;
}
int main(int argc, char const *argv[])
{




    // int bin1 = 101;
    // convertToDecimal(bin1);

    // string bin2 = "1001";
    // convertToDecimal(bin2);

    // int x = 5;
    // convertToBinary(x);

    return 0;
}
