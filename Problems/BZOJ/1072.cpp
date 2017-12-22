/*
[SCOI2007]排列perm
分析：状压DP：f[S][i]表示状态为S，模d为i的数量，在S后面补东西来转移。
	  注意，如果原数中有重复的，那么算出来也就会有重复的，用最后的答案除以cnt[i]的阶乘就可以了。 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,MAXD=(1<<10)+10;
int f[MAXD+3][MAXN+3],cnt[10];
inline int read(){
    int x=0;bool sig=true;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')sig=false;
    for(;isdigit(ch);ch=getchar())x=10*x+ch-'0';return sig?x:-x;
}
inline void write(int x){
    if(x==0){putchar('0');return;}if(x<0)putchar('-'),x=-x;
    int len=0;static int buf[20];while(x)buf[len++]=x%10,x/=10;
    for(int i=len-1;i>=0;i--)putchar(buf[i]+'0');
}
int T,d,lim,len,A[10],ans;char s[10];
int main(){
    T=read();
    while(T--){
        scanf("%s",s);d=read();memset(f,0,sizeof(f));memset(cnt,0,sizeof(cnt));
        for(int i=0;s[i];i++)cnt[A[i]=s[i]-'0']++;
		lim=1<<(len=strlen(s));
        f[0][0]=1;
        for(int S=0;S<lim;S++)
            for(int i=0;i<d;i++)
                for(int j=0;j<len;j++)if(!(S&(1<<j)))
                    f[S|(1<<j)][(10*i+A[j])%d]+=f[S][i];
        ans=f[lim-1][0];
        for(int i=0;i<10;i++)
            for(int j=1;j<=cnt[i];j++)ans/=j;
        write(ans);puts("");
    }
    return 0;
}
