/*
BUY LOW, BUY LOWER
���⣺����ϸ��½������У�����������е�������
�������ؼ��ڼ����������ؼ����ڲ��ظ���ע���ǲ�ͬ�֣����Ե�ֵ���ʱӦֻ��¼һ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=5000;
int opt[MAXN+3],n,a[MAXN+3],cnt[MAXN+3]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	for(int i=1;i<=n;i++){
		opt[i]=1;cnt[i]=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]<a[j]){
				if(opt[j]+1>opt[i]){
					opt[i]=opt[j]+1;
					cnt[i]=cnt[j];
				}
				else if(opt[j]+1==opt[i])cnt[i]+=cnt[j];
			}
			else if(a[i]==a[j])cnt[j]=0;//��aֵ���ʱ������ǰ���ʵ�����Ѿ���Ч����Ϊ����Ŀ϶����ţ�����cntֵ��0����Ϊ������ͬʱ���������ӡ�  
		}
	}
	int ans=0,cts=0;
	for(int i=1;i<=n;i++)ans=max(ans,opt[i]);
	for(int i=1;i<=n;i++)if(opt[i]==ans)cts+=cnt[i];
	printf("%d %d",ans,cts);
	return 0;
}

