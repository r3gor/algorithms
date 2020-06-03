/**
 * Kruskal's algorithm is a minimum-spanning-tree algorithm 
 * which finds an edge of the least possible weight that 
 * connects any two trees in the forest. It is a greedy 
 * algorithm in graph theory as it finds a minimum spanning 
 * tree for a connected weighted graph adding increasing 
 * cost arcs at each step.
 * */

#include <bits\stdc++.h>
using namespace std;

/*
E: Edges
N: Nodes
*/

struct Edge {
    int a, b, cost;
    bool operator<(Edge &e) {
        return this->cost < e.cost;
    }
};

struct Graph {
    int E, N;
    Edge *edges;
};

struct SubSet { /* TODO: change 'SubSet' to '...'. InfoNode */
    int parent;
    int rank;
};

Graph* createGraph(int E, int N) {
    return new Graph{E, N, new Edge[E]};
}

int getParent(SubSet *subsets, int node) {
    if (subsets[node].parent == node)
        return node;
    int parent = getParent(subsets, subsets[node].parent); 
    subsets[node].parent = parent; // update parent
    return parent;
}

int subset_union(SubSet *subsets, int na, int nb) {
    int parent_a = getParent(subsets, na);
    int parent_b = getParent(subsets, nb);

    if (subsets[parent_a].rank > subsets[parent_b].rank) 
        subsets[parent_b].parent = subsets[parent_a].parent;
    else if (subsets[parent_a].rank < subsets[parent_b].rank)
        subsets[parent_a].parent = subsets[parent_b].parent;
    else {
        subsets[parent_b] = subsets[parent_a];
        subsets[parent_a].rank++;
    }
}

int compare(const void* a, const void* b) {
    Edge *a1 = (Edge*)a;
    Edge *b1 = (Edge*)b;
    return a1->cost > b1->cost;
}

Edge* kruscalMST (Graph *g) {
    int cost = 0;
    Edge *answer = new Edge[g->N -1];

    qsort(g->edges, g->E, sizeof(g->edges[0]), compare);
    SubSet *subsets = new SubSet[g->E];
    for (int i=0; i<g->E; i++) {
        subsets[i] = SubSet {i, 0}; 
    }
    int current_answer = 0;
    for (int i=0; i<g->E; i++) {
        Edge e = g->edges[i];
        int parent_a = getParent(subsets, e.a);
        int parent_b = getParent(subsets, e.b);
        if (parent_a == parent_b)
            continue;
        answer[current_answer++] = e;
        subset_union(subsets, parent_a, parent_b);
    }
    return answer;
}

void print_root(Edge *edges, int E) {
    int cost = 0;
    cout<<":: minimun sppaning tree ::\n";
    for (int i=0; i<E; i++) {
        cout<<"edge: ";
        cout<<edges[i].a<<" - "<<edges[i].b<<"\n";
        cost += edges[i].cost;
    }
    cout<<"minimun cost: "<<cost<<"\n";
}   

int main() {
    int N = 4;
    int E = 5;
    Graph *graph = createGraph(E, N);
    graph->edges[0] = {0,1,10};
    graph->edges[1] = {0,2,6};
    graph->edges[2] = {0,3,5};
    graph->edges[3] = {1,3,15};
    graph->edges[4] = {2,3,4};

    Edge *MST = kruscalMST(graph);
    print_root(MST, graph->N-1);
    system("pause");
    return 0; 
}