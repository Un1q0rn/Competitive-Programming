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
const int N = 1e3+10;
char a[N][N];
int vis[N][N],pa[N][N];
int di[4]={-1,1,0,0},dj[4] = {0,0,-1,1};
struct A{
    int i,j;
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    queue<A> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }
    while(sz(q)){
        int ni = q.front().i,nj = q.front().j;
        if(a[ni][nj] == 'B'){
            cout << "YES\n";
            int ii = ni,jj = nj,cnt = 0;
            string ns;
            while(a[ii][jj] != 'A'){
                if(pa[ii][jj] == 0){
                    ii+=1;
                    ns+='U';
                }
                else if(pa[ii][jj] == 1){
                    ii-=1;
                    ns+='D';
                }
                else if(pa[ii][jj] == 2){
                    jj+=1;
                    ns+='L';
                }
                else{
                    jj-=1;
                    ns+='R';
                }
                cnt++;
            }
            cout << cnt << '\n';
            reverse(all(ns));
            for(auto c:ns) cout << c;
            return 0;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int ii = ni+di[i],jj = nj+dj[i];
            if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
            if(a[ii][jj] == '#') continue;
            if(vis[ii][jj]) continue;
            vis[ii][jj] = 1;
            q.push({ii,jj});
            pa[ii][jj] = i;
        }
    }
    cout << "NO";
    return 0;
}
