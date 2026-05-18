#include<stdio.h>

typedef struct{
    char name[50];
    // int id;
}Student;

void input(Student s[], int n);
void writeToTextFile(char *filename, Student s[],int n);
void createRecordOffsets(char *filename, long arr[], int n);
void readFromTextFile(int m, char *filename, Student s[], long arr[]);
void displayRecord(Student s[]);

int main(){
    int n, m;
    char filename[] = "file.txt";
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid size!");
        return 0;
    }
    Student s[n], s2[n];
    long arr[n];

    printf("Enter %d records\n",n);
    input(s, n);
    writeToTextFile(filename, s, n);
    createRecordOffsets(filename, arr, n);
    printf("Enter record number (1 to %d): ", n);    
    scanf("%d",&m);
    if(m<1 || m>n){
        printf("Invalid search!");
        return 0;
    }
    readFromTextFile(m, filename, s2, arr);
    displayRecord(s2);
    return 0;
}

void input(Student s[], int n){
    for(int i=0;i<n;i++){
        printf("Record %d\n",i+1);
        printf("Name: ");
        scanf("%s",s[i].name);
        // printf("Id: ");
        // scanf("%d", s[i].id);
    }
}

void writeToTextFile(char *filename, Student s[],int n){
    FILE *fp;
    fp=fopen(filename, "w");
    if(fp==NULL){
        printf("Failed to open file!");
        return;
    }
    for(int i=0;i<n;i++){
        fprintf(fp, "%s\n", s[i].name);
    }
    fclose(fp);
}

void createRecordOffsets(char *filename, long arr[], int n){
     FILE *fp;
    fp=fopen(filename, "r");
    if(fp==NULL){
        printf("File open error!");
        return;
    }
    char temp[50];
    for(int i=0;i<n;i++){
        arr[i]=ftell(fp);
        if(fscanf(fp,"%s", temp)!=1){
        printf("Read error!");
        fclose(fp);
        return;
    }
    }
    fclose(fp);
}

void readFromTextFile(int m, char *filename, Student s[], long arr[]){
    FILE *fp;
    fp=fopen(filename, "r");
    if(fp==NULL){
        printf("File open error!");
        return;
    }
    fseek(fp, arr[m-1], SEEK_SET);
    if(fscanf(fp,"%s", s[0].name)!=1){
        printf("Read error!");
        fclose(fp);
        return;
    }
    fclose(fp);
}

void displayRecord(Student s[]){
    printf("%s\n", s[0].name);
}
