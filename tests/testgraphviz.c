#include <stdio.h>
#include <time.h>
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
int main(){
    FILE* fptr = fopen("testcase3.txt","r");
    FILE* output = fopen("output.dot", "w+");
    //FILE* fptr1 = fopen("testcase3.txt","w+");
    int n, m;
    int ran[1000][1000];
    int id1, id2, weight;
    fscanf(fptr, "%d \n", &n );
    fprintf(output, "graph dothi\n {");
    for(int i = 0; i< n; i++){
        fscanf(fptr, "%d %d %d\n", &id1, &id2, &weight);
        printf("%d %d\n", id1, id2);
        fprintf(output, "%d -- %d;\n", id1, id2);
    }
    fprintf(output, "}");
//     srand(time(NULL));
//     int r;
//     for(int i = 0; i < 1000; i++){
//         for(int j = 0; j < 1000; j++){
//             ran[i][j] = 0;
//         }  
//     } 
//     fprintf(fptr1,"%d \n", 1000 );
//     for(int i = 0; i < 1000; i++){
//         int id2 = random(0, 999);
//         while(ran[i][id2] != 0 && i == id2){
//             id2 = random(0, 999);
//         }
//         ran[i][id2] = 1;
//         ran[id2][i] = 1;
//         int weight = random(1, 30);
//         fprintf(fptr1, "%d %d %d\n", i, id2, weight);
//     }   
//    fclose(fptr1);
    fclose(fptr);
    fclose(output);
}