/*
[Noi2014]动物园
分析：题目不错，首先求出next数组，顺便求出cnt数组，cnt[i]代表长度为i的前缀经过几次j=next[j]会得到0
	  cnt[i]=cnt[next[i]]+1,再匹配一次，这次要求 长度*2>i 时也视为失配，因为这样就会重叠
	  num[i]=cnt[next'[i]] 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1000000,INF=0x3f3f3f3f;
const LL MOD=1000000007;
int n,nxt[MAXN+3],cnt[MAXN+3],len,tmp=0;
LL ans=1;
char str[MAXN+3];
int main(){
	scanf("%d",&n);
	while(n--){
		ans=1;
		scanf("%s",str+1);
		len=strlen(str+1);
		cnt[1]=1;tmp=0;
		nxt[0]=nxt[1]=0;
		for(int i=2;str[i];i++){
			while(tmp&&str[tmp+1]!=str[i])tmp=nxt[tmp];
			nxt[i]=(tmp+=str[tmp+1]==str[i]);
			cnt[i]=cnt[tmp]+1;
		}
		tmp=0;
		for(int i=2;str[i];i++){
			while(tmp&&str[tmp+1]!=str[i])tmp=nxt[tmp];
			for(tmp+=str[tmp+1]==str[i];tmp>(i>>1);)tmp=nxt[tmp];
			(ans*=cnt[tmp]+1)%=MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

