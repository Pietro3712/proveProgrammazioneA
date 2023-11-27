#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

bool palindroma(char str[]){	// non consentito l'uso di cstring
	// conto lunghezza
	int len=0;
	for(int i=0;str[i]!='\0';i++)
		len++;
	for(int i=0;i<len/2;i++)	// posso anche fare len/2
		if(str[i]!=str[len-i-1])
			return false;
	return true;
}

int coincide(int a1[], int a2[], int dim1, int dim2){
	int coincidenti=0;
	int max,min;
	if(dim1>=dim2)
		min=dim2;
	else min=dim1;
	for(int i=0;i<min;i++)
		if(a1[i]==a2[i])
			coincidenti++;
	return coincidenti;
}

int* firstEven(node* list){			// opzione in più
	if(list==NULL){
		cout << "vuota";
		return NULL;
	}
	else{
		while(list!=NULL){
			if(list->data%2==0){
				int* p=&(list->data);	//opzione in più
				return p;
			}
			list=list->next;
		}
	}
	return NULL;
}
node* firstEvenREC(node* list){
	cout << "lavorando...";
	if(list==NULL){
		cout << "vuota";
		return NULL;
	}
	else{
		if(list->data%2==0)
			return list;
		else return firstEvenREC(list->next);
	}
}
void Add(node* &list, int x){  
    node* nuovo = new node;
    nuovo->data=x;
    nuovo->next=NULL;
    if(list==NULL){
        list=nuovo;
    }
    else{
        node* cursor=list;
        while(cursor->next!=NULL)
            cursor=cursor->next;
        cursor->next=nuovo;
    }
}
void print(node* list){
    if(list==NULL)
        cout << "la lista e' vuota...";
    else{
        while(list!=NULL){
            cout << list->data << " ";
            list=list->next;
        }
    }
}
int main(){
	//char str[]="osso";
	//cout << palindroma(str);
	/*
	int a1[7]={7,6,4,-1,2,5,12};
	int a2[5]={6,7,4,5,2};
	cout << "elementi coincidenti: " << coincide(a1,a2,7,5);*/
	node* list=NULL;
	Add(list,5);
	Add(list,9);
	Add(list,4);
	Add(list,1);
	Add(list,5);
	//int* p=firstEven(list);
	//cout << endl << *p << endl;
	node* p1=firstEvenREC(list);
	cout << endl << p1->data << endl;
	return 0;
}