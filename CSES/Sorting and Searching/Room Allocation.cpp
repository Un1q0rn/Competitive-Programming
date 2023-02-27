#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
struct A{
    int l,r,idx;
    bool operator < (const A&o) const{
        return l < o.l;
    }
};
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;cin >> n;
    auto cmp = [](auto a,auto b){return a.second < b.second;};
    multiset<pair<int,int>,decltype(cmp)> booked(cmp);
    int now = 0;
    vi(int) ans(n);
    vi(A) qry(n);
    for(int i=0;i<n;i++){
        int l,r;cin >> l >> r;
        qry[i] = {l,r,i};
    }
    sort(all(qry));
    for(int i=0;i<n;i++){
        int l = qry[i].l,r = qry[i].r,idx = qry[i].idx;
        if(sz(booked) && l > booked.begin()->second){
            booked.insert({booked.begin()->first,r});
            ans[idx] = booked.begin()->first;
            booked.erase(booked.begin());
        }
        else{
            now++;
            booked.insert({now,r});
            ans[idx] = now;
        }
    }
    cout << now << '\n';
    for(auto e:ans) cout << e << ' ';
    return 0;
}
