/*
[SHOI2008]小约翰的游戏John 
分析：经典的nim游戏。稍有不同的是这里是最后一个取的输。经典的nim有一个定理，所有石子个数xor起来如果==0，说明brother赢，否则john赢。这里也是这样的（因为只要选的时候少拿一个就能强迫对手拿最后一个），但是当石子全部都是1的时候，情况恰恰相反，特判一下就好了
*/
#include<cstdio>
using namespace std;
const char STR[2][10]={"Brother","John"};
int n,ans,x,k; 
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;k=1;
		while(n--){
			scanf("%d",&x);
			ans^=x;
			if(x!=1)k=0;
		}
		puts(STR[(ans!=0)^k]);
	}
	return 0;
}

