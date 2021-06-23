//TEST KRUSKAL
// #include "library/cgraph_datatype.h"
// #include <stdio.h>
// int main(){
//     FILE* fptr = fopen("../testcase.txt","r");
//     int n, m;
//     int id1, id2, weight;
//     fscanf(fptr, "%d %d\n", &n, &m);
//     Graph g = createGraph(n);
//     Graph out = createGraph(n);
//     for(int i = 0; i< m; i++){
//         fscanf(fptr, "%d %d %d\n", &id1, &id2, &weight);
//         addweightEdge(g, id1, id2, weight);
//     }
//     printf("Cay bao trum co trong so la : %d\n", Kruskal(g , n, out, 0));
//     fclose(fptr);
    
//     dropGraph(out);
// }
#include "library/graph_by_jrb_with_ID_total.h"


int main(){
    FILE* fptr = fopen("../testcase.txt","r");
    int n, m;
    int id1, id2, weight;
    fscanf(fptr, "%d %d\n", &n, &m);
    Graph g = createGraph();
    Graph out = createGraph();
    for(int i = 0; i< m; i++){
        fscanf(fptr, "%d %d %d\n", &id1, &id2, &weight);
        addEdge_Vertex_WD(g, id1, id2, weight);
    }
    printf("Cay bao trum co trong so la : %.0lf\n", Kruskal(g , n, out, 0));
    fclose(fptr);
    printToGraphViz(out, n, m);
    dropGraph(out);
}
