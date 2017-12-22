/*
[HAOI2010]最长公共子序列
分析：设F[i][j]表示A中前i，B中前j的最长公共子序列
		设G[i][j]表示A中前i，B中前j的最长公共子序列的数目
		根据F[i][j]的取值讨论下G即可。N^2可过 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5000,MOD=(int)100000000;
int n,m;
char s1[MAXN+3],s2[MAXN+3];
int F[2][MAXN+3],G[2][MAXN+3];
int main(){
    scanf("%s%s",s1+1,s2+1);
    n=strlen(s1+1)-1,m=strlen(s2+1)-1;
    int now=0,last=1;
    for(int j=0;j<=m;j++)G[now][j]=1;
    for(int i=1;i<=n;i++){
        swap(now,last);memset(F[now],0,sizeof(F[now]));memset(G[now],0,sizeof(G[now]));
        G[now][0]=1;
        for(int j=1;j<=m;j++)
            if(s1[i]==s2[j]){
                F[now][j]=F[last][j-1]+1;
                (G[now][j]=G[last][j-1])%=MOD;
                if(F[now][j]==F[last][j])(G[now][j]+=G[last][j])%=MOD;
                if(F[now][j]==F[now][j-1])(G[now][j]+=G[now][j-1])%=MOD;
            }else{
                F[now][j]=max(F[last][j],F[now][j-1]);
                if(F[now][j]==F[last][j])(G[now][j]+=G[last][j])%=MOD;
                if(F[now][j]==F[now][j-1])(G[now][j]+=G[now][j-1])%=MOD;
                if(F[now][j]==F[last][j-1])(G[now][j]-=G[last][j-1])%=MOD;
            }
    }
    printf("%d\n%d\n",F[now][m],(G[now][m]+MOD)%MOD);//前面就不保证G是正的了，就最后处理一下 
    return 0;
}
