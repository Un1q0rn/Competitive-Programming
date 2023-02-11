#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
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
    cout << ans;
    return 0;
}
