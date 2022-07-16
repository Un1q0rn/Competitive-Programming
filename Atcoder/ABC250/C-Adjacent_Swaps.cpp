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
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int
const int MOD = 1e9+7;
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
const int N = 2e5+10;
int a[N],pos[N];
void solve(){
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++){
        a[i] = i;
        pos[i] = i;
    }
    while(q--){
        int x;cin >> x;
        if(pos[x]+1 <= n){
            int tmp = a[pos[x]+1];
            swap(a[pos[x]],a[pos[x]+1]);
            pos[x]++;
            pos[tmp]--;
        }
        else{
            int tmp = a[pos[x]-1];
            swap(a[pos[x]],a[pos[x]-1]);
            pos[x]--;
            pos[tmp]++;
        }
        
    }
    for(int i=1;i<=n;i++) cout << a[i] << ' ';
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
