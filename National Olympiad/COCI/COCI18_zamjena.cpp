#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


map<string,string> pa;
string root(string s){
    return pa[s] == s ? s : pa[s] = root(pa[s]);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<string> a(n),b(n);
    for(auto &e:a){
        cin >> e;
        pa[e] = e;
    }
    for(auto &e:b){
        cin >> e;
        pa[e] = e;
    }
    for(int i=0;i<n;i++){
        string u = root(a[i]),v = root(b[i]);
        if(!isdigit(pa[u][0]) && !isdigit(pa[v][0])){
            pa[u] = v;
        }
        else if(!isdigit(pa[u][0])){
            pa[u] = v;
        }
        else if(!isdigit(pa[v][0])){
            pa[v] = u;
        }
        else if(pa[u] == pa[v]){
            pa[u] = v;
        }
        else{
            cout << "NE";
            return 0;
        }
    }
    cout << "DA";
    return 0;
}
