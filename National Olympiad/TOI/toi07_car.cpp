#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
int a[100][100],m,s,n,e,ch;
vector<int> ans;
void play(int ni,int nj){
    if(ni == 1 && (nj == s-1 || nj == s || nj == s+1)){
        if(nj == s-1) ans.pb(1);
        if(nj == s) ans.pb(3);
        if(nj == s+1) ans.pb(2);
        reverse(all(ans));
        ch = 1;
        for(auto x:ans) cout << x << '\n';
        return;
    }
    if(a[ni-1][nj-1] == 0 && nj-1 >= 1 && ni-1 >= 1){
        ans.pb(2);
        play(ni-1,nj-1);
        ans.pop_back();
    }
    if(a[ni-1][nj] == 0 && ni-1 >= 1){
        ans.pb(3);
        play(ni-1,nj);
        ans.pop_back();
    }
    if(a[ni-1][nj+1] == 0 && nj+1 <= m && ni-1 >= 1){
        ans.pb(1);
        play(ni-1,nj+1);
        ans.pop_back();
    }
    return ;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> s >> n;
    vector<int> e;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(i == n && a[i][j] == 0) e.pb(j);
        }
    }
    for(auto x:e){
        play(n,x);
    }
    return 0;
}
