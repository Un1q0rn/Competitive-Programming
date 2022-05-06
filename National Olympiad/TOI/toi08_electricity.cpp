#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
const int N = 1e6+100;
struct A{
    int idx,w;
    bool operator < (const A&o) const {
        return w>o.w;
    }
};
priority_queue<A> pq;
int dp[N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> dp[i];
        while(!pq.empty() && i-pq.top().idx>k){
            pq.pop();
        }
        if(!pq.empty()) dp[i]+=pq.top().w;
        pq.push({i,dp[i]});
    }
    cout << dp[n];
    return 0;
}
