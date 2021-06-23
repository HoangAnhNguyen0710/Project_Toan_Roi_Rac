#include "library/graph_by_jrb_with_ID_total.h"


int main(){
    
    FILE* fptr = fopen("../testcaseprufer.txt","r"); if(fptr == NULL) return 0;
    int n, m;
    int id1, id2;
    double weight;
    int i;
    fscanf(fptr, "%d %d\n", &n, &m);
    double w;
    int s, t;
    Graph g = createGraph();
    int fathercode[n];
   // Graph out = createGraph();
    for(i = 0; i< m; i++){
        fscanf(fptr, "%d %d %lf\n", &id1, &id2, &weight);
        addEdge_Vertex_WD(g, id1, id2, weight);
        // addVertex(g, id1, (char*)id1);
        // addVertex(g, id2, (char*)id2);
    }
    FatherCode(g ,n ,fathercode);
    printf("The father code of the graph is :\n");
    for(int i = 0; i < n; i++){
        printf("%3d", fathercode[i]);
    }
}
