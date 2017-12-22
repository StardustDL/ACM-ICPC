/*
Elevator
*/
#include<cstdio>
int main(){
	int t,sum,floor,a;
	while(scanf("%d", &t)&&t){
		floor=0;sum=0;
     	while(t--){
         	scanf("%d",&a);
   			sum+=(a>floor?6*(a-floor):4*(floor-a))+5;
         	floor=a;
     	}
     	printf("%d\n",sum);
 	}
 	return 0;
}

