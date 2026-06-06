#include<stdio.h>
#include<math.h>

#define MAX 100

typedef struct{
    int disk[MAX];
    int top;
    char name;
}Stack;

void push(Stack *s, int value){
    s->disk[++s->top]=value;
}

int pop(Stack *s){
    return s->disk[s->top--];
}

void moveDisk(Stack *from, Stack *to){
    int disk=pop(from);
    push(to,disk);
    printf("Move disk %d from %c to %c\n",disk,from->name,to->name);
}

void legalMove(Stack *a, Stack *b){
    if(a->top==-1){
        moveDisk(b,a);
    }
    else if(b->top==-1){
        moveDisk(a,b);
    }
    else if(a->disk[a->top]<b->disk[b->top]){
        moveDisk(a,b);
    }
    else{
        moveDisk(b,a);
    }
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    Stack src={.top=-1, .name='A'};
    Stack aux={.top=-1, .name='B'};
    Stack des={.top=-1, .name='C'};

    for(int i=n;i>=1;i--){
        push(&src,i);
    }
    
    int moves=pow(2,n)-1;
    printf("Total moves: %d\n",moves);

    if(n%2==0){
        Stack temp=aux;
        aux=des;
        des=temp;
    }

    for(int i=1;i<=moves;i++){
        if(i%3==1){
            legalMove(&src, &des);
        }
        else if(i%3==2){
            legalMove(&src, &aux);
        }
        else{
            legalMove(&aux, &des);
        }
    }
    return 0;
}