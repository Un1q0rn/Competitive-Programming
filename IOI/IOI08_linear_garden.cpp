#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()
#define ul unsigned long long

int gcd(int a,int b) {return b == 0 ? a:gcd(b,a%b);}

const int N = 1e6 + 10;

int pw[N];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n,m;cin >> n >> m;
    string s;cin >> s;
    pw[0] = 1;
    for(int i=1;i<N;i++){
        pw[i] = pw[i - 1] * 2 % m;
    }

    int ans = 0;
    int diff = 0,mx = 0,mn = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'P'){
            int k = n - i - 1;

            int ndiff = diff + 1;
            int nmx = max(mx,ndiff);
            int nmn = min(mn,ndiff);

            ll res = 0;
            if(nmx - nmn <= 2){
                if(nmx - nmn == 2){
                    if(nmx == ndiff || nmn == ndiff){
                        res = pw[k / 2];
                    }
                    else{
                        res = pw[(k + 1) / 2];
                    }
                }
                else{
                    res = (pw[k / 2] + pw[(k + 1) / 2] - 1 + m) % m;
                }
            }

            ans = (ans + res) % m;
            
        }

        if(s[i] == 'L'){
            diff++;
        }
        else diff--;
        mn = min(mn,diff);
        mx = max(mx,diff);
    }
    
    cout << (ans + 1) % m;
    return 0;
}
