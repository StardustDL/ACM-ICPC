/*
Jumping Cows
题意：牛们想跳上月球，但他们没办法跳跃，于是巫师发明了一些饮料，每种饮料有一个strength值，每次给出n种饮料，一种饮料只能使用一次，且必须按照给出顺序使用，假设一只牛使用了m种饮料，则它使用的第奇数种饮料（1，3，5,……）会增加牛的跳跃能力，而第偶数种饮料会降低牛的跳跃能力，求牛能跳跃的最大高度。
分析：决策只有两个：选和不选，维护长度为奇数和偶数的最优解，扫一遍即可，注意n=1的情况 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,t,odd,even,k; 
int main(){
	scanf("%d",&n);
	if(n==1){scanf("%d",&t);printf("%d",t);return 0;}
	scanf("%d%d",&odd,&even);
	t=even;
	even=odd-even;
	odd=max(odd,t);
	for(int i=3;i<=n;i++){
		scanf("%d",&k);
		t=max(odd,even+k);//选k，则从even转移 
		even=max(even,odd-k);//选k，则从odd转移 
		odd=t;
	}
	printf("%d",max(odd,even)); 
	return 0;
}

