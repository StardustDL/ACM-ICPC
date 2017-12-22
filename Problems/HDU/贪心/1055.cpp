/*
Color a Tree
���⣺һ�����������Ϊn�������Ϊr��ÿ����㶼��һ��Ȩֵci����ʼʱ��Ϊ0��ÿȾɫһ�������Ҫ��ʱ1��ÿ������Ⱦɫ����Ϊci*ti��tiΪ��ǰ��ʱ�䣩��ÿ�����ֻ���ڸ�����Ѿ���Ⱦɫ�������²��ܱ�Ⱦɫ����Ⱦ����������Ҫ���ѵ���С���ۡ�
������̰�ģ����ݣ�����һ���Ǹ���㣬�����зǸ��������Ȩֵ����ô���������ĸ��׺��Ҫ��������������ʹ�ô�����С��
	  ���Կ��Զ������ĵ����丸�ڵ�ϲ�������������ȨֵΪ��Ci/Ti,Ci=i������������ܼ�ֵ,Ti=i��������ʵ�ʽ����
	  ÿ���Ҵ�Ȩֵ���ķǸ���㣬���丸�ڵ�ϲ�
	  �𰸵ļ��㣺ans=sigma(wi)+sigma( fa(i).time*i.c |i=1..n,expect root)
	  �൱��ÿ���ҵ�����Ȩֵ����Ҫfa(i).time��ʱ������ֵ�Ⱦ�˽ڵ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000; 
struct node{
	int t,w,p;
	double k;
	void cal(){k=w*1.0/t;}
};
node ns[MAXN+3];
int n,rot;
bool input(){
	scanf("%d%d",&n,&rot);
	if(n+rot==0)return false;
	int a,b;
	for(int i=1;i<=n;i++){
		scanf("%d",&ns[i].w);
		ns[i].t=1;
		ns[i].k=ns[i].w;
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		ns[b].p=a;
	}
	return true;
}
int find(){
	double mx=0;int p=0;
	for(int i=1;i<=n;i++){
		if(i==rot)continue;
		if(ns[i].k>mx)mx=ns[p=i].k;
	}
	return p;
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++)ans+=ns[i].w;
	for(int i=1;i<n;i++){
		int p=find(),fa=ns[p].p;
		ns[p].k=0;
		ans+=ns[fa].t*ns[p].w;
		for(int j=1;j<=n;j++)if(ns[j].p==p)ns[j].p=fa;
		ns[fa].t+=ns[p].t;
		ns[fa].w+=ns[p].w;
		ns[fa].cal();
	}
	return ans;
}
int main(){
	while(input())printf("%d\n",solve());
	return 0;
}

