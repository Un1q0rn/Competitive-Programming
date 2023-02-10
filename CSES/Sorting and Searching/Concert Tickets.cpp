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
    multiset<int> s;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        s.insert(x);
    }
    while(m--){
        int t;cin >> t;
        if(s.upper_bound(t) != s.begin()){
            int a = *(--s.upper_bound(t));
            s.erase(--s.upper_bound(t));
            cout << a << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}
