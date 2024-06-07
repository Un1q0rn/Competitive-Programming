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
struct A{
    int i1,j1,i2,j2;
    bool inside(A &o) {
		return (i1 >= o.i1 && i2 <= o.i2 && j1 >= o.j1 &&
		        j2 <= o.j2);
	}
    void print(){
        cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << '\n';
    }
};

const int N = 30;
int n;
char grid[N][N];
void print(int i1,int j1,int i2,int j2){
    for(int i=i1;i<=i2;i++){
        for(int j=j1;j<=j2;j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
int main() {
    setIO("where");
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    vector<A> pcl;
    for(int i1=1;i1<=n;i1++){
        for(int j1=1;j1<=n;j1++){
            for(int i2=i1;i2<=n;i2++){
                for(int j2=j1;j2<=n;j2++){
                    char c1='1',c2='1';
                    bool ch = true;
                    for(int k=i1;k<=i2 && ch;k++){
                        for(int l=j1;l<=j2 && ch;l++){
                            if(c1 == '1'){
                                c1 = grid[k][l];
                            }
                            else if(grid[k][l] != c1 && c2 == '1'){
                                c2 = grid[k][l];
                            }
                            else if(grid[k][l] != c1 && grid[k][l] != c2){
                                ch = false;
                            }
                        }
                    }
                    if(!ch) continue;
                    int cntc1 = 0,cntc2 = 0;
                    vector<vector<int>> vis(n+2,vector<int>(n+2));
                    for(int k=i1;k<=i2;k++){
                        for(int l=j1;l<=j2;l++){
                            if(vis[k][l]) continue;
                            cntc1 += (grid[k][l] == c1);
                            cntc2 += (grid[k][l] == c2);
                            vis[k][l] = 1;
                            queue<pair<int,int>> q;
                            q.push({k,l});
                            while(sz(q)){
                                int ni = q.front().first,nj = q.front().second;
                                q.pop();
                                for(int x=-1;x<=1;x++) for(int y=-1;y<=1;y++){
                                    if(abs(x) == abs(y)) continue;
                                    int ii = ni+x,jj = nj+y;
                                    if(ii < i1 || ii > i2 || jj < j1 || jj > j2) continue;
                                    if(vis[ii][jj] || grid[ii][jj] != grid[k][l]) continue;
                                    vis[ii][jj] = 1;
                                    q.push({ii,jj});
                                }
                            }
                        }
                    }
                    if((cntc1 == 1 && cntc2 >= 2) || (cntc2 == 1 && cntc1 >= 2)){
                        pcl.push_back({i1,j1,i2,j2});
                    }
                }
            }
        }
    }
    for(int i=0;i<sz(pcl);i++){
        int ch = 1;
        for(int j=0;j<sz(pcl);j++){
            if(i == j) continue;
            if(pcl[i].inside(pcl[j])){
                ch = 0;
                break;
            }
        }
        ans += ch;
    }
    cout << ans;
    return 0;
}
