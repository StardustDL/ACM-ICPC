/*
矩形分割
分析：首先一个需要明确的问题就是因为要分成1*1的格子，所以每一条边肯定都要切，只不过是切的次数的多少有所不同。对于每一条纵边来说，它所需要切得次数等于在这条纵向边切之前的已经切的横边的次数。对于横边就看纵边。这样，一个很显然的想法就是让代价大的先切，这样的话满足代价大的切得次数少。把横边和纵边排个序，然后不断的维护ans即可。 
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

