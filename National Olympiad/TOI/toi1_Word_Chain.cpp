#include<bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,n,cnt;cin >> a >> n;
    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++){
        cnt = 0;
        for(int j=0;j<a;j++){
            if(s[i][j] != s[i+1][j]) cnt++;
            if(cnt > 2){
                cout << s[i];
                return 0;
            }
        }
    }
    return 0;
}
