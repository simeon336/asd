#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LINE 256

typedef struct node{
    char* name;
    float* grades;
    int numGrades;
    struct node *next;
} node;

typedef struct linkedList{
    struct node *head;
    struct node *tail;
} list;

typedef struct table{
    int capacity;
    struct linkedList **buffer;
} table;

int hash(char *name, int n){
    int sum = 3;
    int len = strlen(name);
    for(int i = 0; i < len; i++){
        sum = (sum + name[i])*3;
    }

    return sum % n;
}

bool contains(table *Table, char *key){
    int index = hash(key, Table->capacity);
    node *temp = Table->buffer[index]->head;
    
    while(temp != Table->buffer[index]->tail){
        if(strcmp(temp->name, key) == 0){
            return true;
        }
        temp = temp->next;
    }

    return false;
}

float* returnGrades(table *Table, char *key){
    int index = hash(key, Table->capacity);
    node *temp = Table->buffer[index]->head;
    
    while(temp != Table->buffer[index]->tail){
        if(strcmp(temp->name, key) == 0){
            return temp->grades;
        }
        temp = temp->next;
    }

    return NULL;
}

int numGrades(table *Table, char *key){
    int index = hash(key, Table->capacity);
    node *temp = Table->buffer[index]->head;
    
    while(temp != Table->buffer[index]->tail){
        if(strcmp(temp->name, key) == 0){
            return temp->numGrades;
        }
        temp = temp->next;
    }

    return 0;
}


table *init(int capacity){
    table *newTable = (table*)malloc(sizeof(table));
    newTable->capacity = capacity;
    newTable->buffer = calloc(sizeof(list*), capacity);
    
    for(int i = 0; i < capacity; i++){
        newTable->buffer[i] = malloc(sizeof(list));
        newTable->buffer[i]->tail = NULL;
        newTable->buffer[i]->head = NULL;   
    }

    return newTable;
}



table *push(table *Table, char *name, float *grades, int numGrades){
    int index = hash(name, Table->capacity);
    
    // NEW NODE

    node *student = malloc(sizeof(node));

    student->name = malloc(sizeof(char) * (strlen(name)+1));
    strcpy(student->name, name);

    student->grades = malloc(sizeof(float) * numGrades);
    student->numGrades = numGrades;
    for(int i = 0; i < numGrades; i++)
        student->grades[i] = grades[i];

    student->next = NULL;

    // PUT IN TABLE
    
    if (Table->buffer[index]->head == Table->buffer[index]->tail) {
        Table->buffer[index]->head = student;
        student->next = Table->buffer[index]->tail;
    } else {
        // CHECKS FOR THE SAME KEY (STUDENT)
        node *temp = Table->buffer[index]->head;
        while(temp != Table->buffer[index]->tail){
            if(strcmp(temp->name, name) == 0){
                for(int i = 0; i < numGrades; i++){
                    temp->grades[i] = grades[i];
                }
                return Table;
            }

            temp = temp->next;
        } 
        
        student->next = Table->buffer[index]->head;
        Table->buffer[index]->head = student;
    }
    return Table;
}

void printTable(table *Table){
    for(int i = 0; i < Table->capacity; i++){
        printf("[%d]->", i);
        node *temp = Table->buffer[i]->head;
        
        while (temp != NULL){
            printf("%s ", temp->name);
            printf("[ ");
            for(int j = 0; j < temp->numGrades; j++){
                printf("%.2f ", temp->grades[j]);
            }
            printf("], ");
            temp = temp->next;
        }
        printf("\n");
    }
}

float sredno(table *Table, char *key){
    float *grades = returnGrades(Table, key);
    int count = 0;
    float sum = 0;

    for(int i = 0; i < numGrades(Table, key); i++){
        sum += grades[i];
        count++;
    }

    return sum / count;
}

// void enterData(table *Table){
//     size_t size = MAX_LINE;
//     char *info = malloc(sizeof(char)* size);
//     getline(&info, &size, stdin);
    

// }

int main(){
    table *Table = init(10);
    
    float ocenki1[] = {3.544, 5.544, 6.544};
    Table = push(Table, "Gosho", ocenki1, 3);
    Table = push(Table, "Myth", ocenki1, 3);
    Table = push(Table, "Morgana", ocenki1, 3);
    Table = push(Table, "Honeydust", ocenki1, 3);
    Table = push(Table, "Oaksprig", ocenki1, 3);
    Table = push(Table, "Elizabeth", ocenki1, 3);
    Table = push(Table, "Mary", ocenki1, 3);
    Table = push(Table, "Rose", ocenki1, 3);
    Table = push(Table, "Pearl", ocenki1, 3);
    Table = push(Table, "Helgarson", ocenki1, 3);
    Table = push(Table, "Desperado", ocenki1, 3);
    Table = push(Table, "Stella", ocenki1, 3);
    Table = push(Table, "Katherine", ocenki1, 3);
    Table = push(Table, "Nettie", ocenki1, 3);
    Table = push(Table, "Ichijou", ocenki1, 3);
    printTable(Table);
    char test[] = "Nettie";
    if(contains(Table, test) == true){
        printf("\nYes\n");
    } else{
        printf("\nNo\n");
    }
    printf("Sredno: %f", sredno(Table, "Pearl"));
   
    return 0;
}
