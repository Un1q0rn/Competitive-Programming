#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define pf push_front
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
void divide(const string&s,string&s1,string&s2){
    int n = sz(s);
    int bracket = 0;
    for(int i=1;;i++){
        if(s[i] == '('){
            bracket++;
        }
        else if(s[i] == ')'){
            bracket--;
        }
        else if(bracket == 0){
            s1 = s.substr(1,i-1);
            s2 = s.substr(i+1,n-i-2);
            return ;
        }
    }
}
string solves(const string&opr,const string&s,const string&t){
    if(s == "" || t == ""){
        if(opr == "i"){
            return "";
        }
        else return max(s,t);
    }
    string s1,s2,t1,t2;
    divide(s,s1,s2);
    divide(t,t1,t2);
    return '('+solves(opr,s1,t1)+','+solves(opr,s2,t2)+')';
}
void solve(){
    string opr,s,t;
    while(cin >> opr >> s >> t){
        cout << solves(opr,s,t) << '\n';
    }
}


bool multi = false;

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
