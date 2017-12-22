/*
»¨½³
·ÖÎö£ºÌ°ÐÄ 
*/
#include<cstdio> 
#include<algorithm>
using namespace std;
int l,x,a=1,b=1,n; 
int main(){
	scanf("%d%d",&n,&l);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		if(x>l)a=max(a,b+1);
		if(x<l)b=max(b,a+1);
		l=x;
	}
	printf("%d",max(a,b));
	return 0;
}

