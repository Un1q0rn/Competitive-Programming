#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;cin >> s;
    cout <<  s[sz(s)-2] << s[sz(s)-1];
    return 0;
}

