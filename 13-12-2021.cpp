#include <iostream>
#include <cstring>
using namespace std;
//oltre agli esercizi c'è anche un ambiente per testarli

struct node{
	int data;
	node* next;
};

int coincide(int a1[], int a2[], int d1, int d2){
	int max,min;
	int ris=0;
	if(d1>d2){
		max=d1;
		min=d2;
	}
	else{
		max=d2;
		min=d1;
	}
	for(int i=0;i<min;i++){
		if(a1[i]==a2[i])
			ris++;
	}
	return ris;
}
void addHead(node* &l1, int x){
	node* nuovo=new node;
	nuovo->data=x;
	nuovo->next=l1;
	l1=nuovo;
}
void concat(node* &l1, node* l2){
	if(l1==NULL)
		l1=l2;
	if(l2==NULL);
	else{
		node* cursor=l1;
		while(cursor->next!=NULL){
			cursor=cursor->next;
		}
		cursor->next=l2;
	}
}

void concatREC(node* &l1, node* l2){
	if(l1==NULL)
		l1=l2;
	if(l2==NULL);
	if(l1->next==NULL)
		l1->next=l2;
	else concatREC(l1->next, l2);
}

void print(node* l1){
	if(l1==NULL)
		cout << "la lista e' vuota... ";
	while(l1!=NULL){
		cout << l1->data << " ";
		l1=l1->next;
	}
}
int main(){
	char parola[31];
	cout << "inserire la parola: ";
	cin.getline(parola,31);
	while(cin.fail()){
		cout << "errore...reinserire... ";
		cin.clear();
		cin.ignore(1000,'\n');
		cin.getline(parola,31);
	}
	cout << endl << "la parola inserita e': " << parola;
	int len=strlen(parola);
	bool palindroma=true;
	for(int i=0;i<len;i++){
		if(parola[i]!=parola[len-i-1])
			palindroma=false;
	}
	if(palindroma)
		cout << endl << "la parola inserita e' palindroma...";
	else cout << endl << "la parola inserita non e' palindroma";
	node* l1=NULL;
	node* l2=NULL;
	addHead(l1,5);
	addHead(l1,7);
	addHead(l1,3);
	addHead(l1,8);
	addHead(l2,6);
	addHead(l2,1);
	addHead(l2,9);
	cout << "ora concatenero': ";
	print(l2);
	cout << endl << "ad: ";
	print(l1);
	cout << endl;
	concatREC(l1,l2);
	print(l1);
	return 0;
}