#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e,mx;

    DSU(int n) : e(n, -1),mx(n){}

    int find(int i) {return e[i] < 0 ? i : e[i] = find(e[i]);}

    bool same(int a,int b) {return find(a) == find(b);}

    int size(int i) {return -e[find(i)];}

    bool unite(int a,int b){
        a = find(a),b = find(b);
        if(a == b) return false;
        if(e[a] > e[b]) swap(a,b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};
