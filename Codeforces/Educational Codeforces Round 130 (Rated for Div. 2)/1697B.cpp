#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
void solve(){
    int n;cin >> n;
    string s,t;cin >> s >> t;
    map<char,int> m1,m2;
    for(auto c:s) m1[c]++;
    for(auto c:t) m2[c]++;
    if(m1['a']!=m2['a'] || m1['b']!=m2['b'] || m1['c']!=m2['c']){
        cout << "NO\n";
        return ;
    }
    int j = 0;
    FOR(i,0,sz(s)-1){
        if(s[i] == 'b') continue;
        while(t[j] == 'b') j++;
        if(s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j)){
            cout << "NO\n";
            return ;
        }
        j++;
    }
    cout << "YES\n";
} 

bool multi = true;

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
