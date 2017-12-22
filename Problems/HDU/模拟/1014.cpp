/*
Uniform Generator
���⣺�ж�һ����������ɷ����Ƿ����ƽ�������㷽��ai=(ai-1 + step)%mod
������ģ�� 
*/
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
const int MAXN=100000;
int random[MAXN+3],step,mod;
bool check(){
	random[0]=0;  //��һ��������Զ��0   
	for(int i=1;i<=mod-1;i++)random[i]=(random[i-1]+step)%mod;  
	sort(random,random+mod);  
	for(int i=0;i<mod;i++)if(random[i]!=i)return false;
	return true; 
}
int main(){  
    while(cin>>step>>mod){  
        if(check())printf("%10d%10d    Good Choice\n\n",step, mod);  
        else printf("%10d%10d    Bad Choice\n\n",step, mod);  
    }  
    return 0;  
}
