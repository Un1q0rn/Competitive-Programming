#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ui unsigned int 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()
const int N = 5e5+10;
int a[N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int now = 0,d = 1;
    while(m--){
        char opr;cin >> opr;
        int x,y;
        if(opr == 'a'){
            cin >> x >> y;
            x--;y--;
            swap(a[(now+x*d+n)%n],a[(now+y*d+n)%n]);
        }
        else if(opr == 'b'){
            cin >> x >> y;
            x--;
            a[(now+x*d+n)%n] = y;
        }
        else if(opr == 'c'){
            cin >> x;
            x--;
            now = (now+x*d+n)%n;
            d*=-1;
        }
        else {
            cin >> x;
            x--;
            cout << a[(now+x*d+n)%n] << '\n';
        }
    }
    return 0;
}
