#include <bits/stdc++.h>
using namespace std;
int button(int p,int k){
    if(p == 2){
        char b[3] = {'A','B','C'};
        k = (k-1)%3;
        return b[k];
    }
    else if(p == 3){
        char b[3] = {'D','E','F'};
        k = (k-1)%3;
        return b[k];
    }
    else if(p == 4){
        char b[3] = {'G','H','I'};
        k = (k-1)%3;
        return b[k];
    }
    else if(p == 5){
        char b[3] = {'J','K','L'};
        k = (k-1)%3;
        return b[k];
    }
    else if(p == 6){
        char b[3] = {'M','N','O'};
        k = (k-1)%3;
        return b[k];
    }
    else if(p == 7){
        char b[4] = {'P','Q','R','S'};
        k = (k-1)%4;
        return b[k];
    }
    else if(p == 8){
        char b[3] = {'T','U','V'};
        k = (k-1)%3;
        return b[k];
    }
    else if(p == 9){
        char b[4] = {'W','X','Y','Z'};
        k = (k-1)%4;
        return b[k];
    }
}

int main()
{
    int n;cin >> n;
    int p,k,s=1;cin >> p >> k;
    int a[3][3];
    int ip,jp;
    char ans[100];
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) {
        a[i][j] = s;
        s++;
        if(a[i][j] == p){
            ip=i;
            jp=j;
        }
    }
    int ansp=0;
    if(a[ip][jp] != 1){
        ans[0] = button(a[ip][jp],k);
        ansp++;
    } 
    for(int i=0;i<n-1;i++){
        int cj,ci,t;cin >> cj >> ci >> t;
        ip += ci;
        jp += cj;
        if(a[ip][jp] != 1){
            ans[ansp] = button(a[ip][jp],t);
            ansp++;
        }
        else if(a[ip][jp] == 1) ansp=max(0,ansp-t);
    }
    if(ansp > 0)for(int i=0;i<ansp;i++) cout << ans[i];
    else cout << "null";
    return 0;
}

