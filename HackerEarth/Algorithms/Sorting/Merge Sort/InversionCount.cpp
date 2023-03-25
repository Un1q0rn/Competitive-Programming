#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ui unsigned int 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()
vector<int> a;
int n;
ll ans;
void merge(int l,int mid,int r){
    int p = l,q = mid+1;
    vector<int> b(r-l+1);
    int k = 0;
    for(int i=l;i<=r;i++){
        if(p > mid){
            b[k++] = a[q++];
        }
        else if(q > r){
            b[k++] = a[p++];
        }
        else if(a[p] <= a[q]){
            b[k++] = a[p++];
        }
        else{
            b[k++] = a[q++];
            ans += (r-q+1);
        }
    }
    for(int i=0;i<k;i++){
        a[l++] = b[i];
    }
}
void merge_sort(int l,int r){
    if(l >= r) return ;
    int mid = l+((r-l)>>1);
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,mid,r);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    for(auto &e:a) cin >> e;
    merge_sort(0,n-1);
    cout << ans;
    return 0; 
}



