#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()
#define ul unsigned long long

template<typename T>
struct SegTree{
    int n;
    T t[4 * n];
    T inf;
    function<T(T,T)> op;
    SegTree(int sz,T val,function<T(T,T)> f){
        memset(t,0,sizeof t);
        n = sz;
        inf = val;
        op = f;
    }

    void build(int l,int r,int i){
        if(l == r){
            t[i] = a[l];
            return ;
        }
        int m = (l + r) >> 1;
        int nl = i * 2 + 1;
        int nr = i * 2 + 2;
        build(l,m,nl);
        build(m + 1,r,nr);
        t[i] = op(t[nl],t[nr]);
    }

    T upd(int l,int r,int i,int x,T v){
        if(l == r){
            s[i] = v;
            return ;
        }
        int m = (l + r) >> 1;
        int nl = i * 2 + 1;
        int nr = i * 2 + 2;
        upd(l,m,nl,x,v);
        upd(m + 1,r,nr,x,v);
        return t[i] = op(t[nl],t[nr]);
    }

    T qry(int l,int r,int i,int lx,int rx){
        if(r < lx || l > rx) return inf;
        if(lx <= l && rx <= r){
            return t[i];
        }
        int m = (l + r) >> 1;
        int nl = i * 2 + 1;
        int nr = i * 2 + 2;
        return op(qry(l,m,nl,lx,rx),qry(m + 1,r,nr,lx,rx));
    }

};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}
