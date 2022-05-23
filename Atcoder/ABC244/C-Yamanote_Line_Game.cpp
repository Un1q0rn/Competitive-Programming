#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int n = 2e3+10;
int mark[n];
int main(void)
{
    
    int n;cin >> n;
    while(1){
        for(int i=1;i<=2*n+1;i++){
            if(!mark[i]){
                cout << i << '\n';
                mark[i] = 1;
                break;
            }
        }
        int res;
        cin >> res;
        if(res == 0) break;
        mark[res] = 1;
    }
    return 0;
}
