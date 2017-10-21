# include <iostream>

using namespace std;

/*
2017年10月15日16:40:38
链表的基本操作 
*/ 

typedef struct Node{
	int value;
	struct Node* next;
}Node; 

//初始化链表 
Node* initList(){
	Node* head = new Node();
	Node* p = new Node();
	int temp;
	cin>>temp;
	if(temp!=-1){
		head->next=p;
		p->value = temp;
		p->next=NULL;
	} else {
		return head;
	}
	
	while(true){
		cin>>temp;
		if(temp==-1){
			break;
		}
		Node* q = new Node();
		q->value = temp;
		q->next = NULL;
		
		p->next = q;
		p = p->next;
		
	}
	return head;
}

//打印链表 
void showList(Node* head){
	cout<<endl<<"-----------------华丽的分割线------------------"<<endl;
	if(head==NULL){
		return;
	}
	if(head->next==NULL){
	
	}
	Node* p = head->next;
	if(p==NULL){
		return ;
	} else {
		while(p!=NULL){
			cout<<p->value<<endl;
			p = p->next;
		}
	}
	cout<<"-----------------华丽的分割线------------------"<<endl<<endl;
}

//添加value到第一个 
void addToFirst(Node** head,int value){
	Node* p = new Node();
	p->next = NULL;
	p->value = value;
	if(head==NULL){
		head = &p;
		return ; 
	} else {
		if((*head)->next==NULL){
			(*head)->next = p;
			p->next = NULL;
		} else {
			p->next = (*head)->next;
			(*head)->next = p;
		}
		
	}
} 

//添加元素到末尾 
void addToEnd(Node** head,int value){
	Node* p = new Node();
	p->value = value;
	p->next = NULL;
	if(head==NULL){
		head = &p;
		return; 
	} else {
		Node* q = (*head)->next;
		if(q==NULL){
			q = p;
			(*head)->next = p;
		} else {
			while(q->next!=NULL){
				q = q->next;
			}
			q->next = p;
		}
	}
} 

//删除第一个元素    
void removeFirst(Node** head) {
	if(head==NULL){
		return ;
	} 
	Node* p = (*head)->next;
	if(p==NULL){
		return ;  //链表只有头结点,没有元素 
	} else {
		(*head)->next = p->next;
		delete p;
	} 
}

//删除与value相同的元素     
void removeValue(Node** head,int value){
	if(head==NULL){
		return ;
	} 
	Node* p = (*head)->next;
	if(p==NULL){
		return ;  //链表只有头结点,没有元素 
	} else {
		while(p->value==value){
			(*head)->next = p->next;
			delete p;
		}
		
		p = (*head)->next;
		if(p==NULL){
			return;
		}
		Node* pNext = p->next;
		
		while(pNext!=NULL){
			if(pNext->value==value){
				p->next = pNext->next;
				delete pNext;
			} else {
				p = p->next;
				if(p==NULL){
					break;
				} else {
					pNext = p->next;
				}
			}
		}
	} 
}

int main(void){
	//初始化 
	Node* head = initList();
	//showList(head);
	
	//addToFirst(&head,666);
	//showList(head);
	
	//addToEnd(&head,777);
	//showList(head);
	
//	cout<<"-----删除第一个元素后-------"<<endl; 
//	removeFirst(&head);
//	showList(head);
	
	removeValue(&head,3); 
	showList(head);
	
	return 0;
}

