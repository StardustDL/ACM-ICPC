/*
Brackets
���⣺����һ��()[]���ţ�Ҫ������⴮���ŵ����ƥ���������'('��')'ƥ�䣬Ϊ2����'['��']'ƥ�䣬Ϊ2������������ƥ��
����������DP��ת�Ʒ�����[i..j]�����Ž�=i�ܺ�kƥ�� ? [i+1..k-1]+2+[k+1,j]:[i..j]��ע��Ҫ����kȫ��ɨһ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
char str[MAXN+3]; 
int opt[MAXN+3][MAXN+3],n;
int main(){
	while(scanf("%s",str+1),str[1]!='e'){
		n=strlen(str+1);
		memset(opt,0,sizeof(opt));
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				int &t=opt[i][j];
				t=opt[i+1][j];
				for(int k=i+1;k<=j;k++){
					if(str[i]=='('&&str[k]==')' || str[i]=='['&&str[k]==']')t=max(t,opt[i+1][k-1]+2+opt[k+1][j]);
				}
			}
		}
		printf("%d\n",opt[1][n]);
	}
	return 0;
}

