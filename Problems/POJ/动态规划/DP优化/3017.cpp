/*
Cut the Sequence
���⣺����һ�������������У���Ҫ��������зֳɼ������֣�Ȼ��ʹÿ�����ֵĺͲ�����M���ڴ˻����ϣ�Ҫ��ÿһ���ֵ�����Ԫ�صĺ���С������Ҳ��������-1��
�����������Ǻ���ģ�f[i]=min(f[j]+max(j+1,i))���������Ƕ�ά�ģ����Կ϶�Ҫ����Ҫ������Ż���
      ���ҿ���ת�Ʒ���ͬʱ��ij�й�ʱ���������б���Ż��������δ˷����޷���ʽ�ֽ��б��ʽ��ͬ������Ϊ����ͬʱ��ij�й����޷����룬����ͨ�ĵ�������Ҳ�в�ͨ����������������⣬ԭ������Ҫ�õ������У���Ҫ��ƽ���������ֵ��������൱���⣬���Խ������磬��ʹͷ�Σ��һ��Ǽ�ְ������ˡ�
      ����֤�����ߵ��ǵ������ġ���Ϊ���������������У�Ҫ���������<=M�����ߵ�϶������������ǿ�һ���������У������б�������������ֵ�����������㵥������
      ����ת�Ʒ���ͬʱ��ij�йأ����¶��׵�Ԫ��δ�������ž��ߵ㡣���������X������+1��Y����ôY��Ϊmax(X+1,Y)���������ǰ�ÿ��f[X]+a[Y]����ƽ�����С�ͬʱ����ά��һ��low��Ϊ������M����Сf[j]��Ȼ���f[j]+a[q[l]]��tree.begin()�ж�ѡһ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
/*const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL;
LL opt[MAXN+3],m,n,a[MAXN+3],sum[MAXN+3],rmq[MAXN+3][18];
int getmax(int l,int r){
	int k=0;
	while(l+(1<<(k+1))<=r)k++;
	//cout<<k<<endl;
	//cout<<rmq[l][k]<<" "<<rmq[r-(1<<k)+1][k]<<endl;
	return max(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int j=1;j<=n;j++)rmq[j][0]=a[j];
	for(int i=1;i<18;i++){
		for(int j=1;j<=n+1-(1<<i);j++){
			rmq[j][i]=max(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]); 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			opt[i]=opt[j]
		}
	}
	return 0;
}*/ 
#include<cstdio>
#include<cstdlib>
#include<set>
using namespace std;
const int MAXN=100000;
long long opt[MAXN+10],m,sum;
int a[MAXN+10],q[MAXN+10],n;
multiset<int>k;
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int l=0,r=-1,low=1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        while(sum>m)sum-=a[low++];
        if(low>i){printf("%d",-1);return 0;}        
        while(l<=r&&a[i]>a[q[r]]){
            if(r>l)k.erase(opt[q[r-1]]+a[q[r]]);
            r--;
		}
        q[++r]=i;
        if(r>l)k.insert(opt[q[r-1]]+a[q[r]]);
        while(q[l]<low){
            if(l<r)k.erase(opt[q[l]]+a[q[l+1]]);
            l++;
		}
        long long temp=*(k.begin());
        opt[i]=opt[low-1]+a[q[l]];
        if(l<r&&temp<opt[i])opt[i]=temp;
    }
    printf("%lld",opt[n]);
	return 0;
}
