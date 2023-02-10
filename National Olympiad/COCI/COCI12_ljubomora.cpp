#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
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
    int n,m;cin >> n >> m;
    vi(int) a(m);
    for(auto &e:a) cin >> e;
    int l = 1,r = 1e9;
    while(l < r){
        int mid = (l+r)>>1;
        int cnt = 0;
        for(auto e:a){
            cnt+=((e+mid-1)/mid);
        }
        if(cnt <= n){
            r = mid;
        }
        else l = mid + 1;
    }
    cout << l;
    return 0;
}
