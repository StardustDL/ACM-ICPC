/*
[POI2005]ska Piggy banks
������һ��ֱ�ӵ�˼·��ǿ��ͨ���㣬ͳ�����Ϊ0�ĵ㣬���ǿռ�̫��
	  ��һ��˼·�����鼯������һ����(a,b)��b����a�����ͳ��pa[i]==i�ĸ������Ǵ� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
int pa[MAXN+3],ans=0,n; 
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(find(i)!=find(x))pa[find(i)]=find(x);//ע������pa[i]==0Ϊ��ֹ����������Ҫ��һ���жϣ���֤����һ�����ϣ��������п��ܻὫpa[i]=0�ĳ�pa[i]=i��ʹ��֮���find��ջ 
	}
	for(int i=1;i<=n;i++)ans+=pa[i]==0;
	printf("%d\n",ans);
	return 0;
}

