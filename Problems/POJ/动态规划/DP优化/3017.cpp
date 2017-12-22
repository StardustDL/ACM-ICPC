/*
Cut the Sequence
题意：给你一个正整数的序列，你要把这个序列分成几个部分，然后使每个部分的和不超过M。在此基础上，要让每一部分的最大的元素的和最小。如果找不到，输出-1。
分析：方程是很裸的，f[i]=min(f[j]+max(j+1,i))。但是这是二维的，所以肯定要超。要超则必优化。
      当我看到转移方程同时与ij有关时，我想过用斜率优化，但无奈此方程无法因式分解成斜率式。同样是因为方程同时与ij有关且无法分离，用普通的单调队列也行不通。于是我上网找题解，原来不仅要用单调队列，还要用平衡树，这种单调队列相当奇葩，所以今天下午，即使头晕，我还是坚持把它做了。
      可以证明决策点是单调增的。因为这是正整数的序列，要满足区间和<=M，决策点肯定单调增。我们开一个单调队列，队列中保存的是区间最大值，队列中满足单调减。
      但是转移方程同时与ij有关，导致队首的元素未必是最优决策点。如果队首是X，队首+1是Y，那么Y必为max(X+1,Y)。于是我们把每个f[X]+a[Y]插入平衡树中。同时，再维护一个low，为不超过M的最小f[j]。然后从f[j]+a[q[l]]与tree.begin()中二选一。 
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
