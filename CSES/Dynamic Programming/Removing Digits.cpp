#include <bits/stdc++.h>
using namespace std;
 
#define ld long double 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> d(1e6+10,-1);
    queue<int> q;
    q.push(n);
    d[n] = 0;
    while(sz(q)){
        int x = q.front();
        q.pop();
        int k = x;
        while(k > 0){
            if(d[x - (k % 10)] == -1){
                d[x - (k % 10)] = d[x] + 1;
                q.push(x - (k % 10));
            }
            k /= 10;
        }
    }
    cout << d[0];
    return 0;
}
