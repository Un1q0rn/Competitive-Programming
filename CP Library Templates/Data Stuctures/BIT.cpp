#include <bits/stdc++.h>

using namespace std;

template <class T>
struct BIT{
    vector<T> f;
    int size;
    BIT(int n) :size(n), f(n+1){}
  
    void upd(int i,T v){
        i++;
        while(i <= n){
            f[i]+=v;
            i += i & -i;
        }
    }

    T qry(int i){
        i++;
        T res = 0;
        while(i > 0){
            res += f[i];
            i -= i & -i;
        }
        return res;
    }
};
