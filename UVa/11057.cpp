#include <bits/stdc++.h> 
using namespace std; 

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n){
        vector<int> a(n);
        for(auto &e:a) cin >> e;
        sort(a.begin(),a.end());
        int x;cin >> x;
        int ans1,ans2,i=0,j=n-1;
        while(i < j){
            if(a[i]+a[j] < x){
                i++;
            }
            else if(a[i]+a[j] > x){
                j--;
            }
            else{
                ans1 = a[i];
                ans2 = a[j];
                i++,j--;
            }
        }
        cout << "Peter should buy books whose prices are " << ans1 << " and " << ans2 << ".\n";
        cout << endl;
    }
    return 0; 
}
