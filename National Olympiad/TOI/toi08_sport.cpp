#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int n,w,l;
vector<char> ans;
void play(int w,int l){
    if(w == n || l == n){
        for(auto x:ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    ans.pb('W');
    play(w+1,l);
    ans.pop_back();
    ans.pb('L');
    play(w,l+1);
    ans.pop_back();
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> w >> l;
    play(w,l);
    return 0;
}
