/*
Max Sequence
���⣺����һ�����У����������������ص��������е����͡� 
����������������������ֶκͣ��ٴ��ҵ�����һ�飬ö���м�㣬ɨһ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int sec[MAXN+3],pre[MAXN+3],n,a[MAXN+3],ans=-INF;
int main(){
	while(~scanf("%d",&n),n){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sec[n+1]=0,pre[0]=0;ans=-INF;
		for(int i=1;i<=n;i++){//pre[i],sec[i]�������a[i] 
			pre[i]=max(0,pre[i-1])+a[i];
			sec[n-i+1]=max(0,sec[n-i+2])+a[n-i+1];
		}
		for(int i=2;i<=n;i++){//ע��ǰ׺��Сֵ���ܰ�������=0�ı߽� 
			pre[i]=max(pre[i-1],pre[i]);
			sec[n-i+1]=max(sec[n-i+1],sec[n-i+2]);
		} 
		for(int i=1;i<n;i++)ans=max(ans,pre[i]+sec[i+1]);
		printf("%d\n",ans);
	}
	return 0;
}

