/*
最大子段和
分析：类似DP，对于当前这个数，有选和不选两种决策，注意全是负数的情况
	  另一种方法：维护最小前缀和，每次用当前前缀和-最小前缀和更新答案 
*/
#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int n,a,ans=-INF,cur=0;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		ans=max(ans,(cur=max(cur+a,a)));
	}
	printf("%d",ans);
	return 0;
}
/*#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int n,a,ans=-INF,cur=0,mn=0,sum=0;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		sum+=a;
		ans=max(ans,sum-mn);
		mn=min(mn,sum);
	}
	printf("%d",ans);
	return 0;
}*/
