#include<stdio.h>

int userDecision(char a);

union decision{
    unsigned char flags;

    struct{
        unsigned int your_choice:1; /* tobe computed */
        unsigned int your_mothers_choice:1;
        unsigned int your_fathers_choice:1;
        unsigned int socially_acceptable:1;
        unsigned int financially_viable:1;
        unsigned int do_you_aptitude:1;
        unsigned int do_you_likeit:1;
        unsigned int decision:1; /* to be computed */
    }field;
};

union decision input();
int userDecision(char a);
void make_decision(union decision *d);
void print_decision(union decision d);
void print_conclusion_based_on_flags( union decision d);

int main(){
    union decision d=input();
    make_decision(&d);
    print_decision(d);
    print_conclusion_based_on_flags(d);
    return 0;
}

union decision input(){
    union decision d;
    d.flags=0;
    char a;
    printf("Is it your choice?(y/n)");
    scanf(" %c",&a);
    d.field.your_choice=userDecision(a);

    printf("Is it your mother's choice?(y/n)");
    scanf(" %c",&a);
    d.field.your_mothers_choice=userDecision(a);
    
    printf("Is it your father's choice?(y/n)");
    scanf(" %c",&a);
    d.field.your_fathers_choice=userDecision(a);
    
    printf("Is it socially acceptable?(y/n)");
    scanf(" %c",&a);
    d.field.socially_acceptable=userDecision(a);
    
    printf("Is it financially viable?(y/n)");
    scanf(" %c",&a);
    d.field.financially_viable=userDecision(a);
    
    printf("Do you have aptitude?(y/n)");
    scanf(" %c",&a);
    d.field.do_you_aptitude=userDecision(a);
    
    printf("Do you like it?(y/n)");
    scanf(" %c",&a);
    d.field.do_you_likeit=userDecision(a);

    return d;
}

int userDecision(char a){
    if(a=='y'){
        return 1;
    }
    else{
        return 0;
    }
}

void make_decision(union decision *d){
    int score=0;

    score += d->field.your_choice;
    score += d->field.your_mothers_choice;
    score += d->field.your_fathers_choice;
    score += d->field.socially_acceptable;
    score += d->field.financially_viable;
    score += d->field.do_you_aptitude;
    score += d->field.do_you_likeit;
    
    if((d->field.your_choice && d->field.financially_viable 
        && d->field.do_you_aptitude && d->field.do_you_likeit) || score>=5){
            d->field.decision=1;
        }
    else{
        d->field.decision=0;
    }
}

void print_decision(union decision d){
    printf("\n------Your Final Decisions-------\n");
    printf("Your Choice: %s\n", d.field.your_choice ? "YES" : "NO");
    printf("Your Mother's Choice: %s\n", d.field.your_mothers_choice ? "YES" : "NO");
    printf("Your Father's Choice: %s\n", d.field.your_fathers_choice ? "YES" : "NO");
    printf("Is it socially acceptable? : %s\n", d.field.socially_acceptable ? "YES" : "NO");
    printf("Is it financially acceptable? : %s\n", d.field.financially_viable ? "YES" : "NO");
    printf("Do you have aptitude? : %s\n", d.field.do_you_aptitude ? "YES" : "NO");
    printf("Do you like it? : %s\n", d.field.do_you_likeit ? "YES" : "NO");
    printf("Your Final Decision: %s\n", d.field.decision ? "YES" : "NO");
}

void print_conclusion_based_on_flags( union decision d){
    int temp = d.flags;
    int count=0;
    while(temp){
        count += temp & 1;
        temp = temp>>1;
    }
    printf("\nFlags Positive Count: %d\n", count);
    if(count==8){
        printf("Perfect!");
    }
    else if(count>=4){
        printf("Do It!");
    }
    else if(count>2){
        printf("Think carefully");
    }
    else{
        printf("Poor decision");
    }
}
