#include <stdio.h>
#include "library/graph_by_jrb_with_ID_total.h"


int main(){
    int i, previous[100], s,t ;
    double w;
    
    
    FILE* fptr = fopen("../testcase.txt","r");
    int n, m;
    int id1, id2; 
    double weight;
    fscanf(fptr, "%d %d\n", &n, &m);
    Graph g = createGraph();
    Graph out = createGraph();
    for(i = 0; i< m; i++){
        fscanf(fptr, "%d %d %lf\n", &id1, &id2, &weight);
        addEdge(g, id1, id2, weight); addEdge(g, id2, id1, weight);
        addVertex_without_name(g, id1); addVertex_without_name(g, id2);
    }
    
    printf("Nhap id dinh bat dau va dinh ket thuc ( nam trong khoang 0 den 4) :\n");
    scanf("%d %d",&s ,&t);
    w = shortestPath_s_To_t(g, s, t, previous);
    if(w == INFINITIVE_VALUE) printf("Khong ton tai duong di tu %s den %s\n", getVertex(g, s), getVertex(g,t));
    else {
        printf("Duong di ngan nhat tu %s den %s la \n", getVertex(g, s), getVertex(g,t));
        printf("Do dai = %f \n", w);
        printf("Duong di :\n"); i = t;
        do{
            printf("%s <== ", getVertex(g,i));    //v3 
            i = previous[i];                       
        }
        while(i != s);
        printf("%s", getVertex(g, s));
        // for(int i = 20; i >= 0; i --){
        //     printf("%s --", getVertex(g, previous[i]));
        // }

    }
    fclose(fptr);
    dropGraph(g);

}