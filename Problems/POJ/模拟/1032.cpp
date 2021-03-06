/*
Parliament
题意：理解了题意后，其实就是把n分成若干个不同的数的和，求最大乘积
分析：我们首先先撇开“每组的人数不同”这一约束条件，我们发现如10可以拆成5+5，它的乘积最大，而5又可拆成2+3;2*3>5;故我们发现每次的每一个数都拆成两个相等或相差1的两个数乘积最大。而最大的当然是一直拆到出现2；
	  我们在回来考虑“每组的人数不同”这一约束条件；每组的人数不能相等，但我们又要使数拆成最小的部分（最好拆到出现2），比如说2.3.4~~，那我们大可从2加起，2+3+4+~~~一直加到接近所要求的数；如26我们可以用个循环得到2+3+4+5+6，然后让它停下，此时还剩余6（26-2-3-4-5-6）没用完；那我们就从加数序列的最大那个数开始倒序一次加一，这样过后加数序列就变成了3+4+5+6+7了，但还有1没用啊，当然加给最大的那个7（这个过程用一个取模运算就行了）；所以最后答案是3+4+5+6+8. 
*/
#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int *ss=new int[100],sum=0,j=2;
		while(sum<=n){
			sum+=j;
			ss[j]=j;
			j++;
		}
		sum=sum-(j-1);
		j=j-2;
		int a=n-sum,b=j-2+1,c=a/b,d=a%b;
		while(c--){
			int i=b,k=j;
			while(i--)ss[k--]++;
		}
 		int k=j;
 		while(d--)ss[k--]++;
		for(int i=2;i<=j;i++)
			cout<<ss[i]<<" ";
		cout<<endl;
	}
	return 0;
}
