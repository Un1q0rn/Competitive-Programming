#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define sz(x) (int)x.size()
 
bitset<26> ch;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        string s;
        int edge = 0,ver = 0,acorn = 0;
        while(cin >> s){
            if(s[0] == '*') break;
            ch[s[1]-'A'] = 1;
            ch[s[3]-'A'] = 1;
            edge++;
        }
        cin >> s;
        for(int i=0;i<sz(s);i++){
            if(s[i] == ',') continue;
            acorn += !(ch[s[i]-'A']);
            ver++;
        }
        cout << "There are " << (ver-acorn)-edge << " tree(s) and " << acorn << " acorn(s).\n";
        ch.reset();
    }
    return 0;
}
