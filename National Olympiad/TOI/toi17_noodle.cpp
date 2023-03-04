#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
priority_queue<int,vector<int>,greater<int>> pq;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;cin >> n >> m >> k;
    vi(int) a(n);
    for(auto &e:a) cin >> e;
    ll l = 0,r = 1e18;
    while(l<r){
        ll mid = l+((r-l+1)>>1);
        ll cnt = 0,sum = 0;
        for(int i=0;i<n;i++){
            pq.push(a[i]);
            sum+=a[i];
            while(sz(pq) > k){
                sum-=pq.top();
                pq.pop();
            }
            if(sum >= mid && sz(pq) == k){
                cnt++;
                sum = 0;
                while(sz(pq)) pq.pop();
            }
        }
        while(sz(pq)) pq.pop();
        if(cnt < m){
            r = mid-1;
        }
        else l = mid;
    }
    cout << r;
    return 0;
}
