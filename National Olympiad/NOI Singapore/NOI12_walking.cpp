#include <bits/stdc++.h>
using namespace std;
 
#define ld long double 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    double l;int n;
    cin >> l >> n;
    vector<pair<double,double>> a(n);
    for(auto &[x,y]:a){
        cin >>x >> y;
    }
    sort(a.rbegin(),a.rend());
    vector<double> lis;
    for(auto [x,y]:a){
        double t = x + l/y;
        auto it = lower_bound(all(lis),t) - lis.begin();
        if(it != sz(lis)){
            lis[it] = t;
        }
        else lis.push_back(t);
    }
    cout << sz(lis);
    return 0;
}
