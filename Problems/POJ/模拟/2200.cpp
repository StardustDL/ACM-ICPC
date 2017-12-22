/*
A Card Trick
题意：主要是将5张牌做全排列，然后找出符合要求的一种情况即可。 
分析：最大的收获是加深了对next_permutaiton函数的理解。
	  在此题中，我是把每张牌抽象成了一个包含牌数（int value）和花色（char suit）的结构体。
	  对结构体运用next_permutaiton有两点要特别注意：
		（1）要自定义以一个比较函数，两种方法任选一种：
			a.在结构体定义中直接重载<或==或>操作符
			b.额外写个比较函数（用过std::sort对这个方法不陌生）
		（2）遍历所有的全排列情况之前，一定要对结构体数组，按照上面说的这个比较函数做一次排序（用std::sort会比较方便），若使用升序，则后面必须用next_permutaiton，若为降序则必须用prev_permutaiton。否则，会从中间遍历的全排列情况，导致情况缺失。
	  值得一提的是，在当前数组其中的元素处于任一顺序状态下的时候，
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct card{
	int value;
	char suit;
	card(){}
	card(int v, char s):value(v),suit(s){}
	bool operator <(const card& other)const{
		return (value<other.value)||(value==other.value&&suit<other.suit);
	}
};
void initialize(card* cards){
	string tmp;
	for(int i=0;i<5;i++){
		cin>>tmp;
		if(tmp.length()==2){
			switch(tmp[0]){
				case 'A':cards[i].value=1;break;
				case 'J':cards[i].value=11;break;
				case 'Q':cards[i].value=12;break;
				case 'K':cards[i].value=13;break;
				default:cards[i].value=tmp[0]-'0';break;
			}
		}
		else if(tmp.length()==3)cards[i].value=10;
		cards[i].suit=tmp[tmp.length()-1];
	}
}
void printResult(int counter,card* cards){
	printf("Problem %d:",counter);
	for (int i=0;i<5;i++){
		putchar(' ');
		switch(cards[i].value){
			case 1:putchar('A');break;
			case 11:putchar('J');break;
			case 12:putchar('Q');break;
			case 13:putchar('K');break;
			default:printf("%d",cards[i].value);break;
		}
		printf("%c",cards[i].suit);
	}
	puts("");
}
int main(){
	int caseNum;
	cin>>caseNum;
	for(int counter=1;counter<=caseNum;counter++){
		card cards[5];
		initialize(cards);
		sort(cards, cards + 5);  //  必须排序！！！
		do{
			if(cards[0].suit!=cards[1].suit)continue;
			int sum=cards[1].value,minIndex;
			card min(20,'Z');
			vector<card> toBeCmped;
			for (int k=2;k<5;k++)
				if(cards[k]<min){
					min=cards[k];
					minIndex=k;
				}
			for(int k=2;k<5;k++)
				if(k!=minIndex)toBeCmped.push_back(cards[k]);
			if(toBeCmped[0]<toBeCmped[1])sum+=(minIndex-1);
			else sum+=(minIndex-1)+3;
			if(sum%13==cards[0].value){
				printResult(counter,cards);
				break;
			}
		}while(next_permutation(cards,cards+5));
	}
	return 0;
}
