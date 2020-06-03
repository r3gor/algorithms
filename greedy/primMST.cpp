#include<iostream>
#include<typeinfo>

using namespace std;

pair<int,int> * primMST(int** distances, int n) {
    int *near = new int[n];
    int *min_dist = new int[n];
    pair<int,int> *ans = new pair<int,int>[n-1];
    int min_node_val = 9999, min_node;

    for (int i=1; i<n; i++) {
        near[i] = 1;
        min_dist[i] = distances[i][1];
    }
    int ans_i = 0;
    while(ans_i != n-1) {
        min_node_val = 9999;
        for (int i=1; i<n; i++) {
            if (min_dist[i]>0 && min_node_val>min_dist[i]) {
                min_node_val = min_dist[i];
                min_node = i;
            }
        }
        ans[ans_i++] = make_pair(near[min_node], min_node);
        min_dist[min_node] = -1;
        for (int i=1; i<n; i++) {
            if (min_dist[i]>distances[min_node][i]) {
                near[i] = min_node;
                min_dist[i] = distances[min_node][i];
            }
        }
    }
    delete near;
    delete min_dist;
    return ans;
}

int** mat(int N, int init) {
    int **mat = new int*[N];
    for (int i=0; i<N; i++)
        mat[i] = new int[N];
    return mat;

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++) {
            mat[i][j] = init;
        }
    }
    return mat;

}


int main() {

    int **mat4 = mat(4, 9999);
    mat4[0][1] = 10;
    mat4[1][0] = 10;

    mat4[0][2] = 6;
    mat4[2][0] = 6;

    mat4[0][3] = 5;
    mat4[0][3] = 5;

    mat4[1][3] = 15;
    mat4[3][1] = 15;

    mat4[2][3] = 4;
    mat4[3][2] = 4;

    pair<int,int> *ans = primMST(mat4, 4);

    for (int i=0; i<4-1; i++) {
        cout<<"edge: ";
        cout<<ans[i].first<<" ";
        cout<<ans[i].second<<" \n";
    }


}