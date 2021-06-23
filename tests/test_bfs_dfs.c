#include "library/graph_by_jrb_with_ID_total.h"
#include <stdio.h>


int main(){
    FILE* fptr = fopen("../testcase2.txt","r");
    int n, m;
    int id1, id2; 
    double weight;
    fscanf(fptr, "%d %d\n", &n, &m);
    Graph g = createGraph();
    //Graph out = createGraph();
    for(int i = 0; i< m; i++){
        fscanf(fptr, "%d %d %lf\n", &id1, &id2, &weight);
        addEdgeNew(g, id1, id2, weight, 1);
    }
    fclose(fptr);
    int output[n];
    printf("DFS :\n");
    DFS(g, 1, -1, PrintVertex);
    printf("\nBFS :\n");
    BFS(g, 1, -1, PrintVertex);
    // printf("%d", getNumOfV(a));
    // getComponents(a, 7);
    // dropGraph(a);
}
