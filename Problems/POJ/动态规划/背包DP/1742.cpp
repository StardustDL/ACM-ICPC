/*
Coins
题意：求多重背包能组成多少种面值
分析：f[i]表示i能否组成，每次填f[j]时直接由f[j-weight[i]]推出，前提是num[j-weight[i]]<sum[i]，
	  num每填一行都要清零，num[j]表示当前物品填充j大小的包需要至少使用多少个
	  但是使用这种方法有一个条件，就是要求f数组只能是bool类型。否则会出错。
	  对于bool型则不会有性价比的问题，只有体积可达和不可达的问题，在可达前提下只要尽量少的使用当前物品即可，
	  value型则不行，可达不一定少用当前物品，因为多用当前物品可能会获得高价值。
	  例如，如果当前物品性价比极高，那么对于任意大小的包都应该尽量多的当前物品以追求高价值，
	  用上述方法会使得后面包容量足够大时，会有些位置（j=(sum[i]+1)*weight[i]）因无法满足条件num[j - weight[i]]<sum[i]（即之前已经把当前物品买完），而无法购买当前物品。 
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

