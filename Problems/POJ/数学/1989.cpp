/*
The Cow Lineup
题意：给定一个序列，求其最短非子序列的长度。
分析：我们把序列划分为若干个区间，每个区间都包含(1~k)这些数字。
	  我们使划分的区间尽量多，方法就是从左到右一旦满足了包含所有字符，则立即停止该区间，从下一位开始一个新的区间。
	  答案就是划分的区间数＋1。
	  下面我们简单证明一下：对于一个有x个区间的序列，一定包含了所有长度为x的序列。
	  因为，对于任意一个长度为x的序列，只需要依次在x个区间中取出其对应位的元素即可组成。
	  对于一个最多有x个区间的序列，一定不能构成所有的长度为x+1的序列。
	  因为只需要取每个区间的最后一位，构成一个长度为x的序列，在最后加上一个刨除前x个区间后的剩余部分所不具有的字符即可。
	  这个长度为x+1的序列一定不是其子序列。
	  因为每个区间的最后一个元素都是在该区间中唯一的（当一个区间已经搜集了k-1个元素之后，一旦遇到最后一个元素就停止了，所以最后一个元素只有一个），
	  所以这个序列前x个元素在长串中的匹配位置是固定的，只能是每个区间的最后一个元素（无法左移）。
	  这样前x个元素耗尽了长串的x个区间，第x+1个元素就无法构成了。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXK=10000;
int n,k,t,cnt=0,ans=1;
bool vis[MAXK+3];
int main(){
	scanf("%d%d",&n,&k);
	memset(vis,0,sizeof(vis));
	while(n--){
		scanf("%d",&t);
		if(!vis[t]){
			vis[t]=1;
			if(++cnt==k){
				cnt=0;
				memset(vis,0,sizeof(vis));
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

