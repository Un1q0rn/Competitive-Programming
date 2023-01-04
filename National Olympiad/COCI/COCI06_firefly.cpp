#include <bits/stdc++.h> 
using namespace std; 

#define ll long long int 
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n,h;cin >> n >> h;
    vector<int> down(h+1),up(h+1);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(i%2){
            down[x]++;
        }
        else up[h-x+1]++;
    }
    for(int i=h-1;i>=1;i--){
        down[i]+=down[i+1];
    }
    for(int i=2;i<=h;i++){
        up[i]+=up[i-1];
    }
    ll mn = 1e18;
    int cnt = 0;
    for(int i=1;i<=h;i++){
        if(up[i]+down[i] < mn){
            mn = up[i]+down[i];
            cnt = 0;
        }
        cnt+=(up[i]+down[i] == mn);
    }
    cout << mn << ' ' << cnt;
    return 0;
}

