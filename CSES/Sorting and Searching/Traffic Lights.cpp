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
    int x,n;cin >> x >> n;
    set<int> traf;
    traf.insert(0);
    traf.insert(x);
    multiset<int> gap;
    gap.insert(x);
    for(int i=0;i<n;i++){
        int p;cin >> p;
        traf.insert(p);
        gap.insert(*(++traf.find(p))-p);
        gap.insert(p-*(--traf.find(p)));
        gap.erase((gap.find(*(++traf.find(p))-*(--traf.find(p)))));
        cout << *(--gap.end()) << ' ';
    }
    return 0;
}
