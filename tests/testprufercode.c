#include "library/cgraph_datatype.h"
//#include "libfdr/graph_by_jrb.h"
//#include "libfdr/jrb.h"
//#include "library/graph_by_jrb_with_ID_total.h"
int main(){
    FILE* fptr = fopen("../testcaseprufer.txt","r");
    int n, m;
    int id1, id2, weight;
    fscanf(fptr, "%d %d\n", &n, &m);
    Graph g = createGraph(n);
    Graph out = createGraph(n);
    for(int i = 0; i< m; i++){
        fscanf(fptr, "%d %d %d\n", &id1, &id2, &weight);
        addweightEdge(g, id1, id2, weight);
    }
    //printf("Cay bao trum co trong so la : %d\n", Kruskal(g , n, out, 0));
    fclose(fptr);
    out = g;
    newPruferCode(out, 0, n, n);
    // dropGraph(g);
    // dropGraph(out);
    // 
    // printf("%4d", DFS_DAG())
}