#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
 
const int N = 3e5+100;
string s1,s2;
int n,q;
ll fw[N],ptr[N],sum;
vector<ll> word[301];
void update(int idx,int num){
    while(idx<=s1.length()){
        fw[idx] += num;
        idx+=(idx&-idx);
    }
    return;
}

int read(int idx){
    int sum = 0;
    while(idx>0){
        sum+=fw[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s1 >> s2;
    for(int i=0;i<s1.length();i++){
        word[s1[i]].pb(i+1);
    }
    for(int i=0;i<s2.length();i++){
        if(ptr[s2[i]] >= word[s2[i]].size()){
            cout << -1;
            return 0;
        }
        sum += word[s2[i]][ptr[s2[i]]] + read(word[s2[i]][ptr[s2[i]]]);
        update(word[s2[i]][ptr[s2[i]]++], -n);
    }
    cout << sum;
    return 0;
}
