#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

map<int,int> m;
queue<int> q[11],r;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int c,s;cin >> c >> s;
    for(int i=0;i<s;i++){
        int a,b;cin >> a >> b;
        m[b] = a;
    }
    while(1){
        char opr;cin >> opr;
        if(opr == 'X'){
            cout << 0 << '\n';
            break;
        }
        if(opr == 'E'){
            int n;cin >> n;
            r.push(m[n]);
            q[m[n]].push(n);
        }
        if(opr == 'D'){
            if(r.empty()){
                cout << "empty\n";
                continue;
            }
            int now = r.front();
            while(q[now].empty() && !r.empty()){
                r.pop();
                now = r.front();
            }
            cout << q[now].front() << '\n';
            q[now].pop();
            if(q[now].empty()) r.pop();
        }
    }
    return 0;
}
