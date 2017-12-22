/*
Cipher
题意：给一个序列，a0,a1,a2...an-1。再给一个字符串，s0, s1, s2,...,sn-1(长度不够的用空格补上)。s[i]在a[i]位置输出得到一个新的串，重复这个过程k次，求最后的串。
分析：很明显的置换题，先求出每个位置的恒等变换长度（循环节），然后分别求答案（只需对k%len进行模拟） 
	  不能先求整个置换的循环节，这样会TLE 
	  读数很无语。。。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
int a[MAXN+3],n,k,cnt[MAXN+3];
char str[MAXN+3],ans[MAXN+3];
void init(){
	memset(cnt,0,sizeof(cnt));
	for(int i=0,t;i<n;i++){
		cnt[i]++;t=a[i];
		while(t!=i){
			cnt[i]++;
			t=a[t];
		}
	}
}
void solve(int k){
	for(int i=0,t,p;i<n;++i){
		p=a[i];
		t=k%cnt[p];
		while(t--)p=a[p];
		ans[p]=str[i];
	}
	ans[n]='\0';
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){scanf("%d",&a[i]);a[i]--;}
		init();
		while(scanf("%d",&k),k){
			getchar();//必须用getchar，不能用scanf("\n") 
			gets(str);
			for(int i=strlen(str);i<n;i++)str[i]=' ';
			solve(--k);
			puts(ans);
		}
		puts("");
	}
	return 0;
}

