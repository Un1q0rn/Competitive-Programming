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
map<string,int> m;

void solve(){
    int n;cin >> n;
    int anscore=0,ansidx=0;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        int score;cin >> score;
        if(!m[s]){
            m[s] = 1;
            if(anscore < score){
                anscore = score;
                ansidx = i+1;
            }
        }
    }
    cout << ansidx << '\n';
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
