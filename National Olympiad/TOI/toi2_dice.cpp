#include <bits/stdc++.h>
using namespace std;

struct dice{
    int U=1,F=2,L=3,B=5,R=4,D=6;
};

int main()
{
    int n;cin >> n;
    dice a[n];
    for(int i=0;i<n;i++){
        string s;cin >> s;
        for(int j=0;j<s.length();j++){
            if(s[j] == 'F'){
                swap(a[i].F,a[i].D);
                swap(a[i].F,a[i].B);
                swap(a[i].F,a[i].U);
            }
            if(s[j] == 'B'){
                swap(a[i].F,a[i].U);
                swap(a[i].F,a[i].B);
                swap(a[i].F,a[i].D);
            }
            if(s[j] == 'L'){
                swap(a[i].U,a[i].L);
                swap(a[i].U,a[i].D);
                swap(a[i].U,a[i].R);
            }
            if(s[j] == 'R'){
                swap(a[i].U,a[i].R);
                swap(a[i].U,a[i].D);
                swap(a[i].U,a[i].L);
            }
            if(s[j] == 'C'){
                swap(a[i].F,a[i].L);
                swap(a[i].F,a[i].B);
                swap(a[i].F,a[i].R);
            }
            if(s[j] == 'D'){
                swap(a[i].F,a[i].R);
                swap(a[i].F,a[i].B);
                swap(a[i].F,a[i].L);
            }
        }
        cout << a[i].F << " ";
    }
	return 0;
}
