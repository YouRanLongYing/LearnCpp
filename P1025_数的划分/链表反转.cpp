#include <iostream>
using namespace std;

class Node {
	int data;
	
public:
	Node(int value) {
		data = value;
		next = NULL;
//		cout<<"创建Node:"<<data<<endl;
	}
	~Node() {
//		cout<<"析构Node:"<<data<<endl;
	}
	void Display() {
		cout<<"<"<<data<<">";
	}
	Node* next = NULL;
};
Node* reverseNode(Node* cur,Node* next)
{
	if(cur == NULL||next == NULL){
		return cur;
	}
	Node* next2 = next->next;
	next->next = cur;
	
	return reverseNode(next,next2);
}
Node* reverseList(Node* head)
{
	if(head == NULL||head->next == NULL){
		return head;
	}
	Node* first = head;
	head = reverseNode(head,head->next);
	first->next = NULL;
	return head;
}

Node* reverseList2(Node* head)
{
	if(head == NULL||head->next == NULL){
		return head;
	}
	Node* first = reverseNode(head,head->next);
	head->next->next = head;
	head->next = NULL;
	return first;
}
void ShowList(Node* head)
{
	if(head == NULL){
		return;
	}
	Node* current = head;
	while(current !=NULL ){
		current->Display();
		current = current->next;
	}
	cout<<endl;
}
int main(int argc, char** argv) {
	Node* root=NULL;
	Node* last = NULL;
	for(int i=0;i<10;i++){
		Node* current = new Node(i);
		if(root == NULL){
			root = current;
			last = current;
			continue;
		}
		last->next = current;
		last = current;
	}
	
	ShowList(root);
	root = reverseList2(root);
	ShowList(root);
}
