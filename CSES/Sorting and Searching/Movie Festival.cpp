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
    int n;cin >> n;
    vector<pair<int,int>> event(n);
    for(auto &[x,y]:event){
        cin >> x >> y;
    }
    sort(all(event),[](auto &a,auto &b){
            if(a.second != b.second) return a.second < b.second;
            return a.first < b.first;
    });
    int last = -1,ans = 0;
    for(auto [x,y]:event){
        if(x >= last){
            ans++;
            last = y;
        }
    }
    cout << ans;
    return 0;
}
