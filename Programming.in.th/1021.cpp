#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;cin >> q;
    priority_queue<int> p;
    while(q--){
        char opr;cin >> opr;
        if(opr == 'P'){
            int n;cin >> n;
            p.push(n);
        }
        if(opr == 'Q'){
            if(!p.empty()){
                cout << p.top() << '\n';
                p.pop();
            }
            else cout << -1 << '\n';
        }
    }
    return 0;
}
