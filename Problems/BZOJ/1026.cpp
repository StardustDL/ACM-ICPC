/*
[SCOI2009]windy��
��������λDP 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int f[15][15],base[15];
int A,B;
int count(int n){
	if(!n)return 0;
	int tmp=0,w=10;
	while(base[w]>n)w--;
	for(int i=1;i<w;i++)//ȡ����λ��С��n�� 
	    for(int j=1;j<=9;j++)
	        tmp+=f[i][j];
	int cur=n/base[w];//ȡ���λ
	for(int i=1;i<cur;i++)tmp+=f[w][i]; 
	n%=base[w];
	int pre=cur;
	for(int i=w-1;i;i--){//ǰw-iλ��ͬ 
		cur=n/base[i];
		for(int j=0;j<cur;j++)if(abs(pre-j)>=2)tmp+=f[i][j];
		if(i==1)if(abs(pre-cur)>=2)tmp++;//��ȫ��ͬ����һ��n�ǲ���windy�� 
		if(abs(cur-pre)<2)break;
		pre=cur;
		n%=base[i];
	}
	return tmp;
}
int main(){
	base[1]=1;
	for(int i=2;i<=10;i++)base[i]=base[i-1]*10;
	scanf("%d%d",&A,&B);
	for(int i=0;i<=9;i++)f[1][i]=1;
	for(int i=2;i<=10;i++)
	    for(int j=0;j<=9;j++)
	        for(int k=0;k<=9;k++)
	            if(abs(j-k)>=2)f[i][j]+=f[i-1][k];
	printf("%d\n",count(B)-count(A-1));
	return 0;
}
