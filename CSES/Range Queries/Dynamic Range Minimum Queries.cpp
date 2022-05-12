#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
 
const int N = 1 << 18;
 
int a[N],s[N << 1];
int n,q;
void build(int l,int r,int idx)
{
    if(l==r){ s[idx] = a[l]; return; }
    int m = (l+r)/2;
    build(l,m,idx*2);
    build(m+1,r,idx*2+1);
    s[idx] = min(s[idx*2],s[idx*2+1]);
}
 
void update(int l,int r,int idx,int x,int val)
{
    if(x<l or x>r) return;
    if(l==r){ s[idx]=val; return; }
    int m = (l+r)/2;
    update(l,m,idx*2,x,val);
    update(m+1,r,idx*2+1,x,val);
    s[idx] = min(s[idx*2],s[idx*2+1]);
}
 
int query(int l,int r,int idx,int x,int y)
{
    if(x>r or y<l) return INT_MAX;
    if(x<=l and y>=r) return s[idx];
    int m = (l+r)/2;
    return min(query(l,m,idx*2,x,y),query(m+1,r,idx*2+1,x,y));
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,n,1);
    while(q--){
        int i,a,b;cin >> i >> a >> b;
        if(i == 1){
            update(1,n,1,a,b);
        }
        else{
            cout << query(1,n,1,a,b) << '\n';
        }
    }
    return 0;
}
