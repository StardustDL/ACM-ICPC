/*
[POI2008]激光发射器SZK
分析：因为根据光路的可逆性，从A射到B，必然有从B射到A，所以不可能有两个点同时射到同一个点，因为这样从这个点射出去就有两条路线了。所以答案必定是n/2.
	  不要被题目搞乱了 
*/
#include<cstdio>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	printf("%d\n",n>>1); 
	return 0;
}

