/*
Truck History
���⣺��һ��7λ��string����һ����ţ��������֮���distance�������������֮�䲻ͬ��ĸ�ĸ�����һ�����ֻ������һ����š����������������������������֮����Ӧ��distance������Ҫ�ҳ�һ����������������ʹ���ܴ�����С��Ҳ����distance֮����С�� 
�������������ת��Ϊ��С���������������⡣��Ϊÿ�������֮�䶼��·������������ȫͼ���ؼ��ǽ�����ת��Ϊ��С�����������⡣ÿһ�����Ϊͼ��һ�����㣬�����붥���ı�ŲΪ�����ߵ�Ȩֵ����Ŀ��Ҫ�ľ������������С����������
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
	edge(){}
	bool operator < (const edge &e)const {
		return w<e.w; 
	}
}es[MAXN*MAXN+3];
int n,ans=0,tot=0,pa[MAXN+3];
char str[MAXN+3][13];
int calcw(int i,int j){
	int ans=0;
	for(int l=0;l<7;l++){
		if(str[i][l]!=str[j][l])ans++;
	}
	return ans;
}
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
int main(){
	while(scanf("%d",&n),n){
		ans=tot=0;memset(pa,0,sizeof(pa));
		for(int i=1;i<=n;i++)getchar(),scanf("%s",str[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				es[++tot]=edge(i,j,calcw(i,j));
			}
		}
		
		sort(es+1,es+tot+1);//cout<<"!!!"<<endl; 
		for(int i=1,cnt=0,a,b;i<=tot&&cnt<n-1;i++){
			a=find(es[i].u),b=find(es[i].v);
			if(a!=b)pa[a]=b,cnt++,ans+=es[i].w; 
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}

