#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
int x,y,pos;
char tid[4] = {'E','S','W','N'};
char ntid = 'E';
void rot(){
    pos++;
    pos %= 4;
    ntid = tid[pos];
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    for(int i=0;i<n;i++){
        char c;cin >> c;
        if(c == 'R'){
            rot();
        }
        if(c == 'S'){
            if(ntid == 'E'){
                x++;
            }
            else if(ntid == 'S'){
                y--;
            }
            else if(ntid == 'W'){
                x--;
            }
            else if(ntid == 'N'){
                y++;
            }
        }
    }
    cout << x << ' ' << y;
    return 0;
}
