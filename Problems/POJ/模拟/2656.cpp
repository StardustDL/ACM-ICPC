/*
Unhappy Jinjin
题意：NOIP，不开心的津津 
*/
#include<cstdio>
using namespace std;
int n,a,b,maxday,maxvalue;
int main(){
	while(scanf("%d",&n),n){
		maxvalue=-1;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a,&b);
			if(a+b>maxvalue){
				maxvalue=a+b;
				maxday=i;
			}
		}
		if(maxvalue<=8)printf("0\n");
		else printf("%d\n",maxday);
	}
	return 0;
}

