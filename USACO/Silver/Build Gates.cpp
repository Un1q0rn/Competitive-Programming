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

int main() {
    setIO("gates");
    int n;cin >> n;
    string s;cin >> s;
    vector<vector<bool>> vis(4010,vector<bool>(4010)),fence(4010,vector<bool>(4010));
    int x = 2002,y = 2002;
    auto dir = [&](int x,int y,char c){
        if(c == 'N'){
            x++;
        }
        else if(c == 'S'){
            x--;
        }
        else if(c == 'E'){
            y++;
        }
        else{
            y--;
        }
        return make_pair(x,y);
    };
    int mnx = x,mxx = x,mny = y,mxy = y;
    for(auto c:s){
        x = dir(x,y,c).first;
        y = dir(x,y,c).second;
        fence[x][y] = 1;
        x = dir(x,y,c).first;
        y = dir(x,y,c).second;
        fence[x][y] = 1;
        mnx = min(mnx,x);
        mxx = max(mxx,x);
        mny = min(mny,y);
        mxy = max(mxy,y);
    }
    mnx--;
    mxx++;
    mny--;
    mxy++;
    int ans = 0;
    queue<pair<int,int>> q;
    for(int i=mnx;i<=mxx;i++){
        for(int j=mny;j<=mxy;j++){
            if(vis[i][j] || fence[i][j]) continue;
            ans++;
            vis[i][j] = 1;
            q.push({i,j});
            while(sz(q)){
                int ni = q.front().first,nj = q.front().second;
                q.pop();
                for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++){
                    if(abs(k) == abs(l)) continue;
                    int ii = ni + k, jj = nj + l;
                    if(ii < mnx || ii > mxx || jj < mny || jj > mxy) continue;
                    if(vis[ii][jj] || fence[ii][jj]) continue;
                    vis[ii][jj] = 1;
                    q.push({ii,jj});
                }
            }
        }
    }
    cout << ans - 1;
    return 0;
}
