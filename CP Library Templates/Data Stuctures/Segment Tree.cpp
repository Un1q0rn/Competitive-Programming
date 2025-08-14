#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int inf = 1e9;
template<typename T>
struct SegTree{
    int n;
    vector<T> t,a;
    SegTree(vector<T>& s): a(s){
        n = sz(a);
        t.resize(4 * n);
        build(0,n-1,0);
    }

    T merge(T a,T b){
        return min(a,b);
    }

    void build(int l,int r,int i){
        if(l == r){
            t[i] = a[l];
            return ;
        }
        int m = l + ((r - l) >> 1);
        int nl = i * 2 + 1;
        int nr = i * 2 + 2;
        build(l,m,nl);
        build(m + 1,r,nr);
        t[i] = merge(t[nl],t[nr]);
    }

    void upd(int l,int r,int i,int x,T v){
        if(l == r){
            s[i] = v;
            return ;
        }
        int m = (l + r) >> 1;
        int nl = i * 2 + 1;
        int nr = i * 2 + 2;
        upd(l,m,nl,x,v);
        upd(m + 1,r,nr,x,v);
        t[i] = merge(t[nl],t[nr]);
    }

    T qry(int l,int r,int i,int lx,int rx){
        if(r < lx || l > rx) return inf;
        if(lx <= l && r <= rx){
            return t[i];
        }
        int m = l + ((r - l) >> 1);
        int nl = i * 2 + 1;
        int nr = i * 2 + 2;
        return min(qry(l,m,nl,lx,rx),qry(m + 1,r,nr,lx,rx));
    }

};

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    SegTree s(a);
    return 0;
}
