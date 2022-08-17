#include <bits/stdc++.h>
using namespace std;
const int N = 30;
char a[N][N];
int vis[N][N],n;
void dfs(int ni,int nj){
    vis[ni][nj] = 1;
    for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
        if(!i && !j) continue;
        int ii = ni+i,jj = nj+j;
        if(ii < 1 || ii > n || jj < 1 || jj > n) continue;
        if(a[ii][jj] == '0' || vis[ii][jj]) continue;
        dfs(ii,jj);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c = 1;
    while(cin >> n){
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(vis[i][j] || a[i][j] == '0') continue;
                dfs(i,j);
                ans++;
            }
        }
        cout << "Image number " << c << " contains " << ans << " war eagles.\n";
        c++;
        memset(vis,0,sizeof vis);
    }
    return 0;
}
