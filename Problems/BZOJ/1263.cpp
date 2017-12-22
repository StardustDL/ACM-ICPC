/*
[SCOI2006]整数划分
分析：机智的构造答案，高精度，
	  结论：
		如果n是3的倍数 那么将n划分成n/3个3是最优的
		如果n是3的倍数+1 那么将n划分成(n-4)/3个3和两个2是最优的
		如果n是3的倍数+2 那么将n划分成(n-2)/3个3和1个2是最优的
	  证明： 
		考虑不是划分成整数，而是划分成任意实数
		设我们将n划分成了x个正实数之和
		易知当这x个数相等时答案是最优的
		那么每个数都是n/x，答案是(n/x)^x
		设y=(n/x)^x
		则有lny=x[ln(n)-ln(x)]
		两侧求导可得y'=(n/x)^x * ( ln(n) - ln(x) - 1 )
		当x=n/e时y‘取0 此时乘积最大
		因此每个数要尽量靠近e才能使答案最大
		现在考虑整数 离e最近的整数是3 因此要把n尽量分成3 不足的用2补齐 这样可以保证是最优的。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int R=10;
struct bign{
	int d[5000+3],len;
	bign(){len=1;memset(d,0,sizeof(d));}
	void operator *=(int num){
		for(int i=0;i<len;i++)d[i]*=num;
		for(int i=0;i<len;i++){
			if(d[i]>=R){
				d[i+1]+=d[i]/R;d[i]%=R;
				if(i==len-1)len++;
			}
		}
	}
	void output(){
		printf("%d\n",len);
		for(int i=len-1;i>=0&&i>=len-100;i--)printf("%d",d[i]);
	}
}ans;
int n;
int main(){
	scanf("%d",&n);
	ans.d[0]=1;
	switch(n%3){
		case 0:
			for(int i=3;i<=n;i+=3)ans*=3;
			break;
		case 1:
			for(int i=3+4;i<=n;i+=3)ans*=3;
			ans*=4;
			break;
		case 2:
			for(int i=3+2;i<=n;i+=3)ans*=3;
			ans*=2;
			break;
	}
	ans.output();
	return 0;
}

