/*
u Calculate e
Ã‚“‚£∫º∆À„e 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
double cal(int a){
    int temp=1;
    double ret=0;
    for(int i=1;i<=a;i++){
        temp*=i;
        ret+=1.0/temp;
    }
    return ret+1; 
}
int main(){
    puts("n e");
    puts("- -----------");
    puts("0 1");
    puts("1 2");
    puts("2 2.5");
    for(int i=3;i<=9;i++)printf("%d %.9f\n",i,cal(i));
    return 0;
}
