#include <bits/stdc++.h>

using namespace std;
 
vector<int> coin_flips(vector<int> b,int c){
    int p = 0;
    for(int i=0;i<64;i++){
        if(b[i]) continue;
        p ^= i;
    }
    c ^= p;
    return {c};
}

int find_coin(vector<int> b){
    int p = 0;
    for(int i=0;i<64;i++){
        if(b[i]) p ^= i;
    }
    return p;
}
