/*
[Neerc2009]Exclusive Access 2
��������Ϊ�����Ƚ��٣�����״̬ѹ��DP��
	  ���� Dilworth ����,�����޻�ͼ���������,�������ٷ�������������������������ĵڶ��ʣ���
	  ��������ȼ���,�ѵ㼯�ֳ����ɼ���,ʹ��ÿ���Ӽ��ڲ�û�бߡ�
	  Ԥ�����ok[code]��ʾ����code�ڲ��Ƿ��б�,Ȼ�����f[code]��ʾ�Ѽ���code���ֵ������Ӽ�����,
	  ת�Ƶ�ʱ��ö��subcode����ok[subcode]Ϊ��,��f[code-subcode]+1���´𰸡��ܵ�ʱ�临�Ӷ��� O(2^n*m+3^n)�� 
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
