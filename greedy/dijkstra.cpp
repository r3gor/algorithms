#include <iostream> 
#include <algorithm>
using namespace std;

int* dijkstra_cost (int** distances, int n){
    /**
     * returns a matrix represent minimun cost in path
     * to the node 0 to the node i, when i represents the
     * index of this matrix.
    */
    int *ans = new int[n-1];
    for (int i=1; i<n; i++) {
        ans [i-1] = distances[0][i];
    }
    bool *s = new bool [n-1];
    for (int i=0; i<n-1; i++) {s[i] = true;}
    for (int k=1; k<n; k++) {
        int cost_min= 9999, node_min = -1;
        for (int i=0; i<n-1; i++) {
            if (cost_min > ans[i] && s[i]) {
                cost_min = ans[i];
                node_min = i+1;
            }
        }

        s[node_min-1] = false;
        for (int i=1; i<n; i++) {
            ans[i-1] = min(ans[i-1], ans[node_min-1]+distances[node_min][i]);
        }
    }
    return ans;
}

int** mat(int N, int init) {
    int **mat = new int*[N];
    for (int i=0; i<N; i++)
        mat[i] = new int[N];

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++) {
            mat[i][j] = init;
        }
    }
    return mat;

}

int main() {

    int **mat5 = mat(5, 9999);
    mat5[0][4] = 10;
    mat5[0][3] = 100;
    mat5[0][2] = 30;
    mat5[0][1] = 50;
    mat5[2][1] = 5;
    mat5[3][2] = 50;
    mat5[3][1] = 20;
    mat5[4][3] = 10;

    int *d = dijkstra_cost(mat5, 5); 
    for (int i=0; i<5-1; i++) {
        cout<<"distancia minima de nodo 0 a nodo "<<i+1<<": "<< d[i]<<endl;
    }

}