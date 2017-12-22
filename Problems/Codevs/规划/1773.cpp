/*
创新吃鱼法
分析：最大对角线为1子正方形，方法很好，要记住，还有要用scanf 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2500;
typedef int arr[MAXN+3][MAXN+3];
int n,m,ans=0;
arr mp,opt,lft,up,down;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			if(mp[i][j])lft[i][j]=up[i][j]=0;
			else{
				lft[i][j]=lft[i][j-1]+1;
				up[i][j]=up[i-1][j]+1;
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(mp[i][j])down[i][j]=0;
			else down[i][j]=down[i+1][j]+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]){
				opt[i][j]=min(lft[i][j-1]+1,min(opt[i-1][j-1]+1,up[i-1][j]+1));
				ans=max(ans,opt[i][j]);
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(mp[i][j]){
				opt[i][j]=min(lft[i][j-1]+1,min(opt[i+1][j-1]+1,down[i+1][j]+1));
				ans=max(ans,opt[i][j]);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
