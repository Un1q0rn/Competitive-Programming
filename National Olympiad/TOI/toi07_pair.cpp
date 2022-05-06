#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

const int N = 1e5+100;
int a[N],tmp[N];
double ans,dp[N];
void mergesort(int l,int r){
    if(l==r) return ;
    int mid = (l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    for(int i=l;i<=r;i++){
        dp[i] = dp[i-1] + a[i];
    }
    int i=l,j=mid+1,k=l;
    while (i<=mid&&j<=r)
    {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            ans += a[j] * (mid-i+1) + dp[mid] - dp[i-1];
            tmp[k++] = a[j++];
        }
    }
    while (i<=mid) tmp[k++]=a[i++];
    while (j<=r) tmp[k++]=a[j++];
    for(i=l;i<=r;i++) a[i]=tmp[i];
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(0);
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        int x,y;cin >> x >> y;
        a[y] = x;
    }
    mergesort(1,n);
    cout << ans ;
    return 0;
}
