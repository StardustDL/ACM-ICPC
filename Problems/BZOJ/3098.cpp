/*
Hash Killer II
分析：其实本质就是让mod的数超过MOD，这样就容易重复。 
	  如果一个房间里有23个或23个以上的人，那么至少有两个人的生日相同的概率要大于50%。如果你在n个数中随机选数，那么最多选√n次就能选到相同的数（不考虑Rp broken)
	  同样的，这题的Hash值在0到1000000007.
	  那就要选差不多10^5次，唯一注意的是l要取大，使得方案数超过Mod
	  否则就不可能有2个数有相同的Hash值
*/
#include<cstdio>
#include<cstdlib> 
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int main(){
	srand(0);
	printf("%d %d\n",MAXN,20);
	for(int i=1;i<=MAXN;i++)putchar(rand()%26+'a');
	puts("");
	return 0;
}

