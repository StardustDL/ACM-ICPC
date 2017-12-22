/*
mode
分析：把每个数和后面一个与它不同的数相抵消，由于要求的数出现了超过n div 2次，那么最后剩下的就是答案。
注意：不要引用那么多头文件，会MLE 
*/
#include<cstdio>
using namespace std;
int n,t,ans=0,tme=0;
int main(){
	scanf("%d%d",&n,&t);
	ans=t;tme=1; 
	for(--n;n;n--){
		scanf("%d",&t);
		if(t==ans)tme++;
		else if(tme==0)ans=t,tme=1;
		else tme--;
	}
	printf("%d\n",ans);
	return 0;
}

