#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
struct A{
    int a,b,c;
    bool operator < (const A&o) const {
        if(a == o.a) return b<o.b;
        return a<o.a;
    }
};
const int N = 1e6+10;
int n,k,m,cnt,q,mark[N];
vector<A> a;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> q;
    for(int i=0;i<n;i++){
        int u,v;cin >> u >> v;
        a.pb({u,1,i+1});
        a.pb({v+1,-1,i+1});
    }
    sort(all(a));
    for(auto x:a){
        if(x.b == 1 && cnt < k){
            mark[x.c] = 1;
            cnt++;
        }
        else if(x.b < 0 && mark[x.c]) cnt--;
    }
    while(q--){
        int u;cin >> u;
        if(mark[u]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}
