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
    vector<int> a(n),b(m);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;
    sort(all(a),greater<int>());sort(all(b),greater<int>());
    if(n>m){
        swap(a,b);
        swap(n,m);
    }
    int l = 0,r = 1e9+10;
    while(l < r){
        int mid = (l+r)>>1;
        int p = 0,ok = 1,i;
        for(i=0;i<n;i++){
            while(p<m && abs(a[i]-b[p]) > mid) p++;
            if(p>m-1){
                ok = 0;
                break;
            }
            p++;
        }
        if(ok && i == n){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << r;
    return 0;
}
