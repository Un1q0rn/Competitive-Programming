#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> a(256,0),l(n),h(n),r(n);
    int mxd = 0;
    for(int i=0;i<n;i++){
        cin >> l[i] >> h[i] >> r[i];
        for(int j=l[i];j<r[i];j++) a[j] = max(a[j],h[i]);
        mxd = max(mxd,r[i]);
    }
    int now = 0;
    for(int i=1;i<=mxd;i++){
        if(a[i]!=now){
            cout << i << " " << a[i] << " ";
            now = a[i];
        }
    }
	return 0;
}
