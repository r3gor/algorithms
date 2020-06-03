#include<bits/stdc++.h>
using namespace std;


template<typename T>
vector<T> insertion_sort(vector<T> &v) {
    for (int i=1; i<v.size(); i++) {
        int k = v[i];
        int j = i-1;
        while(j+1 && v[j]>k) {
            v[j+1] = v[j];
            j--; 
        }
        v[j+1] = k;
    }
}

int main() { /* TEST */
    vector<int> v {4,3,5,7,1,0};
    insertion_sort(v);
    cout<<"sort v: ";
    for (int i: v) { cout<<i<<" ";}
}