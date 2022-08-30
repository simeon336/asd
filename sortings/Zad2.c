#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 36

typedef struct student{
    int grade;
    char *name;
    struct student *next;
} student;

typedef struct list{
    struct student *head;
} list;

list *init(){
    list *List = (list*)malloc(sizeof(list));
    List->head = NULL;
    return List;
}

void add(list *List, int grade, char* name){
    if(List->head == NULL){
        student *nov = (student*)malloc(sizeof(student));
        nov->grade = grade;
        nov->name = (char*)malloc(sizeof(char)*MAX_LINE);
        strcpy(nov->name, name);
        nov->next = NULL;
        List->head = nov;
        return;
    } 

    student *temp = List->head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    student *nov = (student*)malloc(sizeof(student));
    nov->grade = grade;
    nov->name = (char*)malloc(sizeof(char)*MAX_LINE);
    strcpy(nov->name, name);
    nov->next = NULL;
    temp->next = nov;
}

student* addArray(student *head, int grade, char* name){
    if(head == NULL){
        student *nov = (student*)malloc(sizeof(student));
        nov->grade = grade;
        nov->name = (char*)malloc(sizeof(char)*MAX_LINE);
        strcpy(nov->name, name);
        nov->next = NULL;
        head = nov;
        return head;
    } 

    student *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    student *nov = (student*)malloc(sizeof(student));
    nov->grade = grade;
    nov->name = (char*)malloc(sizeof(char)*MAX_LINE);
    strcpy(nov->name, name);
    nov->next = NULL;
    temp->next = nov;

    return head;
}

void print(list *List){
    student *temp = List->head;
    while(temp != NULL){
        printf("%s %d->", temp->name, temp->grade);
        temp = temp->next;
    }
    printf("\n");

}

void prints(student *head){
    student *temp = head;
    while(temp != NULL){
        printf("%s %d->", temp->name, temp->grade);
        temp = temp->next;
    }
    printf("\n");
}

void swap(student* first, student* second){
    student* temp = first;
    first = second;
    second = temp;
}

student* bubbleSort(student *start)
{
    int swapped, i;
    student *ptr1; 
    student *lptr = NULL; 
  
    if (start == NULL) 
        return start; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->name[0] > ptr1->next->name[0]) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 

    return start;
} 

list *Bucket(list* List){
    student **students = (student**)calloc(12, sizeof(student*));
        student *temp = List->head;
        while(temp != NULL){
           
            students[temp->grade-1] = addArray(students[temp->grade-1], temp->grade, temp->name);
            
            temp = temp->next;
        }

    for(int i = 0; i < 12; i++){
        prints(students[i]);
        students[i] = bubbleSort(students[i]);
    }
    list *newList = init();


    for(int i = 11; i >= 0; i--){
        student *temp = students[i];
        while(temp != NULL){
            add(newList, temp->grade, temp->name);
            temp = temp->next;
        }
    }
    return newList;
}

int main(){
    list *List = init();
    add(List, 3, "Ivanka");
    add(List, 8, "Ivanka");
    add(List, 4, "Avankaa");
    add(List, 5, "Bvanaa");
    add(List, 5, "Avanaa");
    add(List, 6, "Zvanaaka");
    add(List, 6, "Asvanaaka");
    print(List);

    List = Bucket(List);
    print(List);

    
    return 0;
}