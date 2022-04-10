#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<pair<double,double>> a;
double ans;
double cal(double x1,double y1,double x2,double y2,double x3,double y3){
    return abs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)/2.0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    for(int i=0;i<n;i++){
        double x,y;cin >> x >> y;
        a.push_back({x,y});
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ans = max(ans,cal(a[i].f,a[i].s,a[j].f,a[j].s,a[k].f,a[k].s) );
            }
        }
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}
