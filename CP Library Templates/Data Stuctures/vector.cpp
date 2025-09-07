#include <iostream>

using namespace std;

template <typename T>
struct myVec{
private :
    T* a;
    size_t sz;
    size_t cap;

    void resize(size_t ncap){
        T* b = new T[ncap];
        for(size_t i=0;i<sz;i++){
            b[i] = a[i];
        }

        delete[] a;
        a = b;
        cap = ncap;
    }

public :
    myVec() : a(nullptr) , sz(0), cap(0){}

    ~myVec(){
        delete[] a;
    }

    void push_back(const T& v){
        if(sz == cap){
            size_t ncap = (cap == 0) ? 1 : cap * 2;
            resize(ncap);
        }
        a[sz++] = v;
    }

    void pop_back(){
        if(sz){
            sz--;
        }
    }

    size_t size() {return sz;}

    T& operator[](size_t i) const{
        if(i >= sz){
            throw out_of_range("Index out of range");
        }
        return a[i];
    }
};

void solve() {
    myVec<int> a;

    for(int i=0;i<5;i++){
        a.push_back(i);
    }

    for(int i=0;i<(int)a.size();i++){
        cout << a[i] << ' ';
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
