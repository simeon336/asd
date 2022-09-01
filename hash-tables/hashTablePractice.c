#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
    int number;
    char* name;
    struct node *next;
} node;


typedef struct table{
    int capacity;
    struct node **buffer;
} table;

int hash(char *key, int capacity){
    unsigned long long int sum = 3;
    int len = strlen(key);

    for(int i = 0; i < len; i++)
        sum += (key[i] *3);
    
    return sum % capacity;
}

table *init(int capacity){
    table *Table = (table*)malloc(sizeof(table));
    Table->capacity = capacity;
    Table->buffer = calloc(capacity, sizeof(node*));

    for(int i = 0; i < capacity; i++){
        Table->buffer[i] = NULL;
    }
    return Table;
}

bool contains(table *Table, char *key){
    int index = hash(key, Table->capacity);
    node *temp = Table->buffer[index];
    while(temp != NULL){
        if(!strcmp(temp->name, key)){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

table *push(table *Table, char* name, int number){
    int index = hash(name, Table->capacity);

    // Update if it exists
    
    if(contains(Table, name)){
        node *temp = Table->buffer[index];
        while(strcmp(temp->name, name)){
            temp = temp->next;
        }
        temp->number = number;
        return Table;
    }
    
    // Create new person
    
    node *person = (node*)malloc(sizeof(node));
    person->number = number;
    person->name = malloc((strlen(name)) * sizeof(char));
    strcpy(person->name, name);
    person->next = NULL;
    
    // If list empty
    
    if(Table->buffer[index] == NULL){
        Table->buffer[index] = person;
        return Table;
    }
    
    // If not
    
    node *temp = Table->buffer[index];
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = person;
    
    return Table;
}

void printHashTable(table *Table){
    for(int i = 0; i < Table->capacity; i++){
        node *temp = Table->buffer[i];
        while(temp != NULL){
            printf("%s: %d ", temp->name, temp->number);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){

    table *Table = init(4);
    char name[] = "penka";
    Table = push(Table, name, 921212);
    Table = push(Table, "gosho", 123123);
    Table = push(Table, "ggigo", 123123);
    Table = push(Table, "kasdi", 123123);

    printHashTable(Table);
    return 0;
}