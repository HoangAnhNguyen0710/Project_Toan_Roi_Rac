#include <stdio.h>
#include <stdlib.h>
#include "libfdr/dllist.h"
typedef struct{
    int *matrix;
    int n;
}Graph;
// đồ thị trong thư viện này là đo thi ko có hướng
Graph createGraph(int n); // ham tao do thi
void addEdge(Graph graph, int v1, int v2); // ham them canh vao do thi
int adjacent(Graph graph, int v1, int v2); //ham kiem tra xem do thi co canh(v1,v2) hay ko
int getAdjacentVertices(Graph graph, int v, int *output);// Trả về số lượng các đỉnh kề với đỉnh v trên đồ thị; đồng thời mảng output sẽ chứa danh sách các đỉnh kề với đỉnh v
void dropGraph(Graph graph);

Graph createGraph(int n){
    Graph g;
    g.n = n;
    g.matrix =  (int*)malloc(n*n*sizeof(int));
    return g;
}

void addEdge(Graph graph, int v1, int v2){
    graph.matrix[v1* graph.n + v2] =  1;
    graph.matrix[v2* graph.n + v1] = 1;
}
void addweightEdge(Graph graph, int v1, int v2, int weight){
    graph.matrix[v1* graph.n + v2] =  weight;
    graph.matrix[v2* graph.n + v1] = weight;
}

int getEdgeValue(Graph g, int v1, int v2){
    return g.matrix[v2* g.n + v1];

}
void addDirectedEdge(Graph g, int v1, int v2){
    g.matrix[v1* g.n + v2] =  1;
}
int adjacent(Graph graph, int v1, int v2){
    return graph.matrix[v1 *graph.n +v2];
}
int getAdjacentVertices(Graph graph, int v, int *output){
    int total = 0, i;
    for(i = 0; i <graph.n ; i++){
        if(adjacent(graph, v, i)){
        output[total++] = i;
        }
    }
    return total;
}

int outdeg(Graph graph, int v, int *output){
    int total = 0, i;
    for(i = 0; i <graph.n ; i++){
        if(adjacent(graph, v, i)){
        output[total++] = i;
        }
    }
    return total;
}
int indeg(Graph graph, int v, int *output){
    int total = 0, i;
    for(i = 0; i <graph.n ; i++){
        if(adjacent(graph, i, v)){
        output[total++] = i;
        }
    }
    return total;
}
void dropGraph(Graph graph){
   // free(graph.matrix);
    graph.matrix = NULL;
    graph.n = 0;
}
void PrintVertex(int v){
    printf("%4d", v);
}

void BFS(Graph graph, int start, int stop, void (*func)(int)){
    
int visited[1000] = {};
int n, output[100], i, u, v;
Dllist node, queue;
queue = new_dllist();
dll_append(queue, new_jval_i(start)); //thêm phần tử start vào queue
while ( !dll_empty(queue) )
{
node = dll_first(queue);
u = jval_i(node->val);
dll_delete_node(node);
if (!visited[u]) //nếu u chưa được thăm
{
func(u);
visited[u] = 1;
if ( u == stop ) return; //đỉnh u = stop  kết thúc BFS
n = getAdjacentVertices(graph, u, output);
for (i=0; i<n; i++) //xét lần lượt các đỉnh kề với đỉnh u
{
v = output[i];
if (!visited[v]) //thêm v vào queue nếu v chưa được thăm
dll_append(queue, new_jval_i(v));
}
}
}
}
//#endif //IQ_H_

void BFS_Shortest_Path(Graph graph,int start, int stop, int*truoc){
    int visited[1000] = {};
int n, output[100], i, u, v;
Dllist node, queue;
queue = new_dllist();
dll_append(queue, new_jval_i(start)); //thêm phần tử start vào queue
while ( !dll_empty(queue) )
{
node = dll_first(queue);
u = jval_i(node->val);
dll_delete_node(node);
if (!visited[u]) //nếu u chưa được thăm
{
visited[u] = 1;
if ( u == stop ) return; //đỉnh u = stop  kết thúc BFS
n = getAdjacentVertices(graph, u, output);
for (i=0; i<n; i++) //xét lần lượt các đỉnh kề với đỉnh u
{
v = output[i];
if (!visited[v]){
    truoc[v] = u; 
dll_append(queue, new_jval_i(v)); //thêm v vào queue nếu v chưa được thăm
}
}
}
}
}



int count_Connected_Component(Graph g, int ver_num) {
    int mark[ver_num + 1];

    int succes;
    int count = 0, i,j, Connected_Comp_Num = 0;
    for( i = 0; i< ver_num; i++) //khoi tao cac dinh chua danh dau
        mark[i] = 0;
        do {
           j = 0;
           while(mark[j]==1) //tim 1 dinh chua duoc danh dau
           j++;
           mark[j] = 1; //danh dau dinh tim duoc
           count++; //tang so dinh danh dau len 1
           Connected_Comp_Num ++; //tang so thanh phan lien thong len 1
          do {
              succes = 0;
              for(i = 0; i < ver_num; i++)
                 if(mark[i]==1)
                    for(j = 0; j < ver_num; j++)
                          if (mark[j] == 0 && g.matrix[i * g.n + j] == 1) {
                               mark[j] = 1;
                               succes =1;
                               count ++;
                               if(count == ver_num) return Connected_Comp_Num;
                           }
             }while (succes == 1);
         } while(count < ver_num); //lap lai khi con dinh chua duoc danh dau
    return Connected_Comp_Num;
}



Graph UpdateGraph(Graph g, int min){
    int output[100];
    getAdjacentVertices(g,min, output);
    g.matrix[min* g.n + output[0]] =  0;
    g.matrix[output[0]* g.n + min] = 0;
    
    printf("%4d",output[0]);
    
    return g;
}

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
//PRUFER CODE 
void newPruferCode(Graph g, int root, int verte_num, int ver_num){
int a[100];
int visited[1000] = {};
int n, output[100];
int min = verte_num;
for(int i = 0; i<= verte_num; i++){
    for(int j = 0; j<= verte_num; j++){
        if(g.matrix[i* g.n + j] > 0 && i< min && getAdjacentVertices(g, i ,output) == 1 && i!= root)
        min = i;
    }
}
g = UpdateGraph(g, min);
ver_num --; 
if(ver_num == 2) return;
else 
newPruferCode(g, root, verte_num, ver_num);
}

// int ton_tai(Graph g, int v, int ver_num){
//     for( int i = 0; i <= ver_num; i++)
//     {
//         if(g.matrix[v * g.n + i] == 1 || g.matrix[i* g.n + v] == 1) return 1;
//     }
//     return 0;
// }
// void Topo_Sort(Graph g, int start, int *list, int ver_num){
//     Graph tmp = g; int count = 0; int i;
//     int traverse[ver_num];
//     int *S = (int*)calloc(ver_num, sizeof(int)); int sumS = 0;
//     int output[ver_num], op[ver_num];
//     for(int i = 0; i <= ver_num; i++){
//         traverse[i] = 0;
//         if(indeg(g, i, output) == 0 && ton_tai(g, i, ver_num) == 1){
//             S[i] = i;
//             sumS += i;
//         }
//     }
//     while(sumS != 0){
//         for(i = 0; i<= ver_num; i++){
//             if(S[i]!= 0 || S[i] == 0 || i == 0 && ton_tai(g, 0, ver_num) && traverse[0] == 0){
//                 S[i] = 0; sumS -= i; 
//                 list[count] = i; count++; 
//                 traverse[i] = 1;
//                 int n = outdeg(g, i, output);
//                 for(int j =0; j< n; j++){
//                     g.matrix[i* g.n + output[j]] = 0;
//                     printf("in %d - %d\n", indeg(g, output[j],op), output[j]);
//                     if(indeg(g, output[j], op) == 0  && traverse[output[j]] == 0){
//                     S[output[j]] = output[j];
//                     sumS += output[j];
//                     printf("them %d vao S[%d]\n", output[j], output[j]);
//                     }
//                     }
                    
//                 }
//             }
            
//         }
//     }

void DFS(Graph graph, int start, int stop, void (*func)(int)){

int visited[1000] = {};
    int n, output[100],op[100],op2[100], i, u , v;
    Dllist node, stack;
    stack = new_dllist();
    dll_append(stack, new_jval_i(start));
    while(! dll_empty(stack)){
        node = dll_last(stack);
        u = jval_i(node->val);
        dll_delete_node(node);
        if(!visited[u]){
            func(u);
            visited[u] =  1;
            if ( u == stop ) return; 
            //printf("%4d", u);
            n = getAdjacentVertices(graph, u, output);
            for(i =0; i < n ; i++){
                v = output[i];
                if(v == start) printf("cycle\n"); //cycle detected
                if(!visited[v]) dll_append(stack, new_jval_i(v));
            }
            printf("\n");
        }
    }
    return ;
}


int DFS_Cycle(Graph graph, int start){
    int visited[1000] = {};
    int n, output[100], i, u , v;
    int color[1000] = {0}; //khởi tạo tất cả đỉnh là màu trắng _ tức là ch dc thăm
    Dllist node, stack;
    stack = new_dllist();
    dll_append(stack, new_jval_i(start));
    color[start] = 1; // dinh dc dua vao stack thi co màu xám
    while(! dll_empty(stack)){
        node = dll_last(stack);
        u = jval_i(node->val);
        dll_delete_node(node);
        if(color[u] == 1 || color[u] == 2){
            //PrintVertex(u);
           // visited[u] =  1;
            color[u]++; // ghé thăm và đã ra khỏi stack r thì ++ màu
            n = outdeg(graph, u, output);
            for(i =0; i < n ; i++){
                v = output[i];
                // if(v == start) return 0; //cycle deleted
                if(color[v] == 0|| color[v] == 1) {
                    dll_append(stack, new_jval_i(v));
                    color[v] ++; // đưa vào stack sẽ ++ màu
                }
            }
        }
    }
    for(int i = 0 ; i< 10; i++){
      //  printf("%d\n", color[i]);
       if(color[i] == color[start] + 1 && color[i]!= start) return 1; // tồn tại cycle
    }
    return 0; // ko tồn tại cycle
}
int Algorithm_for_Kruskal(Graph g, int verte_num, int min,  Graph out, int out_ed_num, int start){
   // test = createGraph();
   
  
    //printf("%d\n",DFS_Cycle(out, start));
    for(int i = 0; i <= verte_num; i++){
        
        for(int j = i+1 ; j <= verte_num; j++){
           if(getEdgeValue(g, i, j) == min ){
               addweightEdge(out, i, j, min);
               if(DFS_Cycle(out , start) != 0){
               out.matrix[i* out.n + j] = 0;
               out.matrix[j* out.n + i] = 0;
               }
               else {
                   if(getEdgeValue(out, i, j) != 0){
                   printf("Them thanh cong canh %d %d trong so %d vao cay bao trum \n", i, j, min);
                   out_ed_num ++;
                   }
               }
           }
        }
    }  
     
    
   // dropGraph(test);
   // dropGraph(test);
    return out_ed_num;
}
int Kruskal(Graph g, int verte_num, Graph out, int start){

    int min = 0;
    int out_ed_num = 0;
    int distance = 0;
    while(out_ed_num != (verte_num - 1)  ){
        out_ed_num = Algorithm_for_Kruskal(g, verte_num, min,  out, out_ed_num, start);
        //printf("%4d", out_ed_num);
        min ++;
        
    }
    for( int i = 0; i <= verte_num; i++){
        for(int j = i; j<= verte_num; j++){
            if(out.matrix[i* out.n + j]> 0) distance += out.matrix[i* out.n + j];
        }
    }
    return distance;
}
int TO_Mau(Graph g, int n, int *m, int start){ //Xu ly de cho ra ket qua vao mang m[]
    int kt;
    int so_mau = 0;
    for(int i = start;i <n ;i++)
        if(!m[i]) {
            so_mau++; //Dem so mau
            m[i] =so_mau;
            for(int j = i+1; j<n ; j++) //Kiem tra xem nhung dinh nao co the gan bang mau sm nua khong
                if((g.matrix[i* g.n + j] == 0)&&(m[j] == 0)){
                    kt=1;
                    for(int k = i+1; k < j; k++)
                        if((g.matrix[k* g.n + j] == 1)&&(m[i]==m[k])){
                            kt=0;
                            break;
                        }
                    if(kt==1) m[j] = so_mau;
                }                   
        }
    return so_mau;
}