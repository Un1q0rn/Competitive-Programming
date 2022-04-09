#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    ll n,sum1 = 0,sum2 = 0,a;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> a;
        sum1 = sum1 + a;
    }
    for(int i=1;i<=n;i++){
        sum2 = sum2 + i;
    }
    cout << sum2 - sum1;
    return 0;
}
