#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
char a[1010][1010];
int n,vis[1010][1010],sz,parm,cntsz,cntparm;
void floodfill(int ni,int nj){
    if(ni < 1 || ni > n || nj < 1 || nj > n){
        cntparm++;
        return ;
    }
    if(a[ni][nj] == '.'){
        cntparm++;
        return ;
    }
    if(vis[ni][nj]) return ;
    vis[ni][nj] = 1;
    cntsz++;
    for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
        if(abs(i) == abs(j)) continue;
        floodfill(ni+i,nj+j);
    }
}
int main() {
    setIO("perimeter");
    cin >> n;
    FOR(i,1,n){
        FOR(j,1,n){
            cin >> a[i][j];
        }
    }
    FOR(i,1,n){
        FOR(j,1,n){
            if(!vis[i][j] && a[i][j] == '#'){
                cntsz = cntparm = 0;
                floodfill(i,j);
                if(cntsz >= sz){
                    sz = cntsz;
                    parm = cntparm;
                }
            }
        }
    }
    cout << sz << ' ' << parm;
    return 0;
}
