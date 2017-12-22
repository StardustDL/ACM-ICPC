/*
Coins
���⣺����ر�������ɶ�������ֵ
������f[i]��ʾi�ܷ���ɣ�ÿ����f[j]ʱֱ����f[j-weight[i]]�Ƴ���ǰ����num[j-weight[i]]<sum[i]��
	  numÿ��һ�ж�Ҫ���㣬num[j]��ʾ��ǰ��Ʒ���j��С�İ���Ҫ����ʹ�ö��ٸ�
	  ����ʹ�����ַ�����һ������������Ҫ��f����ֻ����bool���͡���������
	  ����bool���򲻻����Լ۱ȵ����⣬ֻ������ɴ�Ͳ��ɴ�����⣬�ڿɴ�ǰ����ֻҪ�����ٵ�ʹ�õ�ǰ��Ʒ���ɣ�
	  value�����У��ɴﲻһ�����õ�ǰ��Ʒ����Ϊ���õ�ǰ��Ʒ���ܻ��ø߼�ֵ��
	  ���磬�����ǰ��Ʒ�Լ۱ȼ��ߣ���ô���������С�İ���Ӧ�þ�����ĵ�ǰ��Ʒ��׷��߼�ֵ��
	  ������������ʹ�ú���������㹻��ʱ������Щλ�ã�j=(sum[i]+1)*weight[i]�����޷���������num[j - weight[i]]<sum[i]����֮ǰ�Ѿ��ѵ�ǰ��Ʒ���꣩�����޷�����ǰ��Ʒ�� 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
const int MAXN=100000;
int cnt[MAXN+3],v[105],c[105];
bool opt[MAXN+3];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m),n+m){
        for(int i=1;i<=n;i++)scanf("%d",&v[i]);
        for(int i=1;i<=n;i++)scanf("%d",&c[i]);
        memset(opt,0,sizeof(opt));
        opt[0]=1;int ans=0;
        for(int i=1;i<=n;i++){
            memset(cnt,0,sizeof(cnt));
            for(int j=v[i];j<=m;j++){
                if(!opt[j]&&opt[j-v[i]]&&cnt[j-v[i]]<c[i]){
                    opt[j]=1;
                    cnt[j]=cnt[j-v[i]]+1;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

