#include<bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> selection_sort(vector<T> &v) {
    for (int i=0; i<v.size(); i++) {
        int ix = i;
        T val = v[i];
        for (int j=i+1; j<v.size(); j++) {
            if (v[j]<val) {
                ix = j;
                val = v[j];
            }
        }
        v[ix] = v[i];
        v[i] = val;
    }
}

int main() { /* TEST */
    vector<int> v {4,3,5,7,1,0};
    selection_sort(v);
    cout<<"sort v: ";
    for (int i: v) { cout<<i<<" ";}
}