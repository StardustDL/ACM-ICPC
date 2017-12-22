/*
Color a Tree
题意：一棵树，结点树为n，根结点为r。每个结点都有一个权值ci，开始时间为0，每染色一个结点需要耗时1，每个结点的染色代价为ci*ti（ti为当前的时间），每个结点只有在父结点已经被染色的条件下才能被染色。求染完整棵树需要花费的最小代价。
分析：贪心：根据：对于一个非根结点，它具有非根结点的最大权值，那么访问完它的父亲后就要立即访问它才能使得代价最小。
	  所以可以对这样的点与其父节点合并，定义这样的权值为：Ci/Ti,Ci=i结点所包含的总价值,Ti=i结点包含的实际结点数
	  每次找此权值最大的非根结点，与其父节点合并
	  答案的计算：ans=sigma(wi)+sigma( fa(i).time*i.c |i=1..n,expect root)
	  相当于每次找到最大的权值，需要fa(i).time的时间才能轮到染此节点 
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

