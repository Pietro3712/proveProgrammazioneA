#include <iostream>
#include <cstring>
using namespace std;

struct node{
	int data;
	node* next;
};

int compact(float a[], int n, float b[]){
	float media=0;
	int k=0;
	for(int i=0;i<n;i++)
		media+=a[i];
	media=media/n;
	cout << "la media e': " << media << endl;
	for(int i=0;i<n;i++)
		if(a[i]>media)
			b[k++]=a[i];
	return k;
}

int sum(node* l, int m){		// iterativa
	if(l==NULL)
		return 0;
	int sum=0;
	while(l!=NULL){
		if(l->data%m==0)
			sum+=l->data;
		l=l->next;
	}
	return sum;
}
int sumREC(node* l, int m){		// ricorsiva
	if(l==NULL)
		return 0;
	if(l->data%m==0)
		return (l->data + sumREC(l->next,m));
	else return sumREC(l->next,m);
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
	/*
	float a[5]={1,2,3.14,4,2.5};
	float b[5];
	int len=compact(a,5,b);
	for(int i=0;i<len;i++)
		cout << b[i] << " ";*/
	char s1[101];
	char s2[101];
	cout << "inserire s1: ";
	cin.getline(s1,101);
	cout << endl << "inserire s2: ";
	cin.getline(s2,101);
	cout << endl << "s1: " << s1;
	cout << endl << "s2: " << s2;
	bool anagramma1=true;
    for(int i=0;i<strlen(s1) && anagramma1;i++)
        for(int j=0;j<strlen(s2);j++){
            if(s1[i]==s2[j]){
                anagramma1=true;
                break;
            }
            anagramma1=false;
        }
    bool anagramma2=true;
    for(int i=0;i<strlen(s2) && anagramma2;i++)
        for(int j=0;j<strlen(s1);j++){
            if(s2[i]==s1[j]){
                anagramma2=true;
                break;
            }
            anagramma2=false;
        }
    if(anagramma1 && anagramma2)
        cout << endl << s1 << " e' anagramma di " << s2;
    else cout << endl << s1 << " non e' anagramma di " << s2;
	/*node* list=NULL;
	Add(list,5);
	Add(list,10);
	Add(list,15);
	Add(list,20);
	Add(list,25);
	cout << "somma: " << sumREC(list,1);*/
	return 0;
}