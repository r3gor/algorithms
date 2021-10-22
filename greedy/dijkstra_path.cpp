#include <vector>
#include <iostream>

#define INF 9999

int min_cost(std::vector<unsigned int> cost, std::vector<bool> marked){
    int min = INF;
    int i_min = -1;
    for (unsigned int i=0; i<cost.size(); i++){
        if (!marked[i] && cost[i]<min){
            min = cost[i];
            i_min = i;
        }
    }
    return i_min;
}

std::vector<unsigned int> dijkstra_path(std::vector<std::vector<unsigned int>> adjmat, int i, int d){
    std::vector<bool> marked(adjmat.size(), 0);
    std::vector<unsigned int> cost(adjmat.size(), INF);
    std::vector<unsigned int> parent(adjmat.size(), -1);

    parent[i] = -1;
    cost[i] = 0;

    for (unsigned int i=0; i<adjmat.size(); i++){
        int i_node = min_cost(cost, marked);

        if (i_node == -1) // all is marked
            break;
        // else
        marked[i_node] = true;

        for (unsigned int j=0; j<adjmat.size(); j++){
            if (marked[j] || !adjmat[i_node][j]) continue;
            if (cost[i_node] + adjmat[i_node][j] < cost[j]){
                cost[j] =  cost[i_node] + adjmat[i_node][j];
                parent[j] = i_node;
            }
        }
    }
    return parent;
}



int main(){
    
    int i = 0;
    int d = 3;

    std::vector<std::vector<unsigned int>> adjmat = {
                        { 0, 1, INF, INF, 10 }, 
						{ 1, 0, 4, INF, INF }, 
						{ INF, 4, 0, 7, INF }, 
						{ INF, INF, 7, 0, 2 }, 
						{ 10, INF, INF, 2, 0 } 
    };
    
    std::vector<unsigned int> parent = dijkstra_path(adjmat, i, d);

    std::cout<<"Camino: "<<std::endl;
    int r = parent[d];
    std::cout<<d<<" <- ";
    while(r > 0){
        std::cout<<r<<" <- ";
        r = parent[r];
    }
    std::cout<<r<<std::endl;
}