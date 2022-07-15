#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ui unsigned int 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()
const int N = 2017;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> a(n);
    map<int,int> m;
    int now=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
    }
    sort(all(a));
    for(int i=0;i<n;i++){
        if(m[a[i]] > 1) continue;
        if(abs(N-a[i]) < abs(N-now)){
            now = a[i];
        }
    }
    if(!now) cout << -1;
    else cout << now;
    return 0;
}
