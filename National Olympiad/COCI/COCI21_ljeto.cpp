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
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> mem(9);
    int score1 = 0,score2 = 0;
    while(n--){
        int t,a,b;cin >> t >> a >> b;
        int add = 100;
        if(mem[a] != 0 && t-mem[a] <= 10){
            add+=50;
        }
        mem[a] = t;
        score1+=add*(a < 5);
        score2+=add*(a > 4);
    }
    cout << score1 << ' ' << score2;
    return 0;
}
