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
const int N = 5e3+10;
int dp[2][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    string s1,s2;cin >> s1;
    s2 = s1;
    reverse(all(s2));
    int state = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                dp[state][j] = dp[state^1][j-1]+1;
            }
            else{
                dp[state][j] = max(dp[state^1][j],dp[state][j-1]);
            }
        }
        state^=1;
    }
    cout << n - dp[state^1][n];
    return 0;
}
