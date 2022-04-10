#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,l,k,c;cin >> n >> m >> l >> k >> c;
    int sum = 0;
    for(int i=0;i<n*m;i++){
        int x;cin >> x;
        sum+=x;
    }
    sum += l*c*k;
    sum/=c;
    sum+=(sum%c==0)?0:1;
    cout << sum;
    return 0;
}
