#include <iostream>
#include <cstring>
using namespace std;
struct node{
	int data;
	node* next;	
};
void add(node* &list, int x){  
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

node* intersect(node* l1, node* l2){	// e' supposto che gli elementi non si ripetano
	node* l3 = NULL;
	if(l1==NULL || l2==NULL)
		return l3;
	while(l1!=NULL){
		node* cursor=l2;
		while(cursor!=NULL){
			if(l1->data == cursor->data)
				add(l3,l1->data);
			cursor=cursor->next;
		}
		l1=l1->next;
	}
	return l3;
}

bool doppia(char* str){
	int len1=0;
	for(int i=0;str[i]!='\0';i++)
		len1++;
	int len2=len1/2;
	for(int i=0;i<len2;i++)
		if(str[i]!=str[len2+i])
			return false;
	return true;
}

char* add_white_spaces(char* str, char c){
	char *nuovo=new char[101];
	int k=0;
	for(int i=0;i<strlen(str);i++){
		nuovo[k++]=str[i];
		if(str[i]==c)
			nuovo[k++]=' ';
	}
	nuovo[k]='\0';
	return nuovo;
}

int main(){
	/*node* l1=NULL;
	node* l2=NULL;
	add(l1,1);
	add(l1,2);
	add(l1,3);
	add(l1,5);
	add(l1,7);
	add(l2,1);
	add(l2,3);
	add(l2,5);
	node* l3=intersect(l1,l2);
	print(l3);*/
	/*char str1[101]="canecane";
	cout << doppia(str1);
	char str2[101]="deathdeath";
	cout << doppia(str2);
	char str3[101]="sonoio";
	cout << doppia(str3);*/
	char str[101];
	cout << "dai stringa: ";
	cin.getline(str,101);
	cout << add_white_spaces(str,'a');
}
