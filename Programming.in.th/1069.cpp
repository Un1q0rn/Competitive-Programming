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
stack<char> st;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    for(int i=0;i<n;i++){
        char c;cin >> c;
        if(st.empty()) st.push(c);
        else if(c == st.top()){
            st.pop();
        }
        else st.push(c);
    }
    if(st.empty()) cout << 0 << '\n' << "empty";
    else{
        cout << sz(st) << '\n';
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
    }
    return 0;
}

