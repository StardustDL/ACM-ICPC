/*
[HAOI2008] 糖果传递
分析：首先，最终每个小朋友的糖果数量可以计算出来，等于糖果总数除以n，用ave表示。
		假设标号为i的小朋友开始有Ai颗糖果，Xi表示第i个小朋友给了第i-1个小朋友Xi颗糖果，如果Xi<0，说明第i-1个小朋友给了第i个小朋友Xi颗糖果，X1表示第一个小朋友给第n个小朋友的糖果数量。 所以最后的答案就是ans=|X1| + |X2| + |X3| + ……+ |Xn|。
		对于第一个小朋友，他给了第n个小朋友X1颗糖果，还剩A1-X1颗糖果；但因为第2个小朋友给了他X2颗糖果，所以最后还剩A1-X1+X2颗糖果。根据题意，最后的糖果数量等于ave，即得到了一个方程：A1-X1+X2=ave。
		同理，对于第2个小朋友，有A2-X2+X3=ave。最终，我们可以得到n个方程，一共有n个变量，但是因为从前n-1个方程可以推导出最后一个方程，所以实际上只有n-1个方程是有用的。
		尽管无法直接解出答案，但可以用X1表示出其他的Xi，那么本题就变成了单变量的极值问题。
		对于第1个小朋友，A1-X1+X2=ave  ->  X2=ave-A1+X1 = X1-C1(假设C1=A1-ave，下面类似）
		对于第2个小朋友，A2-X2+X3=ave  ->  X3=ave-A2+X2=2ave-A1-A2+X1=X1-C2
		对于第3个小朋友，A3-X3+X4=ave  ->  X4=ave-A3+X3=3ave-A1-A2-A3+X1=X1-C3
		……
		对于第n个小朋友，An-Xn+X1=ave。
		  我们希望Xi的绝对值之和尽量小，即|X1| + |X1-C1| + |X1-C2| + ……+ |X1-Cn-1|要尽量小。注意到|X1-Ci|的几何意义是数轴上的点X1到Ci的距离，
		  所以问题变成了：给定数轴上的n个点，找出一个到他们的距离之和尽量小的点，而这个点就是这些数中的中位数，证明略。
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1000000,INF=0x3f3f3f3f;
int n,a[MAXN+3],c[MAXN+3],ave;
LL sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ave=sum/n;
	for(int i=2;i<=n;i++)c[i]=c[i-1]+a[i]-ave;
	sort(c+1,c+n+1);
	LL ans=0;
	int mid=c[(n>>1)+1];
	for(int i=1;i<=n;i++)ans+=abs(c[i]-mid);
	printf("%lld",ans); 
	return 0;
}
