/*
[HAOI2007]反素数ant
分析：按质因数搜索，有几个剪枝 
*/
#include<cstdio>
using namespace std;
int anst,a[15]={1,2,3,5,7,11,13,17,19,23,29,31};
long long ans,n;
int b[15]={1000};//保证第一个的值足够大 
void dfs(int x,long long y,int cnt){
	y*=a[cnt];x=x/(b[cnt]+1)*(b[cnt]+2);//若乘上第cnt个质数，因子数就变成 x/(b[cnt]+1)*(b[cnt]+2);
	if(y>n||x<=anst&&y>=ans)return;//剪枝，若因子较少，且值较大，跳。
	b[cnt]++;
	if(x>=anst)anst=x,ans=y;
	if(b[cnt+1]<b[cnt])dfs(x,y,cnt+1);//优先枚举因子更大的，因为可以通过anst剪掉很多小因子数如2~8。
	if(b[cnt]<b[cnt-1])dfs(x,y,cnt);//b[0]对应这里 
    b[cnt]--;
}
int main(){
	scanf("%d",&n);
	dfs(1,1,1);
	printf("%d\n",ans);
	return 0;
}
