/*
Joseph
题意：有k个坏人k个好人坐成一圈，前k个为好人（编号1~k），后k个为坏人(编号k+1~2k)
	  现在有一个报数m，从编号为1的人开始报数，报到m的人就要自动死去。
	  问当m为什么值时，可以使得在出现好人死亡之前，k个坏人先全部死掉？
	  PS:每一轮都以报数为“1”的人开始重新编号
分析：由于k值比较少（1~13），暴力枚举m就可以了
	  递推公式为：ans[i];  //第i轮杀掉 对应当前轮的编号为ans[i]的人ans[0]=0;
	  	ans[i]=(ans[i-1]+m-1)%(n-i+1);   (i>1  ,  总人数n=2k 则n-i为第i轮剩余的人数) 
		优化：m的特点：
			m的值只可能有两种m=c(k+1)或m=c(k+1)+1，其中c∈N*。	（m范围定论）
			这是为什么呢？
			我们先假定k,m的组合是合适的。那么第k次杀人时，被杀的是不是编号为k的人就是编号为0的人（按照S[k-1]序列编号），为什么呢？因为好人没一个被杀，所以他们组成了长度为k的连续的整体，使得这个坏人只可能在首尾，若坏人出现在中间，说明上次被杀的一定是好人，因为如果上次杀的也是坏人，你就会发现好人中间分散着夹了两个坏人，这显然是不可能的，因为坏人也是个连续的整体，综上，坏人的编号只可能为0或者k。
			那么由被杀者公式得：h[k-1]=(M-1)%(N-k+1)=(M-1)%(k+1)。
			坏人编号为0的情况，h[k-1]=(M-1)%(k+1)=0，所以M=c(k+1)+1；
			坏人编号为k的情况，h[k-1]=(M-1)%(k+1)=k，所以M=c(k+1)+k+1=c(k+1);
			因为M>=k+1，所以c∈N*
			得证。
			这个定论可以让m从一个一个遍历的噩梦中解脱出来，我们只需尝试这些m值：k+1,k+1+1,(k+1)*2,(k+1)*2+1…c*(k+1),c*(k+1)+1……k越大，k+1就越大，m的跳跃性就越强，这样在相当程度上减轻了程序的遍历任务 
*/
#include<iostream>
using namespace std;
int Joseph[14]={0},k;  //打表，保存各个k值对应的m值
int main(){
	while(cin>>k,k){
		if(Joseph[k]){cout<<Joseph[k]<<endl;continue;}
		int ans[30]={0},n=k<<1,m=1;  //第i轮杀掉 对应当前轮的编号为ans[i]的人，n:总人数，m: 所求的最少的报数
		for(int i=1;i<=k;i++){//轮数
			ans[i]=(ans[i-1]+m-1)%(n-i+1);   //n-i为剩余的人数
			if(ans[i]<k){//把好人杀掉了,m值不是所求
				i=0;m++;//枚举m值
			}
		}
		cout<<(Joseph[k]=m)<<endl;
	}
	return 0;
}
/*
#include<cstdio>
using namespace std;
int a[16];
int f(int k,int m){
    int n,i,s;
    n=2*k;s=0;
    for(i=0;i<k;i++){
        s=(s+m-1)%(n-i);
        if(s<k)return 0;
    }
    return 1;
}
int main(){
	int i,k,n;
    for(k=1;k<=14;k++){
        i=k+1;
		while(1){
            if(f(k,i)){
                a[k]=i;
                break;
            }
            else if(f(k,i+1)){
                a[k]=i+1;
                break;
            }
            i+=k+1;
        }
    }
    while(scanf("%d",&n)&&n)
        printf("%d\n",a[n]);
    return 0;
}
*/ 

