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
    int n;
    double L;
    cin >> n >> L;
    vector<pair<double,double>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a));
    auto len = [&](double a,double b){
        return sqrt(a*a - b*b);
    };
    double l = 0,r = 2e9;
    while(r - l > 0.000001){
        double mid = (l + r) / 2.0;
        double mn = 0,mx = 0;
        for(int i=0;i<n;i++){
            double le = a[i].first - len(mid,a[i].second),ri = a[i].first + len(mid,a[i].second);
            if(le <= mx){
                mx = max(mx,ri);
                mn = min(mn,le);
            }
        }
        if(mn <= 0 && mx >= L){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << setprecision(6) << fixed << r;
    return 0;
}
