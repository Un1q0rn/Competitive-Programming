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
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    string s;cin >> s;
    for(int i=0;i<sz(s)-1;i++){
        if(s[i]==s[i+1]){
            cout << "Wrong Answer";
            return 0;
        }
    }
    cout << "Accepted";
    return 0;
}
