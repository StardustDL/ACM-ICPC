/*
Hankson的趣味题
分析：1、预处理trunc(sqrt(2000000000))≈50000以内的质数，这里必须用筛法，否则时间就难说了；
　	　2、初始答案sum=1，然后循环质数，看a0、a1、b0、b1里面有多少个该质数因子，记为aa0、aa1、bb0、bb1，同时将a0、a1、b0、b1这四个数分别消去所有该质数因子；
　	　3、根据aa0、aa1、bb0、bb1确定我们所求的数所含该质数因子的个数上界high和下界low；
　	　4、满足要求的数的个数sum:=sum*(high-low+1)； 
		但是悲剧的WA了一个数据，不知道为什么。。。
		这里利用gcd与lcm的性质：gcd为每个数分解质因数后指数取最小值，lcm为取最大值 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
bitset<50003> vis=0;
vector<int> pris;
int a0,a1,b0,b1,a2,a3,b2,b3,ans=1;
int main(){
	for(int i=2;i<=50000;i++)if(!vis[i]){pris.push_back(i);for(int j=i*i;j>0&&j<=50000;j+=i)vis[j]=1;}
	int n;scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		ans=1;
		for(int i=0;i<pris.size();i++){
			a2=a3=b2=b3=0;
			while(a0>1&&a0%pris[i]==0)a2++,a0/=pris[i];
			while(a1>1&&a1%pris[i]==0)a3++,a1/=pris[i];
			while(b0>1&&b0%pris[i]==0)b2++,b0/=pris[i];
			while(b1>1&&b1%pris[i]==0)b3++,b1/=pris[i];
			//if(a2<a3){ans=0;break;}
			//if(b2>b3){ans=0;break;}
			if(b3<a3){ans=0;break;}
			if(b2>=b3&&a2<=a3){
				ans*=(b3-a3+1);
			}
			else if(b2<b3&&a2>a3&&a3!=b3){ans=0;break;}
		}
		printf("%d\n",ans);
	}
	return 0;
}

