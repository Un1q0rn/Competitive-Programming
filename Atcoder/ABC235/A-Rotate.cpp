#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;cin >> s;
    int ans = 0;
    for(int i=0;i<3;i++){
        ans += ((s[(i)%3]-'0')*100)+((s[(i+1)%3]-'0')*10)+((s[(i+2)%3]-'0'));
    }
    cout << ans;
    return 0;
}

