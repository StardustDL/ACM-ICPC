/*
题意：给出m1，m2以及若干个个si，求si^a mod m1^m2=0中a的最小值。若无解，输出-1。
分析：由于数据太大，根本不能直接计算，但是我们可以通过因式分解来找到突破点。
	  当m1分解出一个因数而s[i]没有时，这种情况肯定无解，当m1和s[i]对此因数各有一定数量时，
	  我们可以根据这个算出让此因数得到整除的a最小值
	  （可能不是所有因数中最优答案，取所有因数答案最大的，这样才能保证s^a是m1^m2的倍数）设x为m1此因数的个数，y为s[i]此因数的个数，则a=x div y; If  x*a<y then inc(a)。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
#include<bitset> 
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct data{
	int c,v;
	data(int a,int b):v(a),c(b){}
};
vector<data> ds;
int m1,m2,n,ans=INF;
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=2,cnt;m1>1;i++){
		if(m1%i==0){
			for(cnt=0;m1%i==0;m1/=i)cnt+=m2;
			ds.push_back(data(i,cnt));
		}
	}
	for(int s,t,i,k;n;n--){
		scanf("%d",&s);
		for(i=0,t=0;i<ds.size();i++){
			if(s%ds[i].v!=0)break;
			k=0;while(s%ds[i].v==0)k++,s/=ds[i].v;
			int a=ds[i].c/k;if(a*k<ds[i].c)a++;
			t=max(t,a);
		}
		if(i<ds.size())continue;
		ans=min(ans,t);
	}
	printf("%d",ans==INF?-1:ans);
	return 0;
}

