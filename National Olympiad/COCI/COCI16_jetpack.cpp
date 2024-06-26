#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()

const int N = 1e5;
int n,flag;
char grid[10][N+10];
bool vis[10][N+10];
vector<int> ans;
void dfs(int i,int j){
    if(flag || vis[i][j] || grid[i][j] == 'X') return ;
    vis[i][j] = 1;
    if(j == n-1){
        flag = 1;
        if(sz(ans)%2){
            if(ans.back() == n-1) ans.pop_back();
            else ans.push_back(n-1);
        }
        cout << sz(ans)/2 << '\n';
        for(int i=0;i<sz(ans)-1;i+=2){
            cout << ans[i] << ' ' << ans[i+1]-ans[i] << '\n';
        }
        return ;
    }
    if(i == 9){
        dfs(i,j+1);
        ans.push_back(j);
        dfs(i-1,j+1);
        ans.pop_back();
    }
    else if(i == 0){
        dfs(i,j+1);
        ans.push_back(j);
        dfs(i+1,j+1);
        ans.pop_back();
    }
    else{
        int now = sz(ans);
        if(sz(ans)%2 == 0) ans.push_back(j);
        dfs(i-1,j+1);
        if(sz(ans)-now >= 0 && (sz(ans)-now)%2 == 1) ans.pop_back();
        now = sz(ans);
        if(sz(ans)%2 == 1) ans.push_back(j);
        dfs(i+1,j+1);
        if(sz(ans)-now >= 0 && (sz(ans)-now)%2 == 1) ans.pop_back();
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<10;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    dfs(9,0);
    return 0;
}
