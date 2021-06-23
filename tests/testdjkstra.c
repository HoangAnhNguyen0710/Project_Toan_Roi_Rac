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
        addEdgeNew(g, id1, id2, weight, 1);
        addVertex(g, id1, (char*)id1);
        addVertex(g, id2, (char*)id2);
    }
   
    //printf("Cay bao trum co trong so la : %.0lf\n", Kruskal(g , n, out, 0));
    
    printf("Nhap diem dau va diem cuoi :\n"); scanf("%d %d", &s, &t);
    // scanf("%d ", &s);
    // scanf("%d ", &t);
    printf("Dijkstra :\n");
    w = shortestPath_s_To_t(g, s, t, previous);
    if(w == INFINITIVE_VALUE) printf("Khong ton tai duong di tu %d den %d\n", s, t);
    else {
        printf("Duong di ngan nhat tu %d den %d la \n", s, t);
        printf("Do dai = %.0lf \n", w);
        printf("Duong di :\n"); i = t;
        do{
           printf("%d <== ", i);    //v3 
            i = previous[i];                       
        }
        while(i != s);
        printf("%d", s);
        // for(int i = 20; i >= 0; i --){
        //     printf("%s --", getVertex(g, previous[i]));
        // }
    }
    printf("\n");
    printf("BFS_Shortest :\n");
    BFS_Shortest_Path(g, s, t, previous);
    i = t;
    do{
           printf("%d <== ", i);    //v3 
            i = previous[i];                       
        }
        while(i != s);
        printf("%d", s);
    printf("\n");
    //getComponents(g, n);
    // }
    fclose(fptr);
    //dropGraph(g);

    
}