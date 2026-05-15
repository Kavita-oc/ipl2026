#include<stdio.h>
#include<string.h>

typedef struct{
    char name[50];
    int roll;
}Student;

void input(int n, Student s[]);
void writeToBin(const char *filename, Student s[], int n);
void readFromBin(const char *filename, Student s[], int m);
void print(Student s[], int n);
void deleteRecord(int d, int n, Student s[], const char *filename);


int main(){
    int n, m, d;
    const char filename[]="file.bin";
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    getchar();
    if(n<=0){
        printf("Invalid input!");
        return 0;
    }
    Student s[n],s2[1], s3[n];

    input(n, s);
    writeToBin(filename, s, n);
    printf("Enter record number: ");
    scanf("%d",&m);
    if(m<1 || m>n){
        printf("Invalid request!");
        return 0;
    }
    readFromBin(filename, s2, m);
    print(s2, 1);
    printf("Enter the record to delete: ");
    scanf("%d",&d);
    getchar();
    if(d < 1 || d > n){
        printf("Invalid record!");
        return 0;
    }
    deleteRecord(d, n, s3, filename);
    printf("Updated database:\n");
    print(s3, n-1);
    return 0;
}

void input(int n, Student s[]){
    for(int i=0;i<n;i++){
        printf("Student %d\n",i+1);
        printf("Roll no.: ");
        scanf("%d", &s[i].roll);
        getchar();
        printf("Name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")]= '\0';
    }
}

void writeToBin(const char *filename, Student s[], int n){
    FILE *fp;
    fp=fopen(filename, "wb");
    if(fp==NULL){
        printf("Unable to open file!");
        return;
    }
    if(fwrite(s, sizeof(Student), n, fp)!=n){
        printf("Write Error!");
    }
    fclose(fp);
}

void readFromBin(const char *filename, Student s[], int m){
    FILE *fp;
    fp=fopen(filename, "rb");
    if(fp==NULL){
        printf("Unable to open file!");
        return;
    }

    fseek(fp, (m-1)*sizeof(Student), SEEK_SET);
    if(fread(&s[0], sizeof(Student), 1, fp)!=1){
        printf("Read Error!");
    }
  
    fclose(fp);
    return;
}

void print(Student s[], int n){
    for(int i=0;i<n;i++){
        printf("\nStudent %d\n", i+1);
        printf("Roll no.: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
    }
}

void deleteRecord(int d, int n, Student s[], const char *filename){
    FILE *fp;
    fp=fopen(filename, "rb");
    if(fp==NULL){
        printf("Unable to open file!");
        return;
    }
    int j=0;
    Student temp;
    for(int i=0;i<n;i++){
        if(fread(&temp, sizeof(Student), 1, fp)!=1){
            printf("Read Error!");
            fclose(fp);
            return;
        }
        if(i!=d-1){
            s[j]=temp;
            j++;
        }
    }
    fclose(fp);
    writeToBin(filename, s, n-1);
}
