#include <bits/stdc++.h>
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(a,b) for(int i=a;i<=b;i++)
#define vi(x)  vector<x>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

int a[310],n,w;
map<int,int> m;

void solve(){
    int n,w;cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++) if(a[i] <= w){
        if(a[i] <= w && !m[a[i]]){
            cnt++;
            m[a[i]] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j] <= w && !m[a[i]+a[j]]){
                cnt++;
                m[a[i]+a[j]] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ll sum = a[i]+a[j]+a[k];
                if(sum <= w && !m[sum]) cnt++,m[sum]=1;
            }
        }
    }
    cout << cnt ;
}

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    //int t;cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
