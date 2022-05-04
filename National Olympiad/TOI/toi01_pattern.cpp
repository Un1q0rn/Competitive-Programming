#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int a[50100][110];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    int mxp=INT_MIN;
    for(int i=0;i<n;i++){
        int p,q,r;cin >> p >> q >> r;
        for(int j=q;j<q+r;j++) a[p][j] = 1;
        mxp = max(p,mxp);
    }
    for(int i=1;i<=mxp;i++){
        for(int j=1;j<=70;j++){
            if(a[i][j] == 0){
                cout << 'o';
            }
            else cout << 'x';
        }
        cout << '\n';
    }
    return 0;
}
