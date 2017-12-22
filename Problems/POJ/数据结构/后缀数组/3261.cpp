/*
Milk Patterns
题意：可重叠的k次最长重复子串。
分析：后缀数组。先二分答案，然后将后缀分成若干组。这里要判断的是有没有一个组的后缀个数不小于k。如果有，那么存在k个相同的子串满足条件，否则不存在。时间复杂度为O(nlogn)。  
*/
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=20000,MAXM=100000;
int str[MAXN+3];
int wa[MAXN+3],sa[MAXN+3],wb[MAXN+3],wv[MAXN+3],wt[MAXM+3];
int height[MAXN+3],rank[MAXN+3];
int N,K;
bool cmp(int *t,int a,int b,int l){
	return t[a]==t[b]&&t[a+l]==t[b+l];
}
void SuffixSort(int* str,int *sa,int n,int m){
	int *x=wa,*y=wb,i,j,p,*t;
	for(i=0;i<m;i++)wt[i]=0;
	for(i=0;i<n;i++)wt[x[i]=str[i]]++;
	for(i=1;i<m;i++)wt[i]+=wt[i-1];
	for(i=n-1;i>=0;i--)sa[--wt[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;i++)wt[i]=0;
		for(i=0;i<n;i++)wv[i]=x[y[i]];
		for(i=0;i<n;i++)wt[wv[i]]++;
		for(i=1;i<m;i++)wt[i]+=wt[i-1];
		for(i=n-1;i>=0;i--)sa[--wt[wv[i]]]=y[i];
		swap(x,y);
		for(p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}
void calheight(int* str,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++)rank[sa[i]]=i;
	for(i=0;i<n;i++){
		if(k)k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank[i]]=k;
	}
}
bool check(int k){
	int cnt,i=2;
	while(true){
		while(i<=N&&height[i]<k)i++;
		if(i>N)break;
		cnt=1;//注意，这里包含i-1，因为height定义是i和i-1组成的LCP 
		while(i<=N&&height[i]>=k){
			cnt++;
			i++;
		}
		if(cnt>=K)return true;
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
	scanf("%d%d\n",&N,&K);
	for(int i=0;i<N;i++)scanf("%d",&str[i]);
	str[N]=0;
	SuffixSort(str,sa,N+1,MAXM);
	calheight(str,N);
	printf("%d\n",ef(1,N));
	return 0;
}

