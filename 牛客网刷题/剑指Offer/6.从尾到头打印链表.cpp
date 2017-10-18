# include <iostream>
#include <stack> 

using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
}; 

//创建链表 
ListNode* createList(int len){
	ListNode* pHead = new ListNode();
	pHead->next = NULL;
	ListNode* p = pHead;
	ListNode* q = NULL;
	int value;
	for(int i=0;i<len;i++){
		cin>>value;
		q = new ListNode();
		q->value = value;
		p->next = q;
		p = q; 
	}
	p->next = NULL;
	return pHead;
} 

//顺序打印链表 
void showList(ListNode* pHead){
	if(pHead==NULL){
		return;
	}
	ListNode* p = pHead->next;
	while(p!=NULL){
		cout<<p->value<<endl; 
		p = p->next;
	}
}

/*
2017年10月18日19:08:58
从尾到头打印链表 
*/ 

//思路1:栈  遍历一次,先压栈   再循环输出
void PrintListReversingly_Iteratively(ListNode* pHead){
	if(pHead==NULL){
		return;
	}
	stack<ListNode*> nodes;
	ListNode* p = pHead->next;
	while(p!=NULL){
		nodes.push(p);
		p = p->next;
	}
	
	ListNode* temp;
	while(!nodes.empty()){
		temp = nodes.top();
		cout<<temp->value<<endl;
		nodes.pop();
	}
}

//思路2:递归   这种方法不是很好,当链表非常长时就会栈溢出 
void PrintListReversingly_Recursively(ListNode* pHead){
	if(pHead!=NULL){
		if(pHead->next!=NULL){
			PrintListReversingly_Recursively(pHead->next);
		}
		cout<<pHead->value<<endl;
	} 
} 

int main(void)
{
	ListNode* pHead = createList(3);
	//PrintListReversingly_Recursively(pHead); 
	PrintListReversingly_Iteratively(pHead);
	return 0;
}

