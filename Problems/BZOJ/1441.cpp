/*
Min 
·ÖÎö£ºÅáÊñ¶¨Àí 
*/
#include<cstdio>
using namespace std;
int n,ans,x; 
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main(){
	scanf("%d%d",&n,&ans);
	for(n--;n;n--){scanf("%d",&x);ans=gcd(ans,x);}
	printf("%d",ans>0?ans:-ans); 
	return 0;
}

