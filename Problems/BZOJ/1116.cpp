/*
[POI2008]CLO
��������������߲�������ȣ�����߹���һ����ȣ�����ֻҪһ����ͨ���к��л�����������������ͻ���һ����������
	  ����ж��л������鼯��link(a,b)��a,b����ͬһ�����ϣ�����������л����������ڣ��ϲ����¼����л�=�Ӽ���������һ���� 
	  ע���ȱ�ǣ����޸����Ľṹ 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int pa[MAXN+3];
bool mark[MAXN+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	//for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);a=find(a),b=find(b);
		if(a==b)mark[a]=1;
		else{
			mark[b]|=mark[a];
			pa[a]=b;//����д��:pa[find(a)]=find(b);mark[find(b)]|=mark[find(a)];�����ڶ��β���a�ĸ������Ѿ���b�ˣ�����Ȼ������Ҫ�� 
		}
	}
	for(int i=1;i<=n;i++)if(mark[find(i)]==0){puts("NIE");return 0;}
	puts("TAK");
	return 0;
}

