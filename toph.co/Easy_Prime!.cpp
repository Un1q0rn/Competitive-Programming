#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int N = 1e7;
const int M = 1e5+10;
int prime[N+100],n,a[M],fw[M];
void sieve(){
    for(int i=3;i<=N;i+=2){
        prime[i] = 1;
    }
    prime[2] = 1;
    for(int i=3;i*i<=N;i+=2){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i){
                prime[j] = 0;
            }
        }
    }
}
void upd(int idx,int val){
    while(idx<=n){
        fw[idx]+=val;
        idx+=idx&(-idx);
    }
}
int read(int idx){
    int ans = 0;
    while(idx>0){
        ans+=fw[idx];
        idx-=(idx&-idx);
    }
    return ans;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    sieve();
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(prime[a[i]]){
            upd(i,1);
        }
    }
    int q;cin >> q;
    while(q--){
        int opr;cin >> opr;
        if(opr == 1){
            int l,r;cin >> l >> r;
            cout << read(r)-read(l-1) << '\n';
        }
        else{
            int idx,val;cin >> idx >> val;
            if(prime[a[idx]] && prime[val])  continue;
            if(!prime[a[idx]] && prime[val]) upd(idx,1);
            if(prime[a[idx]] && !prime[val]) upd(idx,-1);
            a[idx] = val;
        }
    }
    return 0;
}

