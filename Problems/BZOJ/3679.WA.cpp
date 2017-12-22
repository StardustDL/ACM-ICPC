/*
����֮��
������
	���ȶ���ÿλ���ĳ˻�����һ������Ȼ��ת�Ʒ��� 
	d[i][j]��ʾiλ���˻�Ϊj�ķ����������� 
	
	d[i][j]=(1��k��9,k|j){d[i-1][k/j]}
	
	Ȼ�����Ƿ���j���ܴܺ󣬵�����ʵ�鷢��ֻ��5000������������ǿ��԰ɵڶ�ά�±껻���������е��������������ƾͿ����ˣ� 
	��������[1,x)ͳ�ƴ𰸣�����λDP���õ�˼·����ͳ�Ƴ�λ����xС�Ĵ������ٽ�x��λ��֣�ÿ��ͳ�Ƶ�ǰλ�ϸ�С�ڵ�ǰλ��xԭ���ֵĴ𰸣���������ٽ�n��ȥ��ǰλ��ԭ���֣�ע�����x������0,��break������Ϊ��ĿҪ�����1�����Ϲ���Ҫ�����ǰ�d����ÿһ����ǰ׺�ͣ�ע������n����������ֵ����⣩�� 
	ͳ��[L,R)�ݳ�һ�¾ͺ��� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=6000;
LL list[MAXN+3],tot;
LL cnt[19][MAXN+3],sum[19][MAXN+3];
LL l,r,n;
LL qpow(LL a,int n){
	LL ans=1;
	while(n){
		if(n&1)ans=ans*a;
		a=a*a;
		n>>=1;
	}
	return ans;
}
void pre(LL mx){
	LL x=0;
	for(int i=0;i<=3*12;++i)
    	for(int j=0;j<=2*12;++j)
    		for(int k=0;k<=12;++k)
				for(int p=0;p<=12;++p){
              		x=qpow(2,i)*qpow(3,j)*qpow(5,k)*qpow(7,p);
					if(x<=mx&&x>0)list[++tot]=x;
            	}
    sort(list+1,list+tot+1);
}
LL solve(LL x,int n) {
	int bit=0,cur,R=upper_bound(list+1,list+tot+1,n)-list-1;
	LL tx=x,ans=0;
	while(tx){bit++;tx/=10;}
	for(int i=1;i<=bit-1;i++)
		ans=ans+sum[i][R];
	for(;bit;--bit){
		LL t=qpow(10,bit-1);
		cur=x/t;x%=t;
		for(int i=1;i<cur;i++)
			if(n>=i){
				if(bit>1)ans+=sum[bit-1][upper_bound(list+1,list+tot+1,n/i)-list-1];
				else ans++;
			}
		if(cur)n/=cur;
		else break;
	}
	return ans;
}
inline void calsum(int r){
	sum[r][0]=0;
	for(int j=1;j<=tot;++j)sum[r][j]=sum[r][j-1]+cnt[r][j];
}
int main() {
	scanf("%lld%lld%lld",&n,&l,&r);
	pre(n);
	for(int i=1;i<=9;i++)cnt[1][i]=1;calsum(1);
	for(int i=2;i<=18;i++){
		int up=upper_bound(list+1,list+tot+1,qpow(10,i))-list-1;
		for(int j=1;j<=up;j++){
			for(int k=1;k<=9;k++){
				if(list[j]%k==0)
					cnt[i][j]+=cnt[i-1][lower_bound(list+1,list+tot+1,list[j]/k)-list];
			}
		}
		calsum(i);
	}
	printf("%lld\n",solve(r,n)-solve(l,n));
	return 0;
}
