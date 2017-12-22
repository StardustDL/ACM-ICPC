/*
Eva's Problem
分析：水题一道 
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int f[6];
int main(){
    int t;scanf("%d", &t);
    while(t--){
        for(int i=0;i<4;i++)scanf("%d",&f[i]);
        if(f[3]-f[2]==f[2]-f[1])f[4]=f[3]+f[3]-f[2];
        else f[4]=f[3]*f[3]/f[2];
        printf("%d",f[0]);
        for(int i=1;i<5;i++)printf(" %d",f[i]);
        puts(""); 
    }
    return 0;
}
