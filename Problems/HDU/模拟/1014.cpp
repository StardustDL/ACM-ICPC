/*
Uniform Generator
题意：判断一个随机数生成方法是否概率平均，计算方法ai=(ai-1 + step)%mod
分析：模拟 
*/
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
const int MAXN=100000;
int random[MAXN+3],step,mod;
bool check(){
	random[0]=0;  //第一个数字永远是0   
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
