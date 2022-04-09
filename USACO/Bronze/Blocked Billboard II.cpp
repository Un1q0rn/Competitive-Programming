#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct Rect {
	int x1, y1, x2, y2;
	int area() {
		return (y2 - y1) * (x2 - x1); 
	}
};

int intersect(Rect p, Rect q) {
	int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

int main() {
    setIO("billboard");
    cin.tie(0)->sync_with_stdio(0);
    Rect A,B;
    cin >> A.x1 >> A.y1 >> A.x2 >> A.y2;
    cin >> B.x1 >> B.y1 >> B.x2 >> B.y2;
    int lower_left = 0,upper_right = 0,upper_left = 0,lower_right = 0;
    if(A.x1 <= B.x2 && A.x1 >= B.x1 && A.y1 <= B.y2 && A.y1 >= B.y1) lower_left = 1;
    if(A.x2 <= B.x2 && A.x2 >= B.x1 && A.y2 <= B.y2 && A.y2 >= B.y1) upper_right = 1;
    if(A.x1 <= B.x2 && A.x1 >= B.x1 && A.y2 <= B.y2 && A.y2 >= B.y1) upper_left = 1;
    if(A.x2 <= B.x2 && A.x2 >= B.x1 && A.y1 <= B.y2 && A.y1 >= B.y1) lower_right = 1;
    if(lower_left==1 && upper_right==1 && upper_left==1 && lower_right==1){
        cout << 0;
    }
    else if((upper_left==1 && upper_right==1) || (upper_left==1&&lower_left==1) || (lower_left==1&&lower_right==1) || (upper_right==1&&lower_right==1)){
        cout << A.area()-intersect(A,B);
    }
    else cout << A.area();
    return 0;
}
