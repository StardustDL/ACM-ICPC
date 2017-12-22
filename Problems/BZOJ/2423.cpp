/*
[HAOI2010]�����������
��������F[i][j]��ʾA��ǰi��B��ǰj�������������
		��G[i][j]��ʾA��ǰi��B��ǰj������������е���Ŀ
		����F[i][j]��ȡֵ������G���ɡ�N^2�ɹ� 
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
    printf("%d\n%d\n",F[now][m],(G[now][m]+MOD)%MOD);//ǰ��Ͳ���֤G�������ˣ��������һ�� 
    return 0;
}
