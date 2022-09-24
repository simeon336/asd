#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph{
    int nodes;
    bool **egdes;
} graph;

void destroy(graph *g){
    if(g->egdes == NULL){
        free(g);
        return;
    }

    for(int i = 0; i < g->nodes; i++){
        if(g->egdes[i] != NULL){
            free(g->egdes[i]);
        }
    }

    free(g->egdes);
    free(g);
}

graph *create(int num){
    graph *g = (graph*)malloc(sizeof(graph));
    if(g == NULL){
        return NULL;
    }

    g->nodes = num;
    g->egdes = calloc(sizeof(bool*), g->nodes);
    if(g->egdes == NULL){
        free(g);
        return NULL;
    }

    for(int i = 0; i < num; i++){
        g->egdes[i] = calloc(sizeof(bool), g->nodes);
        if(g->egdes[i] == NULL){
            destroy(g);
            return NULL;
        }
    }

    return g;
}

void print(graph *g){
    printf("digraph{\n");

    for(int from = 0; from < g->nodes; from++){
        for(int to = 0; to < g->nodes; to++){
            if(g->egdes[from][to]){
                printf("%d -> %d; \n", from, to);
            }
            
        }
    }
    printf("}\n");
}

bool hasEdge(graph *g, unsigned int fromNode, unsigned int toNode){
    return g->egdes[fromNode][toNode];
}

bool add(graph* g, unsigned int fromNode, unsigned int toNode){
    if(hasEdge(g, fromNode, toNode)){
        return false;
    }
    g->egdes[fromNode][toNode] = true;

    return true;
}

int main(){
    graph *g1 = create(5);
    add(g1, 0, 1);
    add(g1, 2, 1);
    add(g1, 1, 0);
    add(g1, 3, 2);
    add(g1, 2, 1);
    add(g1, 0, 4);
    add(g1, 4, 1);
    print(g1);

    destroy(g1);
    return 0;
}