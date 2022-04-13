#include <bits/stdc++.h>
using namespace std;
char tid[] = {'E','S','W','N'};
int pos=0,x=0,y=0,n;
void walk(){
    if(tid[pos] == 'E') x+=n;
    else if(tid[pos] == 'W') x-=n;
    else if(tid[pos] == 'N') y+=n;
    else if(tid[pos] == 'S') y-=n;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;cin >> q;
    while(q--){
        string opr;cin >> opr;
        cin >> n;
        if(opr == "LT"){
            pos+=3;
            pos%=4;
        }
        if(opr == "RT"){
            pos+=1;
            pos%=4;
        }
        if(opr == "BW"){
            pos+=2;
            pos%=4;
        }
        walk();
        if(abs(x) >= 50000 || abs(y) >= 50000){
            cout << "DEAD";
            return 0;
        }
    }
    cout << x << " " << y << "\n" << tid[pos];
    return 0;
}
