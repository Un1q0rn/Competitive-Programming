#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define pf push_front
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
void solve(){
    int n;cin >> n;
    vector<string> s(n);
    for(auto &e:s) cin >> e;
    for(int i=0;i<n;i++){
        if(s[i][0] == 'H' || s[i][0] == 'D' || s[i][0] == 'C' || s[i][0] == 'S' ) {
            continue;
        }
        else{
            cout << "No";
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(isdigit(s[i][1])){
            int x = s[i][1]-'0';
            if(x >= 2 && x <= 9){
                continue;
            }
            else{
                cout << "No";
                return;
            }
        }
        else{
            if(s[i][1] == 'A' || s[i][1] == 'T' || s[i][1] == 'J' || s[i][1] == 'Q' || s[i][1] == 'K'){
                continue;
            }
            else{
                cout << "No";
                return ;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i] == s[j]){
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
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
