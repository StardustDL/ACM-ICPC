/*
[Usaco2008 Open]Crisis on the Farm ����Σ��
������DP����ʵ������ʲô30ֻһ��= =��30ֻһ��ֻ�Ǳ�֤��ţ�϶��ǾȲ���ģ�����ֻҪԤ���������仯(x+i,y+j)�ܾȵ�ţ��cnt[i][j]���� 
	  f[k, i, j]��ʾ����k����x�����ƶ�i��y�����ƶ�j���������ţ������
	  ���еĶ����ϱ�������Ķ�Ӧ��ע��Ҫ��Ԥ���������һ�£���ʵ����Ԥ����仯�� 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int dx[4]={1,0,0,-1},dy[4]={0,1,-1,0},INF=0x3f3f3f3f,R=31,MAXK=30,MAXN=1000;
const char CHAR[4]={'E','N','S','W'};//�����Ÿ���������·����ʱ��һ���н����������֤�ֵ��� 
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
