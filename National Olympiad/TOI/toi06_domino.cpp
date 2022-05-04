#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int n;
vector<char> c;
void play(int state){
    if(state==n){
        for(auto e:c){
            cout << e;
            cout << e;
            cout << '\n';
        }
        cout << "E\n";
        return;
    }
    if(state>n) return;
    c.push_back('-');
    play(state+1);
    c.pop_back();
    c.push_back('|');
    play(state+2);
    c.pop_back();
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    play(0);
    return 0;
}
