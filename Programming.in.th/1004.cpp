#include<bits/stdc++.h>
using namespace std;


int a[10100],q[1010],fr,en;
char opr;
int main(){
    int n,m,c,s,i,k;
    cin >> n >> m;
    while(m--){
        cin >> c >> s;
        a[s] = c;
    }
    while(1){
        cin >> opr;
        if(opr == 'X'){
            cout << 0 << "\n";
            return 0;
        }
        if(opr == 'E'){
            cin >> n;
            k = en;
            for(i=en-1;i>=fr;i--){
                if(a[n] == a[q[i]]) {
                    k = i+1;
                    break;
                }
            }
            for(i=en-1;i>=k;i--){
                q[i+1] = q[i];
            }
            q[k] = n;
            en++;
        }
        if(opr == 'D'){
            if(fr == en){
                cout << "empty\n";
            }
            else cout << q[fr++] << "\n";
        }
    }
    return 0;
}
