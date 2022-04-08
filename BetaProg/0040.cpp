#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q;cin >> q;
    while(q--){
        string s;cin >> s;
        int len = s.length();
        if((s[len-1]-'0')%2==1 || s == "2") cout << "T\n";
        else cout << "F\n";
    }
    return 0;
}
