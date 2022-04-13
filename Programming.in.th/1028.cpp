#include <bits/stdc++.h>
using namespace std;

map<char,int> m;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        char opr,c,c1,c2;cin >> opr;
        if(opr == '!'){
            cout << '!';
            break;
        }
        else if(opr == '#'){
            cin >> c;
            cout << m[c] << '\n';
        }
        else if(opr == '='){
            cin >> c;
            int n;cin >> n;
            m[c] = n;
        }
        else if(opr == '+'){
            cin >> c1 >> c2;
            m[c1] += m[c2];
        }
        else if(opr == '-'){
            cin >> c1 >> c2;
            m[c1] -= m[c2];
        }
        else if(opr == '*'){
            cin >> c1 >> c2;
            m[c1] *= m[c2];
        }
        else if(opr == '/'){
            cin >> c1 >> c2;
            m[c1] /= m[c2];
        }
    }
    return 0;
}
