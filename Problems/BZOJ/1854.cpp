/*
[Scoi2010]��Ϸ
����������Ĳ��鼯������ 
		��һ����a,b�������Ե��������ɵ�a��b֮��������
		����һ����ͨ�飬���粻����������һ����������ô�ض������������������p-1���㡣
		����һ����ͨ�飬���纬������ô�ض�ȫ����p���㶼�����㡣
		��ô�ϲ����鼯��ʱ���������һ��vis��ά���������
		��Ȩֵ���ɵ㣬���������ɱ�
		���ÿ�μ���ı��Ǻϲ�������ͨ��
		�Ͱ�ȨֵС����ͨ�鲢��Ȩֵ�����ͨ�飬Ȼ���ȨֵС��vis=true
		�������
		�ͰѸ���ͨ��Ķ����vis=true
		�����Ϳ��Ա�֤�����һ����СΪN��ͨ��
		=N-1���߹��ɣ������vis=false������Ϊtrue
		��N���߹��ɣ����е��vis=true
		���ֻҪһ��ɨ��vis�Ϳ��Եó����� 
	  ��ͳ����ͼƥ�䣺ÿ�������������������� Ȼ���1~10000ö������ �ܶ���ͼ���ƥ�� �޷�ƥ��������� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
int pa[MAXN+3],n;
bool vis[MAXN+3]; 
int find(int x){return pa[x]==0?x:pa[x]=find(pa[x]);}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<=n;i++){
		scanf("%d%d",&u,&v);
		if(u>v)swap(u,v);
		int a=find(u),b=find(v);
		if(a==b)vis[a]=1;
		else pa[a]=b,vis[a]=1;
	}
	for(int i=1;i<=n+1;i++){
		if(!vis[i]){printf("%d",i-1);break;}
	}
	return 0;
}

