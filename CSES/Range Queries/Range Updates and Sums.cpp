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
    vector<T> t,a,lazy_add,lazy_set;
    SegTree(vector<T>& s): a(s){
        n = sz(a);
        t.resize(4 * n);
        lazy_add.resize(4 * n);
        lazy_set.resize(4 * n);
        build(0,n-1,0);
    }

    T merge(T b,T c){
        return b + c;
    }
    
    void set(int i,int l,int r,T v){
        int len = r - l + 1;
        t[i] = v * len;
        lazy_set[i] = v;
        lazy_add[i] = 0;
    }

    void add(int i,int l,int r,T v){
        int len = r - l + 1;
        t[i] += v * len;
        if(lazy_set[i] != 0){
            lazy_set[i] += v;
        }
        else lazy_add[i] += v;

    }

    void push(int i,int l,int r){
        if(lazy_set[i] == 0 && lazy_add[i] == 0){
            return ;
        }
        int m = l + ((r - l) >> 1);
        if(lazy_set[i] != 0){
            set(nl,l,m,lazy_set[i]);
            set(nr,m + 1,r,lazy_set[i]);
            lazy_set[i] = 0;
        }
        if(lazy_add[i] != 0){
            add(nl,l,m,lazy_add[i]);
            add(nr,m + 1,r,lazy_add[i]);
            lazy_add[i] = 0;
        }
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

    void upd_add(int l,int r,int i,int lx,int rx,T v){
        if (r < lx || l > rx) {
            return;
        }
        if (lx <= l && r <= rx) {
            add(i,l,r,v);
            return;
        }
        push(i,l,r);
        int m = l + ((r - l) >> 1);
        upd_add(l,m,nl,lx,rx,v);
        upd_add(m + 1,r,nr,lx,rx,v);
        t[i] = merge(t[nl],t[nr]);
    }

    void upd_add(int lx, int rx, T v) {
        upd_add(0,n-1,0,lx,rx,v);
    }

    void upd_set(int l,int r,int i,int lx,int rx,T v){
        if (r < lx || l > rx) {
            return;
        }
        if (lx <= l && r <= rx) {
            set(i,l,r,v);
            return;
        }
        push(i,l,r);
        int m = l + ((r - l) >> 1);
        upd_set(l,m,nl,lx,rx,v);
        upd_set(m + 1,r,nr,lx,rx,v);
        t[i] = merge(t[nl],t[nr]);
    }

    void upd_set(int lx, int rx, T v) {
        upd_set(0,n-1,0,lx,rx,v);
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
    int n,q;cin >> n >> q;
    vector<ll> a(n);
    for(auto &e:a) cin >> e;
    SegTree<ll> s(a);
    while(q--){
        int t,l,r;cin >> t >> l >> r;
        l--,r--;
        if(t == 1){
            ll v;cin >> v;
            s.upd_add(l,r,v);
        }
        else if(t == 2){
            ll v;cin >> v;
            s.upd_set(l,r,v);
        }
        else{
            cout << s.qry(l,r) << '\n';
        }
    }
    return 0;
}
