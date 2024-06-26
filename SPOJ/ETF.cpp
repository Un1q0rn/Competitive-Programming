#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

const int N = 1e6;
int phi[N+10];
void pre(){
    for(int i=1;i<=N;i++) phi[i] = i;
    for(int i=2;i<=N;i++){
        if(phi[i] == i){
            for(int j=i;j<=N;j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    pre();
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        cout << phi[n] << '\n';
    }
    return 0;
}

