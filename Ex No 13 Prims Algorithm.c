#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
intminKey(int key[],intmstSet[],int vertices){
    int min = INT_MAX,minIndex;

    for(int v =0; v < vertices; v++){
        if(!mstSet[v]&& key[v]< min){
            min = key[v];
            minIndex= v;
        }
    }

    returnminIndex;
}

voidprintMST(int parent[],int graph[MAX_VERTICES][MAX_VERTICES],int vertices){
    printf("Edge \tWeight\n");
    for(inti=1;i< vertices;i++){
        printf("%d - %d \t%d\n", parent[i],i, graph[i][parent[i]]);
    }
}

voidprimMST(int graph[MAX_VERTICES][MAX_VERTICES],int vertices){
    intparent[MAX_VERTICES];
    intkey[MAX_VERTICES];    
    intmstSet[MAX_VERTICES];

    for(inti=0;i< vertices;i++){
        key[i]= INT_MAX;
        mstSet[i]=0;
    }

    
    key[0]=0;
    parent[0]=-1;

    for(int count =0; count < vertices -1; count++){
        
        int u =minKey(key,mstSet, vertices);

        mstSet[u]=1;

        
        for(int v =0; v < vertices; v++){
            
            if(graph[u][v]&&!mstSet[v]&& graph[u][v]< key[v]){
                parent[v]= u;
                key[v]= graph[u][v];
            }
        }
    }

    
    printMST(parent, graph, vertices);
}

intmain(){
    int vertices;

    
    printf("Input the number of vertices: ");
    scanf("%d",&vertices);

    if(vertices <=0|| vertices > MAX_VERTICES){
        printf("Invalid number of vertices. Exiting...\n");
        return1;
    }

    intgraph[MAX_VERTICES][MAX_VERTICES];

    printf("Input the adjacency matrix for the graph:\n");
    for(inti=0;i< vertices;i++){
        for(int j =0; j < vertices;j++){
            scanf("%d",&graph[i][j]);
        }
    }

   
    primMST(graph, vertices);

    return0;
}
