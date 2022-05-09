#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

map<int,int> m;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    for(int i=0;i<k;i++){
        int l,r;cin >> l >> r;
        m[l]++;
        m[r+1]--;
    }
    m[n+1] = 0;
    char c;cin >> c;
    int ig;
    if(c == 'R') ig = 0;
    else if(c == 'G') ig = 1;
    else if(c == 'B') ig = 2;
    ll ans = 0,last = 1,now=0;
    for(auto x:m){
        int a = x.first-last;
        ans += a*((ig-now+3)%3);
        now += x.second+3;
        now%=3;
        last = x.first;
    }
    cout << ans << '\n';
    return 0;
}
