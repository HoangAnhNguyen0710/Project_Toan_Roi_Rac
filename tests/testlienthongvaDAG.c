#include "library/graph_by_jrb_with_ID_total.h"


int main(){
    FILE* fptr = fopen("../testcase3.txt","r"); if(fptr == NULL) return 0;
    int n, m;
    int id1, id2;
    double weight;
    int i;
    fscanf(fptr, "%d %d\n", &n, &m);
    int previous[1000];
    double w;
    int s, t;
    Graph g = createGraph();
   // Graph out = createGraph();
    for(i = 0; i< m; i++){
        fscanf(fptr, "%d %d %lf\n", &id1, &id2, &weight);
        addEdgeNew(g, id1, id2, weight, 0);
        addVertex(g, id1, (char*)id1);
        addVertex(g, id2, (char*)id2);
    }
    int x = DAG(g);
    if(x == 0)printf("Do thi testcase3 ko phai la DAG\n");
    else printf("\nDo thi testcase3 la DAG");

    int bool = check_lienthongmach(g);

    if (bool == true)
    {
      printf("\nThành phần liên thông mạch!!\n");
    } else printf("\nThành phần không liên thông mạch!!\n");
    //printf("Cay bao trum co trong so la : %.0lf\n", Kruskal(g , n, out, 0));
    
    fclose(fptr);

    
}