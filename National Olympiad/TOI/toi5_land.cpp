#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
int n,m,mark[5][5];
double ans = LLONG_MAX,a[5][5];
void play(int state,double price){
    if(state == n*m){
        ans = min(ans,price);
        return ;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!mark[i][j]){
                mark[i][j] = 1;
                double up = a[i][j]/10;
                price += a[i][j];
                for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++){
                    if(k == 0 && l == 0) continue;
                    if(i+k < 1 || i+k > n || j+l < 1 || j+l > m) continue;
                    a[i+k][j+l]+=up;
                }
                play(state+1,price);
                mark[i][j] = 0;
                price -= a[i][j];
                for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++){
                    if(k == 0 && l == 0) continue;
                    if(i+k < 1 || i+k > n || j+l < 1 || j+l > m) continue;
                    a[i+k][j+l]-=up;
                }
            }
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(2);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    play(0,0);
    cout << ans << '\n';
    return 0;
}
