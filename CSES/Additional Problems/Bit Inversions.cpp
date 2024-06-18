#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first

const int N = 2e5+10;
string s;
int m,cnt[N];
set<int> dif;
priority_queue<int> pq;
void modify(int x){
    if(x == 0 || x == sz(s)) return ;
    auto it = dif.find(x);
    if(it == dif.end()){
        dif.insert(x);
        it = dif.find(x);
        auto a = *prev(it),b = *next(it);
        pq.push(x-a);pq.push(b-x);
        cnt[x-a]++;cnt[b-x]++;cnt[b-a]--;
    }
    else{
        auto a = *prev(it),b = *next(it);
        dif.erase(it);
        pq.push(b-a);
        cnt[x-a]--;cnt[b-x]--;cnt[b-a]++;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> m;
    dif.insert(0);
    dif.insert(sz(s));
    for(int i=0;i<sz(s)-1;i++){
        if(s[i] == s[i+1]) continue;
        dif.insert(i+1);
    }
    for(auto it = dif.begin();next(it) != dif.end();it++){
        pq.push(*next(it)-*it);
        cnt[*next(it)-*it]++;
    }
    while(m--){
        int x;cin >> x;
        modify(x-1);
        modify(x);
        while(!cnt[pq.top()]) pq.pop();
        cout << pq.top() << ' ';
    }
    return 0;
}
