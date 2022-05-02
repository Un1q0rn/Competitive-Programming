#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int w,h,n;cin >> w >> h >> n;
    vector<int> b(w,0);
    for(int i=0;i<n;i++){
        int x,a;cin >> x >> a;
        for(int j=x;j<min(x+a,w);j++){
            b[j]++;
        }
    }
    int ans1 = 0,ans2 = 0;
    for(int i=0;i<w;i++){
        if(b[i] == 0) ans1++;
        if(b[i] == 1) ans2++;
    }
    cout << ans1*h << " " << ans2*h;
	return 0;
}
