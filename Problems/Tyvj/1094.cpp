/*
���ηָ�
����������һ����Ҫ��ȷ�����������ΪҪ�ֳ�1*1�ĸ��ӣ�����ÿһ���߿϶���Ҫ�У�ֻ�������еĴ����Ķ���������ͬ������ÿһ���ݱ���˵��������Ҫ�еô��������������������֮ǰ���Ѿ��еĺ�ߵĴ��������ں�߾Ϳ��ݱߡ�������һ������Ȼ���뷨�����ô��۴�����У������Ļ�������۴���еô����١��Ѻ�ߺ��ݱ��Ÿ���Ȼ�󲻶ϵ�ά��ans���ɡ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
struct edge{
	int c;bool ish;
	bool operator < (const edge &e)const{
		return c>e.c;
	}
}es[MAXN*2];
int n,m,h=1,l=1,ans=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)scanf("%d",&es[i].c),es[i].ish=1;
	for(int i=1;i<m;i++)scanf("%d",&es[n+i-1].c),es[n+i-1].ish=0;
	sort(es+1,es+n+m-1);
	for(int i=1;i<n+m-1;i++){
		if(es[i].ish){
			ans+=es[i].c*l;
			h++;
		}
		else{
			ans+=es[i].c*h;
			l++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

