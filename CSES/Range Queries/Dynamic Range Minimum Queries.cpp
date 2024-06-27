#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const int inf = 1e9;
int a[N],s[N<<1];

void build(int l,int r,int i){
    if(l == r){
        s[i] = a[l];
        return ;
    }
    int m = (l+r)>>1;
    build(l,m,i*2+1);
    build(m+1,r,i*2+2);
    s[i] = min(s[i*2+1],s[i*2+2]);
}
int upd(int l,int r,int i,int x,int v){
    if(x > r || x < l) return inf;
    if(l == r){
        return s[i] = v;
    }
    int m = (l+r)>>1;
    upd(l,m,i*2+1,x,v);
    upd(m+1,r,i*2+2,x,v);
    return s[i] = min(s[i*2+1],s[i*2+2]);
}

int qry(int l,int r,int i,int lx,int rx){
    if(r < lx || l > rx) return inf;
    if(lx <= l && r <= rx){
        return s[i];
    }
    int m = (l+r)>>1;
    return min(qry(l,m,i*2+1,lx,rx),qry(m+1,r,i*2+2,lx,rx));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    build(0,n-1,0);
    while(m--){
        int t;cin >> t;
        if(t == 1){
            int i,v;cin >> i >> v;
            upd(0,n-1,0,i-1,v);
        }
        else{
            int l,r;cin >> l >> r;
            cout << qry(0,n-1,0,l-1,r-1) << '\n';
        }
    }
    return 0;
}
