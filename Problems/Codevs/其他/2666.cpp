/*
Accept Ratio
分析：分情况讨论来分治
	  如果 f(n, a, b) 表示该题的解，那么一定有 f(n, a, b) = f(n, a, (a + b) / 2) + f(n, (a + b) / 2 + 1, b)；
	  容易知道：当 [n / a] = [n / b] 时，f(n, a, b) = (b - a + 1) * [n / a]，这比求和快一点。
	  可知在b大于n时，许多加数都为1。但在n大于b时，对于任意 i 属于 [a, b]，[n / i] > 1。
	  因此，最差情况时，该算法时间复杂度不如朴素算法。如果一次除法并且向上取整的时间复杂度为O(1)，那么该算法的时间复杂度为O(b-a)。 
*/
#include<iostream>
using namespace std;
typedef long long LL;
LL up(LL a,LL b){
	if(a%b==0)return a/b;
	else return a/b+1;
}
LL solve(LL n,LL a,LL b){
	if(a>b)return 0;
	if(up(n,a)==up(n,b))return (b-a+1)*up(n,a);
	if(n<b)return solve(n,a,n-1)+(b-n+1);
	return solve(n,a,(a+b)>>1)+solve(n,((a+b)>>1)+1,b);
}
int main(){
	LL n,a,b;
	cin>>n>>a>>b;
	cout<<solve(n,a,b);
	return 0;
}
