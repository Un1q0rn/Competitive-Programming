#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;cin >> n >> x;
    vector<int> a(n);
    map<int,int> m;
    for(auto &e:a){
        cin >> e;
    }
    for(int i=0;i<n;i++){
        if(m[x-a[i]]){
            cout << i+1 << " " <<  m[x-a[i]];
            return 0;
        }
        m[a[i]] = i+1;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
