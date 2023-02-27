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

vector<pair<int,int>> a;
int n,m,d;
bool check(int k){
    int day = a[0].f,cnt = 0;
    for(int i=0;i<m;i++){
        if(day-a[i].f> d){
            return false;
        }
        cnt++;
        if(cnt > k){
            cnt = 1;
            if(a[i].f > day) day = a[i].f;
            else day++;
        }
    }
    return day <= n;
}
void print(int k){
    int day = a[0].f,cnt = 0,now = 1;
    cout << k << '\n';
    for(int i=0;i<m;i++){
        while(now < day){
            cout << 0 << '\n';
            now++;
        }
        cnt++;
        if(cnt > k){
            cout << 0 << '\n';
            cnt = 1;
            now++;
            if(a[i].f > day) day = a[i].f;
            else day++;
        }
        cout << a[i].s << ' ';
    }
    while(now <= n){
        cout << 0 << '\n';
        now++;
    }
}
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> n >> d >> m;
    a.resize(m);
    for(int i=0;i<m;i++){
        cin >> a[i].f;
        a[i].s = i+1;
    }
    sort(all(a));
    int l = 1,r = m;
    while(l < r){
        int mid = (l+r)>>1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    print(r);
    return 0;
}
