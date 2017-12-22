/*
[HAOI2007]上升序列
分析：先要求出以每个数开头的最长上升子序列长度，但是LIS最终得出的是每个数字结尾的最长子序列长度，所以我们需要把这个序列倒过来做，倒过来DP，求出在倒着的序列中，以每个数字结尾的最长下降子序列长度，这就相当于原序列中以每个数字开头的最长上升子序列长度了。
	  然后再输出答案即可，注意并不需要记录 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000; 
int n,m,cnt,a[MAXN+3],f[MAXN+3],best[MAXN+3],len; //f[i]=以第i个数字结尾的最长下降子序列长度（等价于以第i个数字开头的最长上升子序列长度），best[i]=长度为i的LIS的第i个元素,cnt=LIS长度
void solve(int x){ //输出长度为x的上升子序列
	int last=0; //已经输出的上升序列的最后一个数字
	for(int i=1;i<=n;i++)
		if(f[i]>=x&&a[i]>last){
			printf("%d",a[i]);
			if(x!=1)putchar(' ');//不是输出最后一个数字，就要输出空格，BZOJ好像不会过滤掉行末空格，所以要这样做，防WA
			last=a[i];
			x--;
			if(!x) break;
		}
	puts(""); 
}
int ef(int x){ //二分寻找大于x且最接近x的元素，注意lower_bound:指向键值>= key的第一个元素；upper_bound:指向键值> key的第一个元素 
	int l=1,r=cnt,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(best[mid]>x){ans=mid;l=mid+1;}
		else r=mid-1;
	}
	return ans;
}
void preDP(){ //DP预处理
	for(int i=n;i>=1;i--){
		int t=ef(a[i])+1;
		f[i]=t;
		cnt=max(cnt,t);
		best[t]=max(best[t],a[i]);
	}
	//若想使用lower_bound，首先得是正数的最长上升子序列，对于最长下降，得转成负数，这样还不如自己写二分 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	preDP();
	scanf("%d",&m);
	while(m--){
		scanf("%d",&len);
		if(len<=cnt)solve(len);
		else puts("Impossible");
	}
	return 0;
}
