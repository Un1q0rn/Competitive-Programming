#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
const int N = 1e3+10;
struct A{
    int i,j,s;
};
const int di[4] = {-1,1,0,0},dj[4] = {0,0,-1,1};
char a[N][N];
int vis[N][N],pa[N][N];
queue<A> q;
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n,m;cin >> n >> m;
    int si,sj;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == 'A'){
                si = i;
                sj = j;
            }
            if(a[i][j] == 'M'){
                q.push({i,j,2});
                vis[i][j] = 1;
            }
            if(a[i][j] == '#') vis[i][j] = 1;
        }
    }
    q.push({si,sj,1});
    vis[si][sj] = 1;
    while(sz(q)){
        int ni = q.front().i,nj = q.front().j,s = q.front().s;
        q.pop();
        for(int i=0;i<4;i++){
            int ii = ni+di[i],jj = nj+dj[i];
            if(ii < 1 || ii > n || jj < 1 || jj > m){
                if(s == 1){
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
                    cout << ns;
                    return 0;
                }
                continue;
            }
            if(vis[ii][jj]) continue;
            vis[ii][jj] = 1;
            q.push({ii,jj,s});
            if(s == 1) pa[ii][jj] = i;
        }
    }
    cout << "NO";
    return 0;
}
