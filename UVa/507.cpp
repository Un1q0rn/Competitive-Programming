#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t;cin >> t;
    int test = 1;
    while(t--){
        int n;cin >> n;
        vector<int> a(n);
        for(int i=1;i<n;i++){
            cin >> a[i];
            a[i]+=a[i-1];
        }
        int mxpf = 0,mnpf = 0,p1=0,ans1=0,ans2 =0;
        for(int i=1;i<n;i++){
            if((a[i]-mnpf == mxpf && i-p1 > ans2-ans1) || (a[i]-mnpf > mxpf)){
                mxpf = a[i]-mnpf;
                ans2 = i;
                ans1 = p1;
            }
            if(a[i] < mnpf){
                mnpf = a[i];
                p1 = i;
            }
        }
        if(mxpf > 0){
            cout << "The nicest part of route " << test << " is between stops " << ans1+1 << " and " << ans2+1;
        }
        else{
            cout << "Route " << test << " has no nice parts";
        }
        cout << '\n';
        test++;
    }
    return 0;
}
