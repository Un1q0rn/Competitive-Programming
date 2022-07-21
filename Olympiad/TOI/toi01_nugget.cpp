#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    set<int> s;
    for(int i=0;i<=n;i+=6){
        for(int j=0;j<=n;j+=9){
            for(int k=0;k<=n;k+=20){
                if(i+j+k <= n && i+j+k != 0) s.insert(i+j+k);
            }
        }
    }
    if(!s.empty()){
        for(auto it=s.begin();it!=s.end();it++){
            cout << *it << "\n";
        }
    }
    else cout << "no";
    return 0;
}
