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
const int N = 15;
const int M = 1e7+100;
ll n,m,x;
ll l[N],a[N],s[M],t[N],q[N];
bool solve(int t){
    vector<int> mark(n+2);
    for(int i=1;i<=n;i++){
        int checkq= 0;
        for(int j=1;j<=n;j++){
            if(mark[j]) continue;
            int cnt=0,ch=1,le=q[i],ri=q[i+1];
            while(le<ri){
                int idx = upper_bound(s+1,s+ri,l[j]-a[i]+s[le-1])-s;
                cnt++;
                if(cnt > t) ch = 0;
                le = idx;
            }
            if(ch){
                mark[j] = 1;
                checkq = 1;
                break;
            }
        }
        if(!checkq) return false;
    }
    return true;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x;
    for(int i=1;i<=n;i++) cin >> l[i];
    sort(l+1,l+n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++){
        cin >> s[i];
        s[i]+=s[i-1];
    }
    for(int i=1;i<=x;i++) cin >> t[i];
    for(int i=1;i<=x;i++){
        for(int j=1;j<=n;j++){
            cin >> q[j];
        }
        q[n+1] = m;
        int ch = 0;
        do{
            if(solve(t[i])){
                ch = 1;
                break;
            }
        }while(next_permutation(a+1,a+n+1));
        if(ch) cout << "P\n";
        else cout << "F\n";
    }
    return 0;
}
