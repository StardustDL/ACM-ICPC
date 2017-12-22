/*
False coin
题意：N个硬币中有1个是假币，其重量不同于其它硬币（其它硬币的重量是相同的）。 现在他们只有一个简单的天平可用。这个天平可以确定左盘中的物品是比右盘中的物品重、轻，还是同等重量。 为确定哪一枚硬币是假币，银行把所有的硬币从1到N进行编号。然后他们把相同数目的硬币分别放在天平的左盘和右盘中，来测量不同组的硬币的重量。硬币的编号以及称量的结果会被仔细地记录下来。（结果为>,<,=）
	  写一个程序，基于这些称量的结果记录，找出哪一枚硬币是假币。 
分析：两端重量相等则两端的硬币都是真的，每个不等情况中必然包含那个假的，且每次出现在同一边（总在小的一边或总在大的一边）。也就是说，只要某些硬币在不等 的一边中不是每次都出现，则它一定是真的。用以上方法进行判断哪些是真的，暂时忽略没出现过的，看有多少个不是真的，如果只有一个则必然是结果，若有多个则无法判断。如果出现过的都是真的，看没出现过的有几个，如果只有一个则为结果，否则无法判断。
	  但有一种简单方法实现上述算法：
	  	如果是=，则把每个值都赋为2000（这个数一定要比比较的次数大啊，我刚开始开了100，wa了好几次，唉，你说这能不让人窝火吗）
	    如果是<，把左边的值不为2000的数减一，右边不为2000的数加1
		如果是>,则反过来
		最后查找不为2000的绝对值最大的数，则该数必为假币，至于是否会输出0这个结果，那就要看不为2000的绝对值最大的数知否只有一个，如果只有一个，那就是要求的结果，如果多个，那么就输出0 
	  但WA了好多次：注意只有一组数据，把输出放了循环里了，另外mx初始值不能为0，应小于0，不然答案和计数会有问题 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000,MK=2000;
int flg[MAXN+3],lft[MAXN+3],rght[MAXN+3],p,n,k;
char c;
int main(){
	scanf("%d%d",&n,&k);
	while(k--){
		scanf("%d",&p);
		for(int i=1;i<=p;i++)scanf("%d",&lft[i]);
		for(int i=1;i<=p;i++)scanf("%d",&rght[i]);
		scanf("\n%c",&c);
		if(c=='='){
			for(int i=1;i<=p;i++)flg[lft[i]]=flg[rght[i]]=MK;
		}
		else if(c=='<'){
			for(int i=1;i<=p;i++){
				if(flg[lft[i]]!=MK)flg[lft[i]]--;
				if(flg[rght[i]]!=MK)flg[rght[i]]++;
			}
		}
		else if(c=='>'){
			for(int i=1;i<=p;i++){
				if(flg[lft[i]]!=MK)flg[lft[i]]++;
				if(flg[rght[i]]!=MK)flg[rght[i]]--;
			}
		}
	}
	int mx=-1,ans=-1,cnt=0;
	for(int i=1;i<=n;i++){
		if(flg[i]!=MK){
			if(abs(flg[i])>mx){
				mx=abs(flg[i]);
				ans=i;
				cnt=1;
			}
			else if(abs(flg[i])==mx){
				cnt++;
			}
		}
	}
	if(cnt==1)printf("%d\n",ans);
	else puts("0");
	return 0;
}

