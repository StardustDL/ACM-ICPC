/*
数字串
分析：用a数组存数列，同时再用一个b数组存a数组中元素出现的次数，例如：a=（1,2,3）
		则b[1]=1; b[2]=1; b[3]=1;
		然后用两个指针，i,j表示头和尾，每次inc(j)，然后把a[j]元素入队，如果a[j]在1..n的范围之内，且a[j]从未出现过(b[a[j]]=0)那么inc(k),k是一个计数器，表示队列中有多少个在1..n中的元素。
		把a[j]元素入队后，需要进行队头后移操作，即如果在a[j]入队后，队头元素出现了一次以上，那么队头出列，在队头出列后，若新的队头依然出现过，或者不在1..m的范围内，那么队头继续出队。
		当把多余的队头移除后，我们可以来判断k，如果当前k=n，而且当前队列长度(j-i+1)比记录中的值小，那么就用这个队列长度去更新最小值。
		重复以上操作直到j=m；
		输出队列长度最小值min。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=200000,INF=0x3f3f3f3f;
int n,m,a[MAXN+3],cnt[MAXN+3],k=0,ans=INF;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	for(int l=1,r=1;r<=n;r++){
		if((cnt[a[r]]++)==0)k++;
		while(cnt[a[l]]>1)cnt[a[l++]]--;
		if(k==m)ans=min(ans,r-l+1);
	}
	if(ans==INF)puts("NO");
	else printf("%d",ans); 
	return 0;
}

