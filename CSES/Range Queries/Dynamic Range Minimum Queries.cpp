#include <bits/stdc++.h>
using namespace std;

#define ll long long int

template<class T> struct Segtree{
    T comp(T a,T b) {return min(a,b);}
    const T DEFAULT = 1e18;
    vector<T> t;
    int n;
    Segtree(int n) : t(2*n,DEFAULT),n(n){}
    void set(int p,T val){
        if(p < 0 || p >= n) return ;
        for(t[p+=n] = val;p > 1;p>>=1){t[p >> 1] = comp(t[p],t[p^1]);}
    }
    T qry(int l,int r){
        if(l < 0 || l >= n || r <= 0 || r < l) return 0;
        T res = DEFAULT;
        for(l+=n,r+=n;l < r;l >>= 1,r >>= 1){
            if(l&1) res = comp(res,t[l++]);
            if(r&1) res = comp(res,t[--r]);
        }
        return res;
    }
    
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,q;cin >> n >> q;
  Segtree<ll> segtree(n);
  for(int i=0;i<n;i++){
      int x;cin >> x;
      segtree.set(i,x);
  }
  while(q--){
      int opr;cin >> opr;
      if(opr == 1){
          int k,u;cin >> k >> u;
          segtree.set(k-1,u);
      }
      else{
          int l,r;cin >> l >> r;
          cout << segtree.qry(l-1,r) << '\n';
      }
  }
  return 0;
}
