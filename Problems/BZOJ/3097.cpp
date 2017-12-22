/*
分析：首先明白两点： 1.卡hash的关键在于构造两个不同的串对应的hash值相同。 2.爆u64相当于对2^64这个数取模。 
	  如果base是偶数，那么a.........aaa(>64个a)与ba.......aa(a的数量为前面那么串a的数量-1)，这两个串长度相同，hash值相同，显然串是不同的，这样就卡掉了。 
	  如果base是奇数，就比较麻烦了。 
	  看vfk的做法吧： 
	  如果base是奇数的话，现在只考虑a、b两个字母。 
		a \ b表示a能整除b。（orz 具体数学） 
		设数学上的函数not(S)表示把字符串S中每个位置的'a'变成'b'，把'b'变成'a'后形成的字符串。比如not("ababaa") = "bababb" 
 		strA . strB代表字符串串联。如"娃" . "哈哈" = "娃哈哈" 
 		|str|表示字符串str的长度。 
 		设字符串序列{orzstr[i]}，orzstr[1] = "a", orzstr[i] = orzstr[i - 1] . not(orzstr[i - 1]) 
 		那么|orzstr[i]| = |orzstr[i - 1]| * 2。显然这是等比数列，得到：|orzstr[i]| = |orzstr[1]| . 2 ^ (i - 1) = 2 ^ (i - 1) 
 		设hash(str)为str的哈希值。 
 		则： 
 		hash(orzstr[i]) = hash(orzstr[i - 1]) * base ^ |not(orzstr[i - 1])| + hash(not(orzstr[i - 1])) 
                        = hash(orzstr[i - 1]) * base ^ (2 ^ (i - 2)) + hash(not(orzstr[i - 1])) 
 		hash(not(orzstr[i])) = hash(not(orzstr[i - 1])) * base ^ (2 ^ (i - 2)) + hash(orzstr[i - 1]) 
 		两式相减： 
   		hash(orzstr[i]) - hash(not(orzstr[i])) 
		= (hash(orzstr[i - 1]) * base ^ (2 ^ (i - 2)) + hash(not(orzstr[i - 1]))) - (hash(not(orzstr[i - 1])) * base ^ (2 ^ (i - 2)) + hash(orzstr[i - 1])) 
		= (hash(orzstr[i - 1]) - hash(not(orzstr[i - 1]))) * (base ^ (2 ^ (i - 2)) - 1) 
 		这让我们发现，hash(orzstr[i]) - hash(not(orzstr[i]))似乎是个神奇的东西。而我们的目的实际上是要找两个字符串strA, strB使得 
		hash(strA) % 2^64 = hash(strB) % 2^64 
 		相当与 
 		2^64 \ hash(strA) - hash(strB) 
 		设数列{f[i]}，f[i] = hash(orzstr[i]) - hash(not(orzstr[i])) 
 		这样就有： 
 		f[i] = f[i - 1] * (base ^ (2 ^ (i - 2)) - 1) 
 		还是有点不爽啊……我们再设数列{g[i]}，g[i] = base ^ (2 ^ (i - 1)) - 1 
 		于是能写成： 
 		f[i] = f[i - 1] * g[i - 1] 
 		则f[i] = f[1] * g[1] * g[2] * ... * g[i - 1] 
 		然后发现一个神奇的事情？ 
 		base是奇数，则base的任意正整数次方也一定是奇数。所以对于任意的i必有g[i]为偶数，所以2 ^ (i - 1) \ f[i] 
 		问题是不是结束了呢……发现没有……这样的话我们要使2 ^ 64 \ f[i]，至少得让i = 65……然后发现|orzstr[65]|是个天文数字。 
 		发现我们刚才那样分析太坑爹了…… 
 		i > 1时有： 
 		g[i] = base ^ (2 ^ (i - 1)) - 1 = (base ^ (2 ^ (i - 2)) - 1) * (base ^ (2 ^ (i - 2)) + 1) = g[i - 1] * 一个偶数 
 		而g[1]显然是偶数吧…… 
 		那么4 \ g[2]，8 \ g[3]... 
 		也就是说2 ^ i \ g[i] 
 		所以f[i] 实际上有： 
 		(2 ^ 1) * (2 ^ 2) * (2 ^ 3) * ... * (2 ^ (i - 1)) \ f[i] 
 		2 ^ (i * (i - 1) / 2) \ f[i] 
 		当i取12时，就有66个2了哟！ 
 		这就是卡base为奇数时的方法。orzstr[12]和not(orzstr[12])即为所求。 
		而读入中base既有奇数又有偶数，直接在奇数构造的字符串后面加64个a就可以了。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1<<11,INF=0x3f3f3f3f;
char str[MAXN+3];
int main(){
	printf("%d %d\n",(1<<11)+65,(1<<10)); 
	str[1]='a';
	for(int i=1,cur=1;i<=11;i++,cur<<=1)
		for(int j=1;j<=cur;j++)str[cur+j]=str[j]=='a'?'b':'a';
	str[1<<11|1]='\0';
	printf("%s",str+1);
	for(int i=1;i<=65;i++)putchar('a');
	puts("");
	return 0;
}

