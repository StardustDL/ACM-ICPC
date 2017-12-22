/*
[Ahoi2005]COMMON 约数研究
分析：逆向思维，考虑每个数对总体的贡献在1-n所有数中，i一共可以成为n/i个数的约数，也即所有的约数中有n/i个i，所以扫一遍累加答案就好了。 
*/
#include<cstdio>
int main(){
	int n,ans=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)ans+=n/i;
	printf("%d",ans);
	return 0;
}

