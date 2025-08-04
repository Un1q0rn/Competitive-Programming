#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()

const int N = 4e5 + 100;
const int inf = 1e9;
int a[N],s[4 * N];
vector<int> c;

void build(int l,int r,int i){
    if(l == r){
        s[i] = 0;
        return ;
    }
    int mid = (l+r)>>1;
    build(l,mid,i*2+1);
    build(mid+1,r,i*2+2);
    s[i] = s[i*2+1] + s[i*2+2];
}
void upd(int l,int r,int i,int x,int v){
    if(l == r){
        s[i] += v;
        return ;
    }
    int mid = (l+r)>>1;
    if(x <= mid) upd(l,mid,i*2+1,x,v);
    else upd(mid+1,r,i*2+2,x,v);
    s[i] = s[i*2+1] + s[i*2+2];
}

int qry(int l,int r,int i,int lx,int rx){
    if(r < lx || l > rx) return 0;
    if(lx <= l && r <= rx){
        return s[i];
    }
    int mid = (l+r)>>1;
    return (qry(l,mid,i*2+1,lx,rx)+qry(mid+1,r,i*2+2,lx,rx));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,Q;cin >> n >> Q;
    for(int i=0;i<n;i++){
        cin >> a[i];
        c.push_back(a[i]);
    }

    vector<tuple<char,int,int>> q(Q);
    for(auto &[op,x,y]:q){
        cin >> op >> x >> y;
        if(op == '!') c.push_back(y);
    }

    sort(all(c));
    c.erase(unique(all(c)),c.end());

    for(int i=0;i<n;i++){
        int idx = lower_bound(all(c),a[i]) - c.begin();
        upd(0,sz(c) - 1,0,idx,1);
    }
    for(auto [op,x,y]:q){
        if(op == '?'){
            int idxa = lower_bound(all(c),x) - c.begin();
            int idxb = upper_bound(all(c),y) - c.begin();
            cout << qry(0,sz(c) - 1,0,idxa,idxb - 1) << '\n';
        }
        else{
            int idxa = lower_bound(all(c),a[x - 1]) - c.begin();
            upd(0,sz(c) - 1,0,idxa,-1);
            a[x - 1] = y;
            int idxb = lower_bound(all(c),y) - c.begin();
            upd(0,sz(c) - 1,0,idxb,1);
        }
    }
    return 0;
}
