/*
Relocation
���⣺ �� n ���������֪����ÿ�������������ÿ�����������ֱ�Ϊc1,c2�Ļ�װ�أ���������Ҫ���Ͷ��ٴο��Խ��������ꡣ
����: �����һ���⣬��״̬ѹ���õ����С���Ʒ����Ȼ��ת�ɱ���DP����û���Ż�������أ� 
		�ҳ�����״̬��1.....(1<<n)-1����ѡ��������������һ�������״̬
        ��ÿ��״̬������һ����Ʒ������Ϊ��״̬������������ֵΪ 1
        ��� 01 ������dp[(1<<n)-1]Ϊ���Ž�
        ת�Ʒ��̣� dp[stat|j]=min(dp[stat|j],dp[j]+1)  ע�� stat �� j �����н���
*/
#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=10,INF=0x3f3f3f3f;
int opt[1<<MAXN+1];
vector<int> thing;
bitset<(1<<MAXN+1)> has;
int n,c1,c2,w[MAXN+3],T;
int check(int stat){
    int s=0;has=0;has[0]=1;
    for(int i=0;i<n;i++)
        if((1<<i)&stat){
            s+=w[i];
            if(s>c1+c2)return 0;
            for(int j=c1;j>=w[i];j--)
            	has[j]=has[j]|has[j-w[i]];
        }
    for(int i=0;i<=c1;i++)
        if(s-i<=c2&&has[i])return 1;
    return 0;
}
int main(){
    scanf("%d",&T);
    for(int k=1;k<=T;k++){
        scanf("%d%d%d",&n,&c1,&c2);
        for(int i=0;i<n;i++)scanf("%d",&w[i]);
        thing.clear();
        memset(opt,INF,sizeof(opt));
        opt[0]=0;
        int st=(1<<n)-1;
        for(int i=1;i<=st;i++)
            if(check(i))thing.push_back(i);
        for(int i=0;i<thing.size();i++)
            for(int j=st;j>=0;j--)
                if(opt[j]!=INF&&(!(j&thing[i])))//����״̬�����н���
                    opt[thing[i]|j]=min(opt[thing[i]|j],opt[j]+1);
        printf("Scenario #%d:\n%d\n\n",k,opt[st]);
    }
    return 0;
}
