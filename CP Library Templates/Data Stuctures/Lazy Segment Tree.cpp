#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

template<typename T>
struct SegTree{
    #define nl (i * 2 + 1)
    #define nr (i * 2 + 2)
    int n;
    vector<T> t,a,lazy;
    SegTree(vector<T>& s): a(s){
        n = sz(a);
        t.resize(4 * n);
        lazy.resize(4 * n);
        build(0,n-1,0);
    }

    T merge(T b,T c){
        return b + c;
    }

    void push(int i,int l,int r){
        if(lazy[i] == 0 || l == r) return;

        int m = l + ((r - l) >> 1);
        int len1 = m - l + 1;
        int len2 = r - m;

        t[nl] += lazy[i] * len1;
        t[nr] += lazy[i] * len2;
        lazy[nl] += lazy[i];
        lazy[nr] += lazy[i];
        lazy[i] = 0;
    }

    void build(int l,int r,int i){
        if(l == r){
            t[i] = a[l];
            return ;
        }
        int m = l + ((r - l) >> 1);
        build(l,m,nl);
        build(m + 1,r,nr);
        t[i] = merge(t[nl],t[nr]);
    }

    void upd(int l,int r,int i,int lx,int rx,T v){
        if (r < lx || l > rx) {
            return;
        }
        if (lx <= l && r <= rx) {
            int len = r - l + 1;
            t[i] += v * len;
            lazy[i] += v;
            return;
        }
        push(i,l,r);
        int m = l + ((r - l) >> 1);
        upd(l,m,nl,lx,rx,v);
        upd(m + 1,r,nr,lx,rx,v);
        t[i] = merge(t[nl],t[nr]);
    }

    void upd(int lx, int rx, T v) {
        upd(0,n-1,0,lx,rx,v);
    }

    T qry(int l,int r,int i,int lx,int rx){
        if(r < lx || l > rx) return 0;
        if(lx <= l && r <= rx){
            return t[i];
        }
        push(i,l,r);
        int m = l + ((r - l) >> 1);
        return merge(qry(l,m,nl,lx,rx),qry(m + 1,r,nr,lx,rx));
    }

    T qry(int lx,int rx){
        return qry(0,n-1,0,lx,rx);
    }
};

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n,m;cin >> n >> m;
    vector<ll> a(n);
    SegTree s(a);
    while(m--){
        int t,l,r;cin >> t >> l >> r;
        if(t == 1){
            int v;cin >> v;
            s.upd(l,r - 1,v);
        }
        else{
            cout << s.qry(l,r - 1) << '\n';
        }
    }
    return 0;
}
