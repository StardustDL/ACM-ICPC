/*
送给圣诞夜的极光
分析：fillfeed 
*/
#include<cstdio>
using namespace std;
const int xp[12]={-2,-1,-1,-1,0,0,0,0,1,1,1,2};
const int yp[12]={0,-1,0,1,-2,-1,1,2,-1,0,1,0};
char a[103][103];
int n,m,ans=0;
void dfs(int x,int y){
	if(a[x][y]=='-'||x>n||y>m||x<1||y<1)return;
	a[x][y]='-';
	for(int t=0;t<12;t++)dfs(x+xp[t],y+yp[t]);
}
void pri(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j])
			printf("%c",a[i][j]);
			else printf("0");
		}
		printf("\n");
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=m;j++)
			scanf("%c",&a[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!='-'){
				ans++;dfs(i,j);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
