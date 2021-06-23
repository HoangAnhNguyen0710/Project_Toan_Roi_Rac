#include "library/graph_by_jrb_with_ID_total.h"

//TEST PRIM
int main(){
    // int so_mau; int mau[100];
    FILE* fptr = fopen("../testcase.txt","r");
    int n, m;
    int id1, id2; 
    double weight;
    fscanf(fptr, "%d %d\n", &n, &m);
    Graph g = createGraph();
    Graph out = createGraph();
    for(int i = 0; i< m; i++){
        fscanf(fptr, "%d %d %lf\n", &id1, &id2, &weight);
        addEdge_Vertex_WD(g, id1, id2, weight);
    }
    printf("Cay bao trum co trong so la : %.0lf\n", Prim_Algorithm(g, 0, n, out));
    fclose(fptr);
   

}