/*
寻宝
*/
#include<cstdio>
using namespace std;
struct room{
	int z;
	bool isy;
	room(){}
	room(int i,bool k){
		z=i;isy=k;
	}
}rs[10002][101];
int a[10002],ans=0,n,m,st=0;
int main(){
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			scanf("%d %d",&x,&y);
			rs[i][j]=room(y,x);
			if(x==1)a[i]++;
		}
	}
	scanf("%d",&st);
	int curr=st;
	for(int i=1;i<=n;i++){
		int next=rs[i][curr].z;
		ans=(ans+next)%20123;
		int j=curr,p=0;
		while(next>a[i])next-=a[i];//这个优化很重要 
		while(1){
			if(rs[i][j].isy)
				if(++p==next)break;
			j++;
			if(j==m)j=0;
		}
		curr=j;
	}
	printf("%d",ans);
	return 0;
}
