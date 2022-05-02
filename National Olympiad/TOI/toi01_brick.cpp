#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    string s[n];
    int a[m];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s[j][i] == 'O'){
                for(int k=1;k<=a[i];k++){
                    if(j-k < 0) break;
                    s[j-k][i] = '#';
                }
                break;
            }
            else if(j == n-1){
                for(int k=0;k<a[i];k++){
                    if(j-k < 0) break;
                    s[j-k][i] = '#';
                }

            }
        }
    }
    for(int i=0;i<n;i++){
        cout << s[i] << "\n";
    }
    return 0;
}

