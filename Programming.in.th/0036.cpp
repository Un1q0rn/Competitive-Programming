#include<bits/stdc++.h>
using namespace std;

int pas[26][100];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    pas[0][0] = pas[1][0] = pas[1][1] = 1;
    n += (n%2==0)?0:1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j == 0 || j == i){
                pas[i][j] = 1;
                continue;
            }
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
        }
    }
    cout << pas[n][n/2];
    return 0;
}

