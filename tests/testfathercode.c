#include "library/graph_by_jrb_with_ID_total.h"


int main(){
    int n = 10;
    int fathercode[n];
    Graph g = createGraph();
    // nhap edge vo huong thong thuong
    // addEdge(g, 0, 2, 1); addEdge(g, 2, 0, 1); addVertex(g, 0, "0"); addVertex(g, 1, "1"); addVertex(g, 2, "2"); 
    // addEdge(g, 6, 5, 1); addEdge(g, 5, 6, 1); addVertex(g, 9, "9"); addVertex(g, 4, "4"); addVertex(g, 5, "5");
    // addEdge(g, 0, 3, 1); addEdge(g, 3, 0, 1); addVertex(g, 3, "3");  addVertex(g, 6, "6");addVertex(g, 7, "7"); addVertex(g, 8, "8");
    // addEdge(g, 1, 6, 1); addEdge(g, 6, 1, 1);
    // addEdge(g, 2, 6, 1); addEdge(g, 6, 2, 1);
    // addEdge(g, 9, 2, 1); addEdge(g, 2, 9, 1);
    // addEdge(g, 7, 9, 1); addEdge(g, 9, 7, 1);
    // addEdge(g, 8, 9, 1); addEdge(g, 9, 8, 1);
    // addEdge(g, 4, 2, 1); addEdge(g, 2, 4, 1);
    // nhap edge vo huong dong thoi nhap dinh
    // addEdge_Vertex(g, 0, 2, 1); addEdge_Vertex(g, 2, 0, 1); 
    // addEdge_Vertex(g, 6, 5, 1); addEdge_Vertex(g, 5, 6, 1); 
    // addEdge_Vertex(g, 0, 3, 1); addEdge_Vertex(g, 3, 0, 1); 
    // addEdge_Vertex(g, 1, 6, 1); addEdge_Vertex(g, 6, 1, 1);
    // addEdge_Vertex(g, 2, 6, 1); addEdge_Vertex(g, 6, 2, 1);
    // addEdge_Vertex(g, 9, 2, 1); addEdge_Vertex(g, 2, 9, 1);
    // addEdge_Vertex(g, 7, 9, 1); addEdge_Vertex(g, 9, 7, 1);
    // addEdge_Vertex(g, 8, 9, 1); addEdge_Vertex(g, 9, 8, 1);
    // addEdge_Vertex(g, 4, 2, 1); addEdge_Vertex(g, 2, 4, 1);
    // nhap edge vo huong dong thoi nhap dinh rut gon 
    addEdge_Vertex_WD(g, 0, 2, 1); 
    addEdge_Vertex_WD(g, 6, 5, 1); 
    addEdge_Vertex_WD(g, 0, 3, 1); 
    addEdge_Vertex_WD(g, 1, 6, 1); 
    addEdge_Vertex_WD(g, 2, 6, 1);
    addEdge_Vertex_WD(g, 9, 2, 1); 
    addEdge_Vertex_WD(g, 7, 9, 1); 
    addEdge_Vertex_WD(g, 8, 9, 1); 
    addEdge_Vertex_WD(g, 4, 2, 1); 
    FatherCode(g, 10, fathercode);
    printf("The father code of the graph is :\n");
    for(int i = 1; i < n; i++){
        printf("%3d", fathercode[i]);
    }
}
