#include <bits/stdc++.h>
using namespace std;

#define N 4

bool is_valid(array<int, N> pos_sol, int k) {
    for (int i =0; i<N; i++ ){
        if (pos_sol[i] == k) return false;
    }
    return true;
}

void mk_min(int &min,array<int, N> &sol, array<array<int, N>, N> arr, int i, array<int, N> pos_sol) {
    if (i == N){
        int s = 0;
        for (int k=0; k<N; k++){ 
            s += arr[k][pos_sol[k]];
        }
        if (s<min) {
            min = s;
            sol = pos_sol; 
        }
    }

    else {
        for (int k=0; k<N; k++) {
            if (is_valid(pos_sol, k)) {
                pos_sol[i] = k;
                mk_min(min, sol, arr, i+1, pos_sol);
                pos_sol[i] = -1;
            }
        }
    }
}

void print_sol(array<array<int, N>, N> arr) {
    array<int, N> sol;
    int min;
    array<int, N> p_sol;
    mk_min(min,sol , arr, 0, p_sol);

    for (int i=0; i<N; i++){ 
        cout<<sol[i]<<" ";
    }
}

int main() {
    array<array<int, N> , N> arr {{
        {1,2,8,30},
        {4,5,3,12},
        {1,7,9,13},
        {7,4,10,18}
    }};
    print_sol(arr);
}