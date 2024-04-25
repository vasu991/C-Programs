#include<stdlib.h>
#include<stdio.h>
#define MAX 10

typedef struct Edge {
    int destination;
    struct Edge* next;
} Edge;

typedef struct Graph {
    Edge* edges[MAX];
} Graph;



Edge* createEdge(int destination) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->destination = destination;
    edge->next = NULL;
    return edge;
}

Graph* createGraph() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    for(int i = 0; i < MAX; i++) {
        graph->edges[i] = NULL;
    }
    return graph;
}

void insertNode(Graph* graph, int node) {
    Edge* edge = createEdge(node);
    graph->edges[node] = edge;
}

void insertEdge(Graph* graph, int source, int destination) {
    Edge* first = graph->edges[source];
    Edge* edge = createEdge(destination);
    edge->next = first;
    graph->edges[source] = edge;

}

void displayEdges(Edge* start, int node) {
    Edge* temp = start;
    printf("EDGES: ");
    if(temp->destination == node) {
        printf("SELF\n");
        return;
    }
    while(temp->next != NULL) {
        if(temp->next->destination == node) {
            printf("%d", temp->destination);
        }
        else {
            printf("%d , ", temp->destination);
        }
        temp = temp->next;
    }
    printf("\n");
}

void displayGraph(Graph* graph) {
    for(int i  = 0; i < MAX; i++) {
        printf("NODE: %d ", i);
        if(graph->edges[i] != NULL) {
            displayEdges(graph->edges[i], i);
        }
        else {
            printf("NULL\n");
        }

    }
}

