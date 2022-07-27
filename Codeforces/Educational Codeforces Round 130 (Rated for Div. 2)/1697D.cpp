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
    auto ask1 = [&](int l,int r){
        cout << "? 2 " << l+1 << ' ' << r+1 << endl;
        int x;cin >> x;
        return x;
    };
    auto ask2 = [&](int i){
        cout << "? 1 " << i+1 << endl;
        char c;cin >> c;
        return c;
    };
    string s = "";
    vi(int) a;
    FOR(i,0,n-1){
        sort(all(a));
        int lo = -1;
        int hi = sz(a)-1;
        while(lo < hi){
            int mid = (lo+hi+1) >> 1;
            if(ask1(a[mid],i) == sz(a)-mid){
                lo = mid;
            }
            else hi = mid-1;
        }
        if(lo == -1){
            s+=ask2(i);
            a.pb(i);
        }
        else{
            s+=s[a[lo]];
            a[lo] = i;
        }
    }
    cout << "! " << s << endl;
} 

bool multi = false;

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
