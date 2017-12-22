/*
�����Fibonacci
�������и�����..��ǰ��������֪��.. �Ǹ�������������
	  fib[gcd(i,j)]=gcd(fib[i],fib[j])
		�ɴ˿ɵã���i|j�������fib[i]|fib[j]��
		ע�⣬���ǲ���Ϊ��Ҫ��������Ϊ��jΪ����ʱ��i=2Ҳ����ʹ��fib[i]|fib[j]��Ҫ���С�
		�ɴˣ����鵽��10^7��������������������������ƽ�����ܺ͵����⡣
	  ������ɸ���㡣
		��֪��ʲô������ɸ�����ѿ�����һ����ص����ϣ����ﲻ�ٷϻ���
		����ɸ�����ص����ÿ��������ɸһ�Σ����Ǳ�����С������ɸ�����Ᵽ֤������ʱ�䡣
		������һ���ԣ�����ɸ����������ŷ��������������������һ��Ҳֻ����������չ��һ�㡣
		��e[i]Ϊi����С�������Ĵ�����g[i]Ϊi������������f[i]Ϊi��������ƽ���͡�
		�赱ǰö�ٵ�i������ö�ٵ�prime[j](�˴�������մ���)����A=i*prime[j]��
		�������ۣ�
			1. i%prime[j]!=0
			��ʱprime[j]��A����С��������Ϊ1��
			����A����������ɣ�����֪��������������ɣ�
			һ������i���������� ��һ������i����������������prime[j]�õ��� 
			���g[A]=g[i]*2  f[A]=f[i]*(prime[j]^2+1)
			2. i%prime[j]==0
			��ʱprime[j]��A����С������ Ϊe[i]+1��
			���������²���������һ����������򵥵ĵõ����
			��B=i/(prime[j]^e[i]) ��B��i��ȥ��С��������õ�����
			��ϸ�о�֮����Եõ�
			f[i]=f[B]* ( sigma(k=0..e[i])(prime[j]^(2*k) )
			f[A]=f[B]*( sigma(k=0..e[i]+1)(prime[j]^(2*k) )
			��ȥf[i]����f[A]=f[i]*(prime[j]^2)+f[B]
			�����漰�����ڸ�����i��B=i/(prime[j]^e[i])�ļ��㣬��Ϊd[i]��
			������û������ģ���A������ʵҲ��������ɸ�Ĺ����е��������
			�Է������ۣ��ַ�������һ�����׵�
			1. d[A]=i
			2. d[A]=d[i]
			���ˣ����ǵõ������������O(n)Ԥ�����㷨��
	  �ռ����ƺ�Ҫ����������? BZOJ���������512MB�����ĵĿ��ɡ�
	  Ȼ�󿼲�һ������ѯ�ʵĻ��ƣ�֪��ѯ�ʵ��Ͻ���C�����Ԥ����C�͹��ˡ�
	  �����һ�䣬��Ҫ������������������� ע��ȡģ�����ݷ�Χ��һ�˾ͻᱬ��int 
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

