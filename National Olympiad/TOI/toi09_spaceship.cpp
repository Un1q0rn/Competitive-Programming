#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int square(int x) { return x*x;}
struct A{
    int x,y,z,m,k,c;
};
A shop[100];
int n,ans=INT_MAX,mark[100],t;
void play(int x,int y,int z,int m,int k,int c,int sum){
    if(m >= n && k >= n && c >= n){
        ans = min(sum,ans);
        return ;
    }
    for(int i=0;i<t;i++){
        if(mark[i]) continue;
        mark[i] = 1;
        int cost = square(shop[i].x-x)+square(shop[i].y-y)+square(shop[i].z-z);
        sum += cost;
        play(shop[i].x,shop[i].y,shop[i].z,m+shop[i].m,k+shop[i].k,c+shop[i].c,sum);
        mark[i] = 0;
        sum -= cost;
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int sx,sy,sz;cin >> n >> sx >> sy >> sz;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> shop[i].x >> shop[i].y >> shop[i].z >> shop[i].m >> shop[i].k >> shop[i].c;
    }
    play(sx,sy,sz,0,0,0,0);
    cout << ans;
    return 0;
}
