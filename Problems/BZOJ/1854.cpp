/*
[Scoi2010]游戏
分析：这题的并查集做法： 
		把一个有a,b两种属性的武器看成点a，b之间的无向边
		对于一个联通块，假如不含环（就是一棵树），那么必定可以满足其中任意的p-1个点。
		对于一个联通块，假如含环，那么必定全部的p个点都能满足。
		那么合并并查集的时候可以利用一个vis来维护这个性质
		把权值看成点，把武器看成边
		如果每次加入的边是合并两个联通块
		就把权值小的联通块并到权值大的联通块，然后给权值小的vis=true
		如果不是
		就把该联通块的顶点的vis=true
		这样就可以保证，如果一个大小为N联通块
		=N-1条边构成，最大点的vis=false，其他为true
		≥N条边构成，所有点的vis=true
		最后只要一次扫描vis就可以得出答案了 
	  传统二分图匹配：每个武器向两个属性连边 然后从1~10000枚举属性 跑二分图最大匹配 无法匹配则输出答案 
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

