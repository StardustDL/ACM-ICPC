/*
Round Numbers
���⣺���һ������round number�������Ķ����Ʊ�ʾ�У�0�ĸ������ڵ���1�ĸ��������ڸ�һ�����ݷ�Χ[start, end]������һ������round number�ĸ���.(1 <= start < end <= 2,000,000,000) 
�������Ƚ���������ת��ǰ׺�͡�����Code��k=n�Ķ�����λ������ͳ�ƶ�����λ=1..k-1�Ĵ𰸣�
	  �ٶ���kλ�����ƣ�ͳ�Ʊ�nС����������ÿһλ���������1�����䵱��0��Ȼ���߼�λ����ȡ��������������������
	  Ҳ����˵11010�ĳ�10xxx��ʵ�ַ�����ͳ��ǰ���ж��ٸ�0��1.Ȼ�����֪����߲�ȷ���Ĳ��ֻ�������Ҫ���ٸ�0�ſ�������������
	  Ҫ����ע��λ������ż�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50;//MAXN���1000���ܲ������� 
int C[MAXN+3][MAXN+3]; 
bitset<MAXN+3> bit;
int table(int n,int m){
	if(n==0||m==0||n==1||m==n)return 1;
	if(C[n][m])return C[n][m];
	C[n-1][m]=table(n-1,m);
	C[n-1][m-1]=table(n-1,m-1);
	C[n][m]=C[n-1][m]+C[n-1][m-1];
	return C[n][m];
}
int solve(int n){
	bit=n;
	int ans=1,cnt=0;
	int temp=n;while(temp){temp>>=1;cnt++;}
	for(int i=1;i<cnt-1;i++){
		for(int j=((i&1)?(i>>1):((i+1)>>1))+1;j<=i;j++){
			ans+=table(i,j);
		}
	}
	int a=1,b=0;//a:1�ĸ�����b:0�ĸ��� 
	for(int i=cnt-2;i>=0;i--){
		if(bit[i]){
			int x=max(i+a-b-1,0);//t��ʾ��߿���������ϵ�λ������xΪ���������Ҫ��0�ĸ�����x + b + 1 = t - x + a��x = (t + a - b - 1)/2��ע��x����С��0
			for(int j=(x&1)?((x+1)>>1):(x>>1);j<=i;j++){
				ans+=table(i,j);
			}
			a++;
		}
		else b++;
	}
	if(b>=a)ans++;//�ж�n�ǲ���round number
	return ans; 
}
int main(){
	int l,r;
	while(~scanf("%d%d",&l,&r)){
		printf("%d\n",solve(r)-solve(l-1));
	}
	return 0;
} 
 
