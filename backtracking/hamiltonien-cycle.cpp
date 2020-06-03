#include <bits/stdc++.h>

#define AA(N) array<array<bool, N>, N>
#define A(N) array<int, N>
#define ui unsigned int

using namespace std;

template<ui N>
bool valid(AA(N) a_matrix, A(N+1) path, int pos, int node) {
    if (!a_matrix[path[pos-1]][node]) return false;
    for (int i=0; i<pos; i++) 
        if (path[i]==node) return false;
    return true;
}

template<ui N>
bool make_path(AA(N) a_matrix, A(N+1) &path, int pos) {
    if (pos == N) {
        if (a_matrix[path[pos-1]][path[0]]){
            path[pos] = path[0];
            return true;
        }
        return false;
    }

    for (ui i=1; i<N; i++) {
        if (valid<N>(a_matrix, path, pos, i)) {
            path[pos] = i;
            if (make_path<N>(a_matrix, path, pos+1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

template<ui N>
A(N+1) get_hamiltonien_cycle(AA(N) a_matrix) {
    A(N+1) path {0,-1,-1,-1,-1,-1};
    if (!make_path<N>(a_matrix, path, 1)){
        cout<<"ciclo no existe!"<<endl;
    }
    for (int i : path){
        cout<<i<<" ";
    }
    return path;
}   

int main() {
    // const int N = 2;
    AA(5) sma {{
        {0, 1, 0, 1, 0},  
        {1, 0, 1, 1, 1},  
        {0, 1, 0, 0, 1},  
        {1, 1, 0, 0, 1},  
        {0, 1, 1, 1, 0}
        }};

    get_hamiltonien_cycle<5>(sma);
    return 0;
}