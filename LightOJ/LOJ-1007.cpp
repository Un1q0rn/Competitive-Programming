#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

const int N = 5e6;
int phi[N+10];
ull pref[N+10];
void pre(){
    for(int i=1;i<=N;i++) phi[i] = i;
    for(int i=2;i<=N;i++){
        if(phi[i] == i){
            for(int j=i;j<=N;j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    for(int i=1;i<=N;i++){
        pref[i] = pref[i-1] + (ull)phi[i]*(ull)phi[i];
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int t;cin >> t;
    int c = t;
    while(t--){
        int a,b;cin >> a >> b;
        ull res = pref[b] - pref[a-1];
        cout << "Case " << c-t << ": " << res << '\n';
    }
    return 0;
}


