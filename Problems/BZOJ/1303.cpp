/*
[CQOI2009]��λ��ͼ
��������λ����Ҫ�����x������С��x����������ͬ�����������д��ڵ���Ϊ1��С�ڵ���Ϊ-1��ֻҪ��Ϊ�㼴�ɣ�
	  ����Ϊ�����������У���x��λ��������ɨ�����˷�ԭ��ͳ�ƴ𰸡�
	  ע��+0=-0���������ͳ�����Σ�����Ķ���l[i]*r[-i]+l[-i]*r[i] 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int n,b,pos,ans=0;
int a[MAXN+3],_l[2*MAXN+3],_r[2*MAXN+3],*l=&_l[MAXN],*r=&_r[MAXN]; 
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>b)a[i]=1;
		else if(a[i]<b)a[i]=-1;
		else a[pos=i]=0;
	}
	for(int i=pos,t=0;i>0;i--)l[t+=a[i]]++;
	for(int i=pos,t=0;i<=n;i++)r[t+=a[i]]++;
	ans=l[0]*r[0];
	for(int i=1;i<=n;i++)
		ans+=l[i]*r[-i]+r[i]*l[-i];
	printf("%d",ans);
	return 0;
}

