/*
³Ë³Ë³Ë£¡
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cctype>
using namespace std;
double _log10(int n){
    return log(n+0.0)/log(10.0);
}
double fac[1000000];
string str;
int len;
int sol(){
    double sum=0;
    for(int i=0;i<len;){
        if(isdigit(str[i])){
            int num=0;
            for(;i<len&&isdigit(str[i]);i++)num=num*10+str[i]-'0'; 
            if((i<len&&str[i]=='*')||i==len){
                sum+=_log10(num);
                i++;
                continue;
            }
            else if(i<len&&str[i]=='^'){
                i++;int f=0;
                for(;i<len&&isdigit(str[i]);i++)f=f*10+str[i]-'0';
                sum+=f*_log10(num);
                i++;
                continue;
            }
            else if(i<len&&str[i]=='!'){
                i+=2;
                sum+=fac[num];
                continue;
            }
        }
        else i++;
    }
    return (int)sum+1;
}
int main(){
    for(int i=1;i<1000000;i++) fac[i]=fac[i-1]+_log10(i);
    char ch;
    while(cin>>ch)str+=ch;
    len=str.size();
    int cnt=sol();
    printf("%d\n",cnt);
    return 0;
}

