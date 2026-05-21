#include<stdio.h>

struct BitField{
    unsigned int u1: 1;
    unsigned int u2: 3;
    signed int s1: 5;
    signed int s2: 4;
};

int main(){
    struct BitField a;
    a.u1=0;
    a.u2=5;
    a.s1=-8;
    a.s2=-4;
    printf("%d\n",a.u1);
    printf("%d\n",a.u2);
    printf("%d\n",a.s1);
    printf("%d\n",a.s2);
    return 0;
}