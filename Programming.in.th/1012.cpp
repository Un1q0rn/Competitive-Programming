#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    double sum =0 ;
    vector<double> a(5),v{1,0.75,0.5,0.25,0.125};
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            int x;cin >> x;
            a[j]+=x;
        }
    }
    for(int i=0;i<5;i++){
        sum+=(a[i]*v[i]);
    }
    cout << ceil(sum);
	return 0;
}
