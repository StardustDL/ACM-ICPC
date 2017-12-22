/*
[HAOI2008]Ӳ�ҹ���
������dpԤ����+�ݳ�ԭ��
	  ��F[i]Ϊ������ÿ��Ӳ�ҵ��������Ƶ�����£��õ���ֵi�ķ���������״̬ת�Ʒ���Ϊ
	    F[i]=Sum{F[i-C[k]] | i-C[k]>=0 �� k=1..4}
	    Ϊ���ⷽ���ظ���Ҫ��kΪ�׶ε��ƣ��߽�����ΪF[0]=1������Ԥ�����ʱ�临�ӶȾ���O(S)��
	  ����������ÿ��ѯ�ʣ������ݳ�ԭ����Ϊ �õ���ֵS�Ĳ��������Ƶķ����� �C ��1��Ӳ�ҳ������Ƶķ����� �C ��2��Ӳ�ҳ������Ƶķ����� �C ��3��Ӳ�ҳ������Ƶķ����� �C ��4��Ӳ�ҳ������Ƶķ����� + ��1,2��Ӳ��ͬʱ�������Ƶķ����� + ��1,3��Ӳ��ͬʱ�������Ƶķ����� + ���� + ��1,2,3,4��Ӳ��ȫ��ͬʱ�������Ƶķ�������
	  ����1��Ӳ�ҳ�������ʱ��ֻҪҪ�õ�D[1]+1öӲ�ң�ʣ���Ӳ�ҿ���������䣬���Է�����Ϊ F[ S �C (D[1]+1)C[1] ]��
	  ���ҽ���(S �C(D[1]+1)C[1])>=0�����򷽰���Ϊ0������������ƣ�ÿ��ѯ��ֻ����16�Σ�����ѯ�ʵ�ʱ�临�Ӷ�ΪO(1)��
	  ����ѯ�ʽ϶࣬��Ʒ���٣��ʺ����ַ����� 
	  ���ſ�long long 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
int c[5],d[5],n,s;
LL cnt[MAXN+3],ans;
void solve(int ind,int out,int sum){//out����ʾ�������Ƶ���Ʒ�������Դ��ж��Ǽ��Ǽ� 
	if(sum<0)return;
	if(ind==5){
		if(out&1)ans-=cnt[sum];
		else ans+=cnt[sum];
	}
	else{
		solve(ind+1,out+1,sum-(d[ind]+1)*c[ind]);
		solve(ind+1,out,sum);
	}
}
int main(){
	for(int i=1;i<=4;i++)scanf("%d",&c[i]);
	cnt[0]=1;
	for(int i=1;i<=4;i++)
		for(int j=c[i];j<=MAXN;j++)
			cnt[j]+=cnt[j-c[i]];
	for(scanf("%d",&n);n;n--){
		for(int i=1;i<=4;i++)scanf("%d",&d[i]);
		scanf("%d",&s);
		ans=0;solve(1,0,s);
		printf("%lld\n",ans);
	}
	return 0;
}

