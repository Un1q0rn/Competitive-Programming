#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

const int N = 1e8;
bool mark[N+10];
ll cnt = 1;
void sieve(){
    memset(mark,true,sizeof(mark));
    for(ll i=2;i*i<=N;i++){
        if(!mark[i]) continue;
        for(ll j=i+i;j<=N;j+=i){
            mark[j] = false;
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    sieve();
    for(int i=2;i<=N;i++){
        if(!mark[i])  continue;
        if(cnt%100 == 1) cout << i << '\n';
        cnt++;
    }
    return 0;
}
