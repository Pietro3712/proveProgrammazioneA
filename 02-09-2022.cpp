#include <iostream>
using namespace std;

struct node{
	char data;
	node* next;
};

void revert(char str[]){
	int len=0;
	char tmp;
	for(int i=0;str[i]!='\0';i++)
		len++;
	for(int i=0;i<len/2;i++){
		tmp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=tmp;
	}
}

void add(node* &list, char x){
	node* nuovo = new node;
	nuovo->data=x;
	nuovo->next=NULL;
	if(list==NULL)
		list=nuovo;
	else{
		node* cursor=list;
		while(cursor->next!=NULL)
			cursor=cursor->next;
		cursor->next=nuovo;
	}
}

void concat(node* &l1, node* l2){
	if(l1==NULL)
		l1=l2;
	if(l2==NULL);
	else{
		node* cursor=l1;
		while(cursor->next!=NULL)
			cursor=cursor->next;
		cursor->next=l2;
	}
}
void concatREC(node* &l1, node* l2){
	if(l1==NULL)
		l1=l2;
	if(l2==NULL);
	if(l1->next==NULL){
		l1->next=l2;
		cout << "capolinea baby" << endl;
	}
	else concatREC(l1->next, l2);
}
void concatGPT(node* &l1, node* l2) { // fatto da chatGPT
    if (l1 == NULL) {
        l1 = l2;
        return;
    }
    node* temp = l1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = l2;
}
void concatRECGPT(node* &l1, node* l2) { // fatto da chatGPT
    if (l1 == NULL) {
        l1 = l2;
        return;
    }
    if (l1->next == NULL) {
        l1->next = l2;
        return;
    }
    concatRECGPT(l1->next, l2);
}

void print(node* list){
	if(list==NULL)
		cout << "lista vuota...";
	else{
		while(list!=NULL){
			cout << list->data << " ";
			list=list->next;
		}
	}
}

int main(){
	/*
	int* a = new int[1000];
	int n;
	int k=0;
	int f=0;
	do{
		cout << "inserire numero: ";
		cin >> n;
		if(n>=0)
			a[k++]=n;
	}
	while(n>=0);
	cout << endl;
	for(int i=0;i<k;i++)
		cout << a[i] << " ";
	int *b = new int[1000];
	for(int i=0;i<k;i++){
		bool same=true;
		for(int j=0;j<k;j++)
			if(a[i]==a[j] && i!=j)
				same=false;
		if(same)
			b[f++]=a[i];
	}
	cout << endl;
	for(int i=0;i<f;i++)
		cout << b[i] << " ";
	delete[] a;
	delete[] b;
	*/
	node* l1=NULL;
	node* l2=NULL;
	add(l1,'a');
	add(l1,'d');
	add(l2,'g');
	add(l2,'f');
	add(l2,'l');
	print(l1);
	cout << endl;
	print(l2);
	cout << endl;
	concatREC(l1,l2);
	print(l1);
	return 0;
}