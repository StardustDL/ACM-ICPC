/*
奇妙的Fibonacci
分析：有个定理..以前见过所以知道.. 那个定理是这样的
	  fib[gcd(i,j)]=gcd(fib[i],fib[j])
		由此可得，若i|j，则必有fib[i]|fib[j]。
		注意，他们不互为充要条件，因为当j为奇数时，i=2也可以使得fib[i]|fib[j]，要特判。
		由此，化归到求10^7内数的因数个数和所有因数的平方的总和的问题。
	  用线性筛来搞。
		不知道什么是线性筛的朋友可以搜一搜相关的资料，这里不再废话。
		线性筛最大的特点就是每个数仅被筛一次，且是被其最小质因数筛掉。这保证了线性时间。
		利用这一特性，线性筛可以用于求欧拉函数和因数个数，这一题也只不过是又拓展了一点。
		设e[i]为i的最小质因数的次数，g[i]为i的因数个数，f[i]为i的因数的平方和。
		设当前枚举到i，质数枚举到prime[j](此处建议参照代码)，记A=i*prime[j]。
		分类讨论：
			1. i%prime[j]!=0
			这时prime[j]是A的最小质因数且为1次
			分析A的因数的组成，可以知道他由两部分组成，
			一部分是i的所有因数 另一部分是i的所有因数各乘上prime[j]得到的 
			因此g[A]=g[i]*2  f[A]=f[i]*(prime[j]^2+1)
			2. i%prime[j]==0
			此时prime[j]是A的最小质因数 为e[i]+1次
			这种情形下并不能像另一种情况那样简单的得到解决
			令B=i/(prime[j]^e[i]) 即B是i除去最小质因数后得到的数
			仔细研究之后可以得到
			f[i]=f[B]* ( sigma(k=0..e[i])(prime[j]^(2*k) )
			f[A]=f[B]*( sigma(k=0..e[i]+1)(prime[j]^(2*k) )
			消去f[i]即得f[A]=f[i]*(prime[j]^2)+f[B]
			这里涉及到对于给定的i，B=i/(prime[j]^e[i])的计算，记为d[i]。
			朴素是没有问题的，可A，但其实也可以线性筛的过程中递推算出。
			仍分类讨论，分法和上面一样。易得
			1. d[A]=i
			2. d[A]=d[i]
			至此，我们得到了整个问题的O(n)预处理算法。
	  空间上似乎要爆掉的样子? BZOJ上这题给了512MB，放心的开吧。
	  然后考察一下在线询问的机制，知道询问的上界是C，因此预处理到C就够了。
	  最后啰嗦一句，不要忘记特判奇数的情况。 注意取模和数据范围，一乘就会爆掉int 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=10000000,INF=0x3f3f3f3f;
const LL MOD=1000000007;
LL mindiv[MAXN+3];
LL f[MAXN+3],g[MAXN+3],d[MAXN+3],e[MAXN+3];
vector<LL> pris;
void init(int size){
	f[1]=g[1]=1;
	for(LL i=2;i<=size;i++){
		if(mindiv[i]==0){mindiv[i]=i;pris.push_back(i);f[i]=(i*i+1)%MOD;g[i]=2;e[i]=1;d[i]=1;}
		for(LL j=0,k;j<pris.size()&&(k=i*pris[j])<=size;j++){
			mindiv[k]=pris[j];
			if(pris[j]==mindiv[i]){
				g[k]=g[i]*(e[i]+2)/(e[i]+1);
				e[k]=e[i]+1;
				f[k]=(f[i]*(pris[j]*pris[j]%MOD)%MOD+f[d[i]])%MOD;
				d[k]=d[i];
				break;
			}
			g[k]=g[i]*2;e[k]=1;d[k]=i;
			f[k]=(f[i]*(pris[j]*pris[j]%MOD+1))%MOD;
		}
	}
}
LL Q,q,A,B,C,a,b;
int main(){
	cin>>Q>>q>>A>>B>>C;
	init(max(C,q)+1);
	B%=C;A%=C;a=b=0;
	while(Q--){
		a+=g[q];b+=f[q];
		if(q&1){a+=1;b+=4;}
		a%=MOD;b%=MOD;
		q=(q*A+B)%C+1;
	}
	cout<<a<<endl<<b<<endl;
	return 0;
}

