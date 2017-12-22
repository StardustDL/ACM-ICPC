/*
SUBTRACT 
���⣺����һ�ֲ���������i���ǽ�a[i]-a[i+1]ȡ�����кϲ����ټ��뵽a[i]��λ�ã����Լ��ܲ�����⣩������n-1�β����󣬻�ʣ��һ�����֡�����a[1]~a[n]��Ŀ��t�����ʣ�µ����֣��������˳��
�����������൱��������֮�����+-���ַ���ʹ�ô���t�������+-����������ˣ�PS����һ�����űض��Ǽ��ţ�
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f,R=10000;
int can[MAXN+3][R+3<<1];
bool op[MAXN+3];
int n,T,a[MAXN+3];
int main(){
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(can,0,sizeof(can));
	can[1][a[1]+R]=1;
	can[2][a[1]-a[2]+R]=-1;
	for(int i=3;i<=n;i++){
		for(int j=0;j<=R<<1;j++){
			if(can[i-1][j]==0)continue;
			if(j+a[i]<=R<<1)can[i][j+a[i]]=1;//�� 
			if(j-a[i]>=0)can[i][j-a[i]]=-1;//�� 
		} 
	}
	for(int i=n,j=R+T;i>=1;i--){
		op[i]=can[i][j]==1;
		j-=a[i]*can[i][j];
	}
	int cnt=0;
	for(int i=2;i<=n;i++)if(op[i])printf("%d\n",i-cnt-1),cnt++;
	for(int i=2;i<=n;i++)if(!op[i])puts("1");
	return 0;
}

