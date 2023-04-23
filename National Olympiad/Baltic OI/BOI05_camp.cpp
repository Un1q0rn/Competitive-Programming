#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
struct A{
    int ic,jc,rc,cc,arrang,alti;
};
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int r,c;cin >> r >> c;
    vector<vector<int>> a(r+2,vector<int>(c+2));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
            a[i][j]+=a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    int l,w;cin >> l >> w;
    int h;cin >> h;
    vector<A> chars(h);
    for(int i=0;i<h;i++){
        int ic,jc,rc,cc,arrang,alti;
        cin >> ic >> jc >> rc >> cc >> arrang >> alti;
        chars[i] = {ic,jc,rc,cc,arrang,alti};
    }
    int ansi=-1,ansj=-1,now=0;
    for(int i=1;i<=r-l+1;i++){
        for(int j=1;j<=c-w+1;j++){
            int cnt = 0;
            for(int k=0;k<h;k++){
                int i1 = i+chars[k].ic-1,j1 = j+chars[k].jc-1;
                int rc = chars[k].rc,cc = chars[k].cc;
                int i2,j2,i3,j3;
                if(chars[k].arrang){
                    i2 = i1+rc,j2 = j1;
                    i3 = i2+rc-1,j3 = j2+cc-1;
                }
                else{
                    i2 = i1,j2 = j1+cc;
                    i3 = i2+rc-1,j3 = j2+cc-1;
                }
                int sum2 = a[i3][j3]-a[i2-1][j3]-a[i3][j2-1]+a[i2-1][j2-1];
                int sum1 = a[i3][j3]-a[i1-1][j3]-a[i3][j1-1]+a[i1-1][j1-1]-sum2;
                if(chars[k].alti){
                    cnt+=(sum1>=sum2);
                }
                else cnt+=(sum1<sum2);
                if(cnt+(h-k-1) <= now){
                    break;
                }
            }
            if(cnt > now){
                ansi = i;
                ansj = j;
                now = cnt;
            }
        }
    }
    cout << ansi << ' ' << ansj;
    return 0;
}
