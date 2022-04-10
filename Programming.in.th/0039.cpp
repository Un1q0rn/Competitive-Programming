#include<bits/stdc++.h>
using namespace std;

vector<int> ans,a;
int n,m,mark[10],no[10];
void permute(int state){
    if(state == n){
        for(auto e:ans) cout << e << " ";
        cout << "\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        if(no[i] == 1 && state == 0) continue;
        if(!mark[i]){
            mark[i] = 1;
            ans.push_back(i);
            permute(state+1);
            ans.pop_back();
            mark[i]=0;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x;cin >> x;
        no[x] = 1;
    }
    permute(0);
    return 0;
}
