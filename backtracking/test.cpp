#include <bits/stdc++.h>
using namespace std;

void f(array<int, 2> &arr){
    arr[0] = 100;
}

int main(){
    array<int, 2> arr {1,2};
    f(arr);
    cout<<arr[0];
}