#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    char line[300];
    struct node *next;
}node;

node *readFromFile(FILE *fp);
void printData(node *head);
void writeToFile(char *filename, node *head);
void freeList(node *head);

int main(){
    char file[]="text.txt";
    char file2[]="text2.txt";
    FILE *fp=fopen(file, "r");
    if(fp==NULL){
        return 1;
    }
    
    node *head = readFromFile(fp);
    fclose(fp);

    printData(head);
    
    writeToFile(file2, head);
    
    freeList(head);

    return 0;
}

node *readFromFile(FILE *fp)
{
    node *n = malloc(sizeof(node));
    if(n==NULL){
        return NULL;
    }

    if (fgets(n->line, sizeof(n->line), fp) == NULL)
    {
        free(n);
        return NULL;
    }

    n->next = readFromFile(fp);

    return n;
}

void printData(node *head){
    node *temp = head;

    while(temp != NULL)
    {
        printf("%s", temp->line);
        temp = temp->next;
    }
}

void writeToFile(char *filename, node *head){
    FILE *fp=fopen(filename, "w");
     if(fp==NULL){
        return;
    }

    node *temp = head;

    while(temp != NULL)
    {
        fprintf(fp, "%s", temp->line);
        temp = temp->next;
    }

    fclose(fp);
}

void freeList(node *head){
    node *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}