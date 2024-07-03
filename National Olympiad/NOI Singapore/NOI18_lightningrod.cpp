#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;
        while(sz(st) && st.top().first >= a-b && st.top().second <= a+b){
            st.pop();
        }
        if(!sz(st) || a-b < st.top().first || a+b > st.top().second){
            st.push({a-b,a+b});
        }
    }
    cout << sz(st);
    return 0;
}
