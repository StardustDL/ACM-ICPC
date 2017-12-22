/*
[Sdoi2013]随机数生成器
分析：http://timeplayer.blog.163.com/blog/static/2037182542015056019970/
*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
int n,m,P,C;
typedef long long LL;
int qpow(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=(LL)ans*a%P;
		a=(LL)a*a%P;
		n>>=1;
	}
	return ans;
}
map<int,int> mp;
int mlog(int a,int C){
	int sqn=sqrt(P)+1,i,j,tmp,inva,at;
	mp.clear();
	tmp = 1;
	inva = qpow(a,P-2);
	for(i=0;i<sqn;i++,tmp=(LL)tmp*inva%P)
		if(!mp.count((j=(LL)C*tmp%P)))
			mp[j] = i;
	at=qpow(a,sqn);tmp=1;j=0;
	for(i=0;i<=sqn;i++,tmp=(LL)tmp*at%P)
		if(mp.count(tmp))
			return mp[tmp]+i*sqn;
	return -1;
}
int main(){
	int i,j,a,b,X1,Xn,ans,A,B,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&P,&a,&b,&X1,&Xn);
		if(Xn == X1){printf("1\n");continue;}
		if(a==0){
			if(Xn == b)printf("2\n");
			else printf("-1\n");
			continue;
		}
		if(a==1){
			ans = (LL)((Xn-X1)%P+b)*qpow(b,P-2)%P;
			if(ans < 0)ans += P;
			if(ans>0)printf("%d\n",ans);
			else if(b==0)printf("%d\n",-1);
			else printf("%d\n",P);
			continue;
		}
		//a^n = a * (Xn(1-a)-b) * (X1*(1-a)-b)^(-1)
		//a^n = a * B * A^(-1)
		//A' = A^(-1)
		//B' = a*B
		//a^n = A'*B'
		A = qpow(((LL)X1*(1-a)-b)%P,P-2);
		B = ((LL)Xn*(1-a)-b)%P;
		ans = mlog(a,(LL)A*B%P);
		if(ans >= 0)ans++;
		printf("%d\n",ans);
	}
	return 0;
}	

