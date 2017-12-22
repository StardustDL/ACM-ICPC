/*
Maximum repetition substring
题意： 
分析：枚举长度为L，然后看长度为L的字符串最多连续出现几次。
	  既然长度为L的串重复出现，那么str[0],str[l],str[2*l]……中肯定有两个连续的出现在字符串中（因为如果要重复出现（出现次数>1）那么就会包含）。
	  那么就枚举连续的两个，然后从这两个字符串进行匹配，看最多能匹配多远。其实就是匹配这两个的后缀的最长公共前缀 
	  即以str[i*l],str[i*l+l]前后匹配，这里是通过查询suffix(i*l),suffix(i*l+l)的最长公共前缀。 
	  通过rank值能找到i*l,与i*l+l的排名，我们要查询的是这段区间的height的最小值，通过RMQ预处理，达到查询为0(1)的复杂度，
	  设LCP长度为M(即为循环多次的总长度), 则答案显然为M / L + 1 （类比POJ2406，+1是因为匹配长度还要再加一个i..i+l这个区间的答案，可以画个图）, 但这不一定是最好的, 
	  因为答案的首尾不一定在我们枚举的位置上（L不整除M，差出M%L）. 解决方法是, 我们考虑M % L的值的意义, 我们可以认为是后面多了M % L个字符, 
	  但是我们更可以想成前面少了(L - M % L)个字符! 所以我们求后缀j * L - (L - M % L)与后缀(j + 1) * L - (L - M % L)的最长公共前缀。
	    即把之前的区间前缀L-M%L即可。
	  然后把可能取到最大值的长度L保存，由于 题目要求字典序最小，通过sa数组进行枚举，取到的第一组，肯定是字典序最小的。 
	  穷举长度 L 的时间是 n，每次计算的时间是 n/L。所以整个做法的时间复杂度是 O(n/1+n/2+n/3+……+n/n)=O(nlogn)。
	  自己想的另一种方法： 
		类比POJ2406：相当于求一子串，使得其包含的循环个数最大（即为2406所求内容）
		这样枚举区间左端点i，从i扫到n，每计算出一个next[j]值，就利用T=len/(j-next[j])计算循环出现个数，注意不存在循环的情况
		这样是O(n^2)的，但是可以进行优化 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000+5;
int wa[MAXN+3],wb[MAXN+3],wt[MAXN+3],wv[MAXN+3];
bool cmp(int *str,int a,int b,int l){
	return str[a]==str[b] && str[a+l]==str[b+l];
}
void da(int* str,int* sa,int n,int m){//排序后缀数组 
	int i,j,p,*x=wa,*y=wb;
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
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++; //这里错了一次y错写成str 
	}
}
int sa[MAXN+3],rank[MAXN+3],height[MAXN+3];
void calheight(int*str,int n){//计算height数组 
	int i,j,k=0;
	for(i=0;i<=n;i++)rank[sa[i]]=i;
	for(i=0;i<n;i++){
		if(k)k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank[i]]=k;
	}
}
int qmin[MAXN+3][18];
void rmqinit(int n,int* val){//预处理rmq 
	for(int i=1;i<=n;i++)qmin[i][0]=val[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			qmin[i][j]=min(qmin[i][j-1],qmin[i+(1<<j-1)][j-1]);
}
int rmquery(int l,int r){//rmq查询，查询以l开头和以r开头的后缀的最长公共前缀 
	l=rank[l],r=rank[r];
	if(l>r)swap(l,r); 
	l++;//注意这里 
	int m=floor(log10(r-l+1.0)/log10(2.0));
	return min(qmin[l][m],qmin[r-(1<<m)+1][m]);
}
char S[MAXN+3];
int cove[MAXN+3],n;
int ans[MAXN+3],tot,kase=0;
int main(){
	while(scanf("%s",S),S[0]!='#'){
		n=strlen(S);
		for(int i=0;i<n;i++)cove[i]=S[i]-'a'+1;
		//printf("%d\n",cove[0]);
		cove[n]=0;
		da(cove,sa,n+1,128);
		//puts("!!!");
		calheight(cove,n);
		rmqinit(n,height);
		int mx=0;tot=0;
		for(int l=1;l<n;l++){//枚举循环节长度 
			for(int i=0;i<n;i+=l){//枚举两个被覆盖的相邻位置i,i+l 
				int len=rmquery(i,i+l),tme=len/l+1,k=i-(l-len%l);//求出最长长度，循环出现次数，以及特殊判断 
				if(k>=0)if(rmquery(k,k+l)>=len)tme++;//特殊判断 
				if(tme>mx){
					mx=tme;
					ans[(tot=0)++]=l;
				}
				else if(tme==mx){
					ans[tot++]=l;
				}
			}
		}
		int len=-1,st;
		for(int i=0;i<=n&&len==-1;i++){
			for(int j=0;j<tot;j++){
				int l=ans[j];
				if(rmquery(sa[i],sa[i]+l)>=(mx-1)*l){
					len=l;
					st=sa[i];
					break;
				}
			}
		}
		printf("Case %d: ",++kase);
		for(int i=0;i<len*mx;i++)putchar(S[st+i]);
		puts("");
	}
	return 0;
}

