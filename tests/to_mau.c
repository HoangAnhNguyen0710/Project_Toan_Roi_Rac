//#include "libfdr/cgraph_datatype.h"

#include "graph_by_jrb_with_ID_total.h"
// int BFS_count_deg(Graph graph, int start, int stop,  vertex *list){
// int max = 0;   
// int visited[1000] = {};
// int n, output[100], i, u, v;
// int out[100];
// int count = 0;
// Dllist node, queue;
// queue = new_dllist();
// dll_append(queue, new_jval_i(start)); //thêm phần tử start vào queue
// while ( !dll_empty(queue) )
// {
// node = dll_first(queue);
// u = jval_i(node->val);
// dll_delete_node(node);
// if (!visited[u]) //nếu u chưa được thăm
// {
// list[count].dinh = u;
// list[count].deg = getAdjacentVertices(graph, u, out);
// list[count].mau = 0;
// if(list[count].deg > max) max = list[count].deg;
// count ++;
// visited[u] = 1;
// if ( u == stop ) return max; //đỉnh u = stop  kết thúc BFS
// n = getAdjacentVertices(graph, u, output);
// for (i=0; i<n; i++) //xét lần lượt các đỉnh kề với đỉnh u
// {
// v = output[i];
// if (!visited[v]) //thêm v vào queue nếu v chưa được thăm
// dll_append(queue, new_jval_i(v));
// }
// }
// }
// return max;
// }

void import_edges(Graph g, int ed_num, FILE* fptr){
    int v1, v2;
    for(int i = 0; i < ed_num; i++){
        fscanf(fptr,"%d %d\n", &v1, &v2);
        addEdge(g, v1, v2, 1);
        addEdge(g, v2, v1, 1);
    }
}


// int  so_mau = 0;
// int m[100];

// void TO_Mau(Graph g, int n){ //Xu ly de cho ra ket qua vao mang m[]
//     int kt;
//     for(int i =1;i <=n ;i++)
//         if(!m[i]) {
//             so_mau++; //Dem so mau
//             m[i] =so_mau;
//             for(int j = i+1; j<=n ; j++) //Kiem tra xem nhung dinh nao co the gan bang mau sm nua khong
//                 if((g.matrix[i* g.n + j] == 0)&&(m[j] == 0)){
//                     kt=1;
//                     for(int k = i+1; k < j; k++)
//                         if((g.matrix[k* g.n + j] == 1)&&(m[i]==m[k])){
//                             kt=0;
//                             break;
//                         }
//                     if(kt==1) m[j] = so_mau;
//                 }                   
//         }
// }
void In_ra_man_hinh(int n, int so_mau, int *m){ //In ket qua ra man hinh
    for(int i = 1;i <= so_mau; i++){
        printf("\nMau %d : ___", i );
        for(int j=1;j<=n;j++) if(m[j]==i) printf("%d\t",j);
       
    }
    
}
int main(){
    int ver_num, ed_num;
    int max_deg;
    int i; int so_mau;
    FILE *fptr = fopen("../tomau.txt", "r"); 
    fscanf(fptr,"%d %d\n", &ver_num, &ed_num);
    int m[100];
    Graph g = createGraph(ver_num+1);
    import_edges(g, ed_num, fptr);
    //max_deg = BFS_count_deg(g, 1, -1, list);
    //printf("%d\n", max_deg);
    // for(i = 0; i< ver_num; i++){
    //     if(list[i].deg == max_deg - 1) break;
        
    // }
    // BFS_count_deg(g, list[i].dinh, -1, list);
    so_mau = TO_Mau(g, ver_num, m, 1);
    In_ra_man_hinh(ver_num, so_mau, m);
    DAG(g);


}