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

void solve(){
    string s;cin >> s;
    if(sz(s) == 1){
        for(int i=0;i<6;i++) cout << s;
    }
    else if(sz(s) == 2){
        for(int i=0;i<3;i++) cout << s;
    }
    else if(sz(s) == 3){
        for(int i=0;i<2;i++) cout << s;
    }
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
