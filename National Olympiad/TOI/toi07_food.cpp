#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int mark[10],pick[10],n,m;
vector<int> ans;
void permute(int state){
    if(state == n){
        for(auto x:ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(state == 0 && mark[i]) continue;
        if(!pick[i]){
            ans.pb(i);
            pick[i] = 1;
            permute(state+1);
            pick[i] = 0;
            ans.pop_back();
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;  
    for(int i=0;i<m;i++){
        int x;cin >> x;
        mark[x] = 1;
    }
    permute(0);
    return 0;
}
