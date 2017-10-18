# include <iostream>
#include <stack> 

using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
}; 

//�������� 
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

//˳���ӡ���� 
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
2017��10��18��19:08:58
��β��ͷ��ӡ���� 
*/ 

//˼·1:ջ  ����һ��,��ѹջ   ��ѭ�����
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

//˼·2:�ݹ�   ���ַ������Ǻܺ�,������ǳ���ʱ�ͻ�ջ��� 
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

