/*
食物链
分析：比较高级的并查集，
	  可以将食物链关系转成并查集的边权，注意mod 3
	  不能用cin，即使开了优化还是TLE 
*/#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=50000;
struct uniset{
	int pa[MAXN+3],d[MAXN+3];//pa[a]==pa[b]=>d[i]=0:同类;d[i]=1:B吃A;d[i]=2:A吃B; 
	
	void init(int n){
		for(int i=1;i<=n;i++)pa[i]=i;
		memset(d,0,sizeof(d));
	}
	int find(int x){
		if(x!=pa[x]){
			int t=find(pa[x]);
			d[x]=(d[x]+d[pa[x]])%3;//此时pa[x]还没改变 
			pa[x]=t;
		}
		return pa[x];
	}
	bool unions(int a,int b,int t){//t取0(同类),1(a吃b),返回是否符合条件 
		int fa=find(a),fb=find(b);
		if(fa==fb){
			return ((d[b]-d[a]+3)%3==t);//利用d的定义得到 
		}
		pa[fb]=fa;
		d[fb]=(d[a]-d[b]+t+3)%3;//这一点是归纳得出，可以再仔细想想
		return true;
	}
}S;
int main(){
	int k,n,a,b,c,ans=0;
	scanf("%d %d\n",&n,&k);
	S.init(n);
	while(k-->0){
		scanf("%d %d %d",&a,&b,&c);
		if(c==b&&a==2||b>n||c>n)ans++;
		else if(!S.unions(b,c,a-1))ans++;
	}
	printf("%d",ans);
	return 0;
}
