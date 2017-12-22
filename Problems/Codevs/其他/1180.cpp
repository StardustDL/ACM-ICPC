/*
中位数
分析：统计m位置左边的比m大的数个数-比m小的数的个数，对m右边一样处理
	  当x[i]==y[-i]时，即有x[i]*y[-i]种方案 
*/
#include<iostream>
using namespace std;
const int R=100000+3,MAXN=R<<1;
typedef long long LL;
int n,m,p,d[R],dx[MAXN+3],dy[MAXN+3],k;
LL ans;
int main(){
	cin>>n>>m;
	dx[R]=1,dy[R]=1;
	for(int i=1;i<=n;i++){
		cin>>d[i];if(d[i]==m)p=i;
	}
	k=0;
	for(int i=p-1;i>=1;i--){
		if(d[i]>m)k++;else k--;
		dx[R+k]++;
	}
	k=0;
	for(int i=p+1;i<=n;i++){
		if(d[i]>m)k++;else k--;
		dy[R+k]++;
	}
	for(int i=-n;i<=n;i++)
		ans+=dx[R+i]*dy[R-i];
	cout<<ans;
	return 0;
}
 
