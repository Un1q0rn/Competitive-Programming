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

int vis[3000][3000];
int main() {
    setIO("");
    int n;cin >> n;
    queue<pair<int,int>> q;
    auto addq = [&](int x, int y) { 
			if (!vis[x][y]) return;
			int cnt = 0;
            for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
                if(abs(i) == abs(j)) continue;
				cnt += vis[x+i][y+j];
            }
			if (cnt == 3)
				for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++) {
                    if(abs(i) == abs(j)) continue;
					if (!vis[x + i][y + j])
						q.push({x + i,y + j});
				}
	};
    int total = 0;
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        x += 1000,y += 1000;
        q.push({x,y});
        while(sz(q)){
            int nx = q.front().first,ny = q.front().second;
            q.pop();
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            total++;
            addq(nx,ny);
            for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++){
                if(abs(k) == abs(l)) continue;
                addq(nx + k,ny + l);
            }
        }
        cout << total - i - 1 << '\n';
    }
    return 0;
}
 
