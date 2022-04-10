#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(6);
    int n;cin >> n;
    double ans = n;
    if(n==1) ans = 2;
    else if(n==3){
        ans = 2+sqrt(3); 
    }
    else if(n%2==1){
        ans = (n-3)+2*sqrt(3);
    }
    cout << ans;
    return 0;
}
