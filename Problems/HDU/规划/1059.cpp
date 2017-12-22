/*
Dividing
题意：把价值为1，2，3，4，5，6的宝石平均分成两份，不能切割，有没有办法分开。
分析：多重背包，但实际上可以通过剪枝优化的类似01背包的思路AC 
*/
#include<cstdio>
#include<cstring>
using namespace std;
int opt[60011],num[7],sum,total;
int main(){
	int kase=0;
	while(scanf("%d",&num[1])!=-1){
		sum=num[1];
		for(int i=2;i<=6;i++){scanf("%d",&num[i]);sum+=num[i]*i;}
		if(sum==0)break;
		kase++;
		if(sum&1){printf("Collection #%d:\nCan't be divided.\n\n",kase);continue;}
		total=sum/2;
		memset(opt,0,sizeof(opt));
		for(int k=0;k<=num[1]&&k<=total;k++)opt[k]=1;
		for(int i=2;i<=6;i++){
			for(int l=total;l>=0;l--){
				if(!opt[l])continue;
				for(int k=1;k<=num[i]&&k*i+l<=total;k++){
					if(opt[k*i+l])break;//大于这个的答案一定已经处理过了 
					opt[k*i+l]=1;
				}
			}
		}
		if(opt[total])printf("Collection #%d:\nCan be divided.\n\n",kase);
		else printf("Collection #%d:\nCan't be divided.\n\n",kase);
	}
	return 0;
}
