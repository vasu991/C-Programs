#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"


#include <stdbool.h>
#include "Simple Graph.c"

int main() {
    Graph* graph = createGraph();
    int choice;
    printf("A GRAPH is created..\n");

     do {
        printf("----------------ENTER----------------\n1. If you want to insert a NODE.\n");
        printf("2. If you want to create an EDGE between two NODES.\n");
        printf("3. Display GRAPH.\n");
        printf("4. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:{
                int node;
                printf("Enter the value of the NODE:\n");
                scanf("%d", &node);
                if(graph->edges[node] != NULL) {
                    printf("NODE already exits..\n");
                    break;
                }
                insertNode(graph, node);
                break;
            }
            case 2: {
                int source;
                int destination;
                printf("Enter the SOURCE of the EDGE:\n");
                scanf("%d", &source);
                if(graph->edges[source] == NULL) {
                    printf("SOURCE NODE does not exist.\nFirst create SOURCE NODE.\n");
                    break;
                }
                printf("Enter the DESTINATION of the EDGE:\n");
                scanf("%d", &destination);
                if(graph->edges[destination] == NULL) {
                    printf("DESTINATION NODE does not exist.\nFirst create DESTINATION NODE.\n");
                    break;
                }
                if(source == destination) {
                    printf("NODE already reaches itself..\n");
                    break;
                }
                Edge* temp = graph->edges[source];
                bool check = true;
                while(temp->next != NULL) {
                    if(temp->destination == destination) {
                        printf("EDGE already exits..\n");
                        check = false;
                    }
                    temp = temp->next;
                }
                if(check) {
                    insertEdge(graph, source, destination);
                }
                break;
            }
            case 3:{
                displayGraph(graph);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Wrong input!!\n");
                break;
            }
        }
    } while(choice != 4);

    return 0;
}
#pragma clang diagnostic pop