#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct node{
	float data;
	node* next;
};

struct S{
	char cognome[81];
	int eta;
};

void concat(node* &l1, node* l2){
	if(l1==NULL && l2==NULL)
		cout << endl << "entrambe le liste sono vuote";
	else if(l1==NULL)	// l1 ed l2 dovranno coincidere
		l1=l2;
	else if(l2==NULL);	// non devo concatenare nulla quindi non faccio nulla
	else{
		node* cursor=l1;
		while(cursor->next!=NULL)
			cursor=cursor->next;
		cursor->next=l2;
	}
}

void concatREC(node* &l1, node* l2){
	if(l1->next==NULL)		// caso base per quando giungo al capolinea
		l1->next=l2;
	else if(l1==NULL && l2==NULL)
		cout << endl << "entrambe le liste sono vuote";
	else if(l1==NULL)
		l1=l2;
	else if(l2==NULL);
	else concatREC(l1->next, l2);
}

int estrai_eta(S* A, int n, int* R){
	int counter=0;
	for(int i=0;i<n;i++){
		bool free=true;
		for(int j=0;j<counter;j++)		// controllo che non sia gia' presente
			if(A[i].eta==R[j])
				free=false;				// in questo caso e' gia presente 
		if(free)
			R[counter++]=A[i].eta;
	}
	return counter;
}
void printREC(node* l1){
	if(l1==NULL)
		cout << endl << "la lista e' vuota";
	else if(l1->next==NULL)
		cout << l1->data;
	else{
		cout << l1->data << " ";
		printREC(l1->next);
	}
}

int main(){
	/*S T1[]={{"aaa",23},{"bbb",19},{"ccc",23},{"ddd",25},{"eee",19}};
	int* R;
	int k=estrai_eta(T1,5,R);
	for(int i=0;i<k;i++)
		cout << "      " << R[i];*/
	/*char nomefile[65];
	cout << "inserire nomefile: ";
	cin.getline(nomefile,65);
	S tabella1[1000];
	int insieme_eta[1000];
	ifstream f1;
	f1.open(nomefile);
	if(f1.fail()){
		f1.clear();
		f1.open(strcat(nomefile,".txt"));
	}
	if(f1.fail())
		return 1;
	int k=0;					// fara' da contatore a tabella1
	while(!f1.eof()){
		f1 >> tabella1[k].cognome;		// prendo cognome, se volessi ignorare spazi userei f1.getline();
		f1 >> tabella1[k].eta;
		k++;
	}
	f1.close();
	int counter=estrai_eta(tabella1,k,insieme_eta);
	ofstream f2;
	char preffisso[60]="eta_di_";			// mi serve altrimenti vado a occupare memoria non mia (quella precedente a nomefile[0])
	f2.open(strcat(preffisso,nomefile));
	for(int i=0;i<counter;i++)
		f2 << insieme_eta[i] << "      ";
	f2.close();*/
	node* l1=NULL;
	node* l2=NULL;
	l1=new node;
	l1->data=1.5;
	l1->next=new node;
	l1->next->data=2.3;
	l1->next->next=NULL;
	l2=new node;
	l2->data=1.1;
	l2->next=new node;
	l2->next->data=0.5;
	l2->next->next=NULL;
	concatREC(l1,l2);
	printREC(l1);
	return 0;
}