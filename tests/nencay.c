#include "libfdr/cgraph_datatype.h"
#include <stdio.h>
// 2 ham duoc dua vao thu vien tren de tien su dung
// Graph UpdateGraph(Graph g, int min){
//     int output[100];
//     getAdjacentVertices(g,min, output);
//     g.matrix[min* g.n + output[0]] =  0;
//     g.matrix[min* g.n + output[0]] = 0;
//     printf("%4d",output[0]);
//     return g;
// }
// void PruferCode(Graph graph, int root, int verte_num, int ver_num){
// int a[100];
// int visited[1000] = {};
// int n, output[100], i, u, v;
// Dllist node, queue;
// int min = ver_num;
// queue = new_dllist();
// dll_append(queue, new_jval_i(root)); //thêm phần tử start vào queue
// while ( !dll_empty(queue) )
// {
// node = dll_first(queue);
// u = jval_i(node->val);
// dll_delete_node(node);
// if (!visited[u]) //nếu u chưa được thăm
// {
// if(getAdjacentVertices(graph, u, a) == 1){
//     if(u < min && u!= root) min = u; // gan min = dinh be nhat va co bac = 1 va khac root dc chon
// }
// visited[u] = 1;
// n = getAdjacentVertices(graph, u, output);
// for (i=0; i<n; i++) //xét lần lượt các đỉnh kề với đỉnh u
// {
// v = output[i];
// if (!visited[v]) //thêm v vào queue nếu v chưa được thăm
// dll_append(queue, new_jval_i(v));
// }
// }
// }
// if(verte_num == 2 ) return;  // nếu số đỉnh còn lại trong graph chỉ còn 2 thì stop, prufer code đến đây thôi
// else {
// graph = UpdateGraph(graph, min);
// verte_num--;
// PruferCode(graph, root, verte_num, ver_num);
// }
// } 
int main(){
    int n = 9; // so dinh 
    int output[10];
    Graph g = createGraph(n+1);
    addEdge(g, 0, 2); addEdge(g, 0, 3);
    addEdge(g, 2, 4); addEdge(g, 2, 6);
    addEdge(g, 2, 9); addEdge(g, 6, 1);
    addEdge(g, 6, 5); addEdge(g, 9, 7);   
    addEdge(g, 9, 8);
    PruferCode(g, 0, n, n); // chon min la đỉnh số lớn nhất
    printf("\n");
    //BFS(g, 0, -1,PrintVertex);
    dropGraph(g);
}