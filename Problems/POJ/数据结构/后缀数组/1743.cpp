/*
Musical Theme
题意：有N(1 <= N <=20000)个音符的序列来表示一首乐曲，每个音符都是1..88范围内的整数，现在要找一个重复的主题。“主题”是整个音符序列的一个子串，它需要满足如下条件：
    	1.长度至少为5个音符。
    	2.在乐曲中重复出现。(可能经过转调，“转调”的意思是主题序列中每个音符都被加上或减去了同一个整数值)
    	3.重复出现的同一主题不能有公共部分。 
分析：后缀数组。求出任意相邻音符的差值，然后把问题转化为 不可重叠最长重复子串，用后缀数组来做。先二分答案，把题目变成判定性问题：判断是否存在两个长度为k的子串是相同的，且不重叠。解决这个问题的关键还是利用 height数组。把排序后的后缀分成若干组，其中每组的后缀之间的height值都不小于k。
	  容易看出，有希望成为最长公共前缀不小于 k 的两个后缀一定在同一组。然后对于每组后缀，只须判断每个后缀的 sa 值的最大值和最小值之差是否不小于k。如果有一组满足，则说明存在，否则不存在。整个做法的时间复杂度为
	  O(nlogn)。本题中利用 height 值对后缀进行分组的方法很常用
*/
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=20000+50;
int str[MAXN+3];
int wa[MAXN+3],sa[MAXN+3],wb[MAXN+3],wv[MAXN+3],wt[MAXN+3],n;
int height[MAXN+3],rank[MAXN+3];
bool cmp(int *t,int a,int b,int l){
	return t[a]==t[b]&&t[a+l]==t[b+l];
}
void da(int* str,int *sa,int n,int m){
	int *x=wa,*y=wb,i,j,p,*t;
	for(i=0;i<m;i++)wt[i]=0;
	for(i=0;i<n;i++)wt[x[i]=str[i]]++;
	for(i=1;i<m;i++)wt[i]+=wt[i-1];
	for(i=n-1;i>=0;i--)sa[--wt[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;i++)wt[i]=0;
		for(i=0;i<n;i++)wt[wv[i]=x[y[i]]]++;
		for(i=1;i<m;i++)wt[i]+=wt[i-1];
		for(i=n-1;i>=0;i--)sa[--wt[wv[i]]]=y[i];
		swap(x,y);
		for(p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}
void calheight(int* str,int n){
	int i,j,k=0;
	for(i=0;i<=n;i++)rank[sa[i]]=i;//注意这种写法必须含n，其实i=0没有用，因为rank[sa[0]]=n，这在下面的循环中用不到，而若i<n则会有位置rank[i]=0，接下来的rank[i]-1就超界了 
	for(i=0;i<n;i++){
		if(k)k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank[i]]=k;
	}
}
/*void calheight(int *r, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i ++]] = k)
    {
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++); 
    }
}*/
bool check(int k){
	int mx=-1,mn=INF,i=2;
	while(true){
		while(i<=n&&height[i]<k)i++;
		if(i>n)break;
		mx=mn=sa[i-1];//注意，这里包含sa[i-1]，因为height定义是i和i-1组成的LCP 
		while(i<=n&&height[i]>=k){
			mx=max(mx,sa[i]);
			mn=min(mn,sa[i]);
			i++;
		}
		if(mx-mn>=k)return true;
	}
	return false;
}
int ef(int l,int r){
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	return l;
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++)scanf("%d",&str[i]);
		if(n<10){puts("0");continue;}
		n--;
		for(int i=0;i<n;i++)str[i]=str[i+1]-str[i]+89;
		str[n]=0;
		da(str,sa,n+1,200);
		calheight(str,n);
		//puts("!!!");
		int ans=ef(4,(n-1)>>1);
		printf("%d\n",ans<4?0:ans+1);
	}
	return 0;
}

/*

int main()
{
    int i, ans;
    while(scanf("%d", &n) && n != 0)
    {
        for(i = 0; i < n; i ++)
        {
            scanf("%d", &str[i]);
        }
        if(n < 10) {
            printf("0\n");
            continue;
        }
        n --;
        for(i = 0; i < n; i ++)
        {
            str[i] = str[i+1] - str[i] + 89;
        }
        str[n] = 0;
        da(str ,n + 1, 200);
        calheight(str, n);
        
        int low = 4, high = (n-1)/2, mid;
        while(low < high)
        {
            mid = (low + high + 1) / 2;
            if(valid(mid)) {
                low = mid;
            }else {
                high = mid - 1;
            }
        }
        ans = low < 4 ? 0 : low + 1;
        printf("%d\n", ans);
    }
    return 0;
}*/

