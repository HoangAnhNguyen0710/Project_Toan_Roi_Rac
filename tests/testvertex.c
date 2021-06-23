#include "library/cgraph_datatype.h"
#include <stdio.h>
int main(){
    FILE* fptr = fopen("../testcase2.txt","r");
    int n;
    int id1, id2, weight;
    fscanf(fptr, "%d %d\n", &n);
    Graph g = createGraph(n);
    Graph out = createGraph(n);
    for(int i = 0; i< n; i++){
        fscanf(fptr, "%d %d %d\n", &id1, &id2, &weight);
        addweightEdge(g, id1, id2, weight);
    }
    //printf("Cay bao trum co trong so la : %d\n", Kruskal(g , n, out, 0));
    fclose(fptr);
    dropGraph(out);
}