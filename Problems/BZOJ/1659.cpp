/*
[Usaco2006 Mar]Lights Out 关灯
分析：迭代加深 ，还有一种DP 
*/
#include<cstdio>
const int N=51;
const int INF=1<<30;
int n,m,lo,la=INF;
int a[N],b[N],opt[N],ans[N],k; 
void update(){//更新字典序 
    if(lo>la)return;
    if(lo==la){
        for(int i=1;i<=n;i++){
            if(opt[i]>ans[i])break;
            if(opt[i]<ans[i])return;
        }
    }
    la=lo;
    for(int i=1;i<=la;i++)ans[i]=opt[i];
}
bool DFS(int cnt,int pos){//当前位置为pos，已经有了cnt个1 
    if(cnt>k) return 0;
    if(pos+m-1>n){
        for(int i=pos;i<=n;i++) cnt+=a[i];
        if(cnt>k) return 0;
        update();
        return 1;
    }
    bool flag=0;
    flag|=DFS(cnt+a[pos],pos+1);
    opt[++lo]=pos;
    for(int i=1;i<=m;i++)a[pos+i-1]^=b[i];
    flag|=DFS(cnt+a[pos],pos+1);
    lo--;
    for(int i=1;i<=m;i++)a[pos+i-1]^=b[i];
    return flag;
}
char t;
int main(){
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++)scanf("%c",&t),a[i]=t-'0';scanf("\n");
    for(int i=1;i<=m;i++)scanf("%c",&t),b[i]=t-'0';
    for(k=0;k<=n;k++)if(DFS(0,1))break;
    printf("%d\n",la);
    for(int i=1;i<=la;i++) printf("%d\n",ans[i]);
    return 0;
}
/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <map>
using namespace std;
int f[55][130],g[55][130],last[55][130],L,T;
char s[20],light[55];
int getone(int a)
{
    int ans=0;
    while(a)    ans+=(a&1),a>>=1;
    return ans;
}
void out(int pos,int state)
{
    if(pos>T)
        out(pos-1,last[pos][state]);
    if(g[pos][state]>g[pos-1][last[pos][state]]||
        (pos==T&&g[pos][state]==1))
        printf("%d\n",pos-T+1);
}
int main()
{
    scanf("%d%d",&L,&T);
    scanf("%s%s",light+1,s+1);
    if(T>L){cout<<"0"<<endl;return 0;}
    int sw=0,state=0;
    for(int i=1;i<=T;i++)    sw=(sw<<1)+s[i]-'0',state=(state<<1)+light[i]-'0';
    memset(f,31,sizeof(f));
    memset(g,31,sizeof(g));
    f[T][state]=getone(state);
    g[T][state]=0;
    f[T][state^sw]=getone(state^sw);
    g[T][state^sw]=1;
    for(int i=T;i<L;i++)
        for(int j=0;j<(1<<T);j++)
            if(f[i][j]<=L)
            {
                //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
                int nxt=((j<<1)+light[i+1]-'0')&((1<<T)-1);
                if(f[i+1][nxt]>f[i][j]+light[i+1]-'0')
                {
                    f[i+1][nxt]=f[i][j]+light[i+1]-'0';
                    g[i+1][nxt]=g[i][j];
                    last[i+1][nxt]=j;
                }
                else    if(f[i+1][nxt]==f[i][j]+light[i+1]-'0')
                    if(g[i+1][nxt]>g[i][j])  
                        g[i+1][nxt]=g[i][j],last[i+1][nxt]=j;
                nxt^=sw;
                if(f[i+1][nxt]>f[i][j]-getone(j)+getone(nxt)+(j>>(T-1)))
                {
                    f[i+1][nxt]=f[i][j]-getone(j)+getone(nxt)+(j>>(T-1));
                    g[i+1][nxt]=g[i][j]+1;
                    last[i+1][nxt]=j;
                }
                else    if(f[i+1][nxt]==f[i][j]-getone(j)+getone(nxt)+(j>>(T-1)))
                    if(g[i+1][nxt]>g[i][j]+1)    
                        g[i+1][nxt]=g[i][j]+1,last[i+1][nxt]=j;
            }
    int p=199405020,ans=f[L][0];
    state=0;
    for(int i=0;i<(1<<T);i++)
        if(f[L][i]<ans)
        {
            ans=f[L][i];
            p=g[L][i];
            state=i;
        }
        else    if(f[L][i]==ans&&p>g[L][i])
            p=g[L][i],state=i;
    printf("%d\n",p);
    out(L,state);
    return 0;
}
*/ 
