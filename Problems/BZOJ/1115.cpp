/*
[POI2009]石子游戏Kam
分析：阶梯博弈：
		首先是对阶梯博弈的阐述，博弈在一列阶梯上进行，每个阶梯上放着自然数个点，两个人进行阶梯博弈，每一步则是将一个集体上的若干个点( >=1 )移到前面去，最后没有点可以移动的人输，
		如这就是一个阶梯博弈的初始状态 2 1 3 2 4  只能把后面的点往前面放，如何来分析这个问题呢，其实阶梯博弈经过转换可以变为Nim..把所有奇数阶梯看成N堆石子，做nim，把石子从奇数堆移动到偶数堆可以理解为拿走石子..就相当于几个奇数堆的石子在做Nim，( 如所给样例..2^3^4=5 不为零所以先手必胜)为什么可以这样来转化？
   		假设我们是先手，所给的阶梯石子状态的奇数堆做Nim先手能必胜，我就按照能赢的步骤将奇数堆的石子移动到偶数堆，如果对手也是移动奇数堆..我们继续移动奇数堆，如果对手将偶数堆的石子移动到了奇数堆，那么我们紧接着将对手所移动的这么多石子从那个奇数堆移动到下面的偶数堆，两次操作后，相当于偶数堆的石子向下移动了几个，而奇数堆依然是原来的样子，即为必胜的状态，就算后手一直在移动偶数堆的石子到奇数堆，我们就一直跟着他将石子继续往下移..保持奇数堆不变，如此做下去，我可以跟着后手把偶数堆的石子移动到0，然后你就不能移动这些石子了，所以整个过程，将偶数堆移动到奇数堆不会影响奇数堆做Nim博弈的过程，整个过程可以抽象为奇数堆的Nim博弈。
   		其他的情况，先手必输的，类似推理，只要判断奇数堆做Nim博弈的情况即可。
   		为什么是只对奇数堆做Nim就可以，而不是偶数堆呢？因为如果是对偶数堆做Nim，对手移动奇数堆的石子到偶数堆，我们跟着移动这些石子到下一个奇数堆...那么最后是对手把这些石子移动到了0..我们不能继续跟着移动...就只能去破坏原有的Nim而导致胜负关系的不确定...所以只要对奇数堆做Nim判断即可知道胜负情况， 
	  分析这道题：
	  	开始时，除第一堆外，每堆能取的石子都有限制，相当于第i堆只能取s[i]-s[i-1]个石子 
 		在第i堆取走x个石子后，第i堆能取的石子少了x个，第i+1堆能取的石子多了x个 
 		这相当于把x个石子第i堆移到了第i+1堆 ，方向和阶梯nim相反
		 所以反着做差分的“奇数”NIM即可 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,a[MAXN+3],T,ans; 
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=n;i>0;i--)a[i]-=a[i-1];//和前面的差分反着做，因为要保留第一个值 
		ans=0;
		for(int i=n;i>0;i-=2)ans^=a[i];
		if(ans)puts("TAK");
		else puts("NIE");
	}
	return 0;
}

