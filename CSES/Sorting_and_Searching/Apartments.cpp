#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long int
#define all(x) x.begin(),x.end()
 
 
int main(){
    int n,m,k;cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for(auto &e:a){
        cin >> e;
    }
    for(auto &e:b){
        cin >> e;
    }
    sort(all(a));
    sort(all(b));
    int ans = 0;
    for(int i=0,j=0;i<n;i++){
        while(j<m && b[j] < a[i]-k){
            j++;
        }
        if(j<m && b[j] <= a[i]+k){
            j++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
