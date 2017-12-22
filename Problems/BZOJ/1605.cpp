/*
[Usaco2008 Open]Crisis on the Farm 牧场危机
分析：DP，其实并不是什么30只一堆= =，30只一堆只是保证了牛肯定是救不完的，所以只要预处理出坐标变化(x+i,y+j)能救得牛数cnt[i][j]即可 
	  f[k, i, j]表示走了k步，x方向移动i，y方向移动j的最大被拯救牛的数量
	  题中的东西南北和坐标的对应，注意要和预处理的正负一致，其实就是预处理变化量 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int dx[4]={1,0,0,-1},dy[4]={0,1,-1,0},INF=0x3f3f3f3f,R=31,MAXK=30,MAXN=1000;
const char CHAR[4]={'E','N','S','W'};//这里排个序，下面求路径的时候一旦有解就跳出，保证字典序 
int n,m,K,ans;
int Cx[MAXN+3],Cy[MAXN+3],Hx[MAXN+3],Hy[MAXN+3];
int f[MAXK+3][R*2+3][R*2+3],cnt[R*2+3][R*2+3];
char step[MAXK+3][R*2+3][R*2+3];
int main(){
    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&Cx[i],&Cy[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&Hx[i],&Hy[i]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int Dx=Hx[j]-Cx[i],Dy=Hy[j]-Cy[i];
        if(abs(Dx)<=30 && abs(Dy)<=30)
            ++cnt[R+Dx][R+Dy];
    }
    for(int k=0;k<=K;++k)
        for(int i=0;i<=R*2;++i)
            for(int j=0;j<=R*2;++j){
                f[k][i][j]=-INF;
                step[k][i][j]='Z';
            }
    f[0][R][R]=0;
    for(int k=1;k<=K;k++)for(int i=1;i<=R*2-1;i++)for(int j=1;j<=R*2-1;j++)
        f[k][i][j]=cnt[i][j]+max(max(f[k-1][i-1][j],f[k-1][i+1][j]),max(f[k-1][i][j-1],f[k-1][i][j+1]));
    ans=0;    
    for(int i=1;i<=R*2-1;i++)for(int j=1;j<=R*2-1;j++)
        ans=max(ans,f[K][i][j]); 
    for(int i=1;i<=R*2-1;i++)for(int j=1;j<=R*2-1;j++)
        if(f[K][i][j]==ans)step[K][i][j]='A';
    for(int k=K-1;k>=0;--k)
        for(int i=1;i<=R*2-1;i++)for(int j=1;j<=R*2-1;j++)for(int l=0;l<4;l++)
            if(f[k][i][j]+cnt[i+dx[l]][j+dy[l]]==f[k+1][i+dx[l]][j+dy[l]]&&step[k+1][i+dx[l]][j+dy[l]]<'Z'){
                step[k][i][j]=CHAR[l];break;}
    printf("%d\n",ans);
    int i=R,j=R;
    for(int k=0;k<K;++k){
        printf("%c",step[k][i][j]);
        if(step[k][i][j]=='E')++i;else
        if(step[k][i][j]=='W')--i;else
        if(step[k][i][j]=='S')--j;else
        if(step[k][i][j]=='N')++j;
    }
    puts("");
    return 0;
}
