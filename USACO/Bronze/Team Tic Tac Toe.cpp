#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("tttt");
    vector<char> a(9);
    map<char,int> w;
    map<set<char>,int> team;
    FOR(i,0,8){
        cin >> a[i];
        w[a[i]]=1;
    }
    int indi = 0,doub=0;
    for(int i=0;i<=6;i+=3){
        set<char> s;
        FOR(j,0,2) s.insert(a[i+j]);
        if(sz(s) == 1 && w[a[i]]){
            w[a[i]] = 0;
            indi++;
        }
        if(sz(s) == 2 && !team[s]){
            team[s] = 1;
            doub++;
        }
    }
    FOR(i,0,2){
        set<char> s;
        for(int j=0;j<=6;j+=3) s.insert(a[i+j]);
        if(sz(s) == 1 && w[a[i]]){
            w[a[i]] = 0;
            indi++;
        }
        if(sz(s) == 2 && !team[s]){
            team[s] = 1;
            doub++;
        }
    }
    if((a[0] == a[4] && a[4] == a[8]) && w[a[0]]){
        w[a[0]] = 0;
        indi++;
    }
    if((a[2] == a[4] && a[4] == a[6]) && w[a[0]]){
        w[a[0]] = 0;
        indi++;
    }
    set<char> s;
    s.insert(a[0]);s.insert(a[4]);s.insert(a[8]);
    if(sz(s) == 2 && !team[s]){
        team[s] = 1;
        doub++;
    }
    s.clear();
    s.insert(a[2]);s.insert(a[4]);s.insert(a[6]);
    if(sz(s) == 2 && !team[s]){
        team[s] = 1;
        doub++;
    }
    cout << indi << '\n' << doub;
    return 0;
}
