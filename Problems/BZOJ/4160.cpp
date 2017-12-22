/*
[Neerc2009]Exclusive Access 2
分析：因为点数比较少，考虑状态压缩DP。
	  根据 Dilworth 定理,有向无环图的最长链长度,等于最少反链划分数量（导弹拦截里面的第二问）。
	  所以问题等价于,把点集分成若干集合,使得每个子集内部没有边。
	  预处理出ok[code]表示集合code内部是否有边,然后计算f[code]表示把集合code划分的最少子集数量,
	  转移的时候枚举subcode满足ok[subcode]为真,用f[code-subcode]+1更新答案。总的时间复杂度是 O(2^n*m+3^n)。 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=15,INF=0x3f3f3f3f;
bool ok[(1<<MAXN)+3];
int n,m,idx[26],g[MAXN+3][MAXN+3],f[(1<<MAXN)+3];
int main(){
    scanf("%d",&m);
    memset(idx,-1,sizeof(idx));
    for (int i=1,x,y;i<=m;++i){
        char s1[2],s2[2];
        scanf("%s%s",s1,s2);x=s1[0]-'A';y=s2[0]-'A';
        if (idx[x]==-1) idx[x]=n++;
        if (idx[y]==-1) idx[y]=n++;
        g[idx[x]][idx[y]]=g[idx[y]][idx[x]]=1;
    }
    for (int i=0;i<1<<n;++i){
        ok[i]=1;
        for (int j=0;j<n;++j)
            for (int k=0;k<n;++k)
                if (j!=k&&((i>>j)&1)&&((i>>k)&1)&&g[j][k]){ok[i]=0;break;}
    }
    memset(f,INF,sizeof(f));f[0]=0;
    for (int i=0;i<1<<n;++i)
        for (int t=i;t;t=(t-1)&i)
            if (ok[t]) f[i]=min(f[i],f[i^t]+1);
    printf("%d\n",f[(1<<n)-1]-2);
    return 0;
}
