#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

const int N = 550;
int a[N][N],u[N][N],l[N][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q=2,m,n,ans,k;
    while(q--){
        memset(a,0,sizeof a);
        memset(u,0,sizeof u);
        memset(l,0,sizeof l);
        ans = 0;
        cin >> n >> m >> k;
        while(k--){
            int i,j;cin >> i >> j;
            a[i+1][j+1] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]) continue;
                l[i][j] = l[i][j-1]+1;
                u[i][j] = u[i-1][j]+1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;;k++){
                    if(i-k<0||j-k<0) break;
                    if(a[i-k+1][j]==1 || a[i][j-k+1]==1) break;
                    if(u[i][j-k+1]>=k&&l[i-k+1][j]>=k) ans = max(ans,k);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
