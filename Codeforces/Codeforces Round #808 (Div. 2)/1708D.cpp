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
#define ll long long int
const int mod = 1e9+7;
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
const int N = 1e5+10;
int a[N];
void solve(){
    int n;cin >> n;
    FOR(i,1,n){
        cin >> a[i];
    }
    ROF(i,n-1,1){
        int pre = a[i+1],ch = 0;
        ROF(j,i,1){
            ch = (a[j]==0);
            pre-=(a[j]=pre-a[j]);
            if(ch){
                sort(a+j,a+i+1);
                break;
            }
        }
        if(!ch){
            sort(a+1,a+n+1);
        }
    }
    cout << a[1] << '\n';
} 

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t;cin >> t;
    //int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
