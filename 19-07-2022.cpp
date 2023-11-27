#include <iostream>
using namespace std;

struct intv{
	int inf;
	int sup;
};
struct node{
	int data;
	node* next;
};
bool add(intv &i, int x){
	if(x==i.sup+1){
		i.sup=x;
		return true;
	}
	else if(x==i.inf-1){
		i.inf=x;
		return true;
	}
	else if(x<=i.sup && x>=i.inf)
		return true;
	else return false;
}

int compact(int* a, int n, int* b){
	int k=0;
	for(int i=0;i<n;i++){
		bool copy = true;
		for(int j=0;j<k;j++)
			if(a[i]==b[j])
				copy=false;
		if(copy)
			b[k++]=a[i];
	}
	return k;
}
bool equals(node* l1, node* l2){
	if(l1==NULL && l2==NULL)
		return true;
	else if(l1==NULL)
		return false;
	else if(l2==NULL)
		return false;
	else{
		while(l1!=NULL && l2!=NULL){
			if(l1->data!=l2->data)
				return false;
			l1=l1->next;
			l2=l2->next;
		}
		if(l1==NULL && l2==NULL)
			return true;
		else return false;
	}
}
bool equalsREC(node* l1, node* l2){
	if(l1==NULL && l2==NULL)
		return true;
	else if(l1==NULL)
		return false;
	else if(l2==NULL)
		return false;
	else{
		if(l1->data==l2->data)
			return equalsREC(l1->next,l2->next);
		else return false;
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
	/*int a[9]={1,2,7,1,2,4,1,7,5};
	int b[5];
	int numeri=compact(a,9,b);
	cout << numeri << endl << endl << "vettore compattato: ";
	for(int i=0;i<numeri;i++)
		cout << b[i] << " ";*/
	/*intv i;
	i.inf=3;
	i.sup=7;
	cout << endl << add(i,8);
	cout << endl << "[ " << i.inf << " , " << i.sup << " ]";*/
	node* l1=NULL;
	node* l2=NULL;
	Add(l1,5);
	Add(l1,2);
	Add(l1,3);
	Add(l2,5);
	Add(l2,2);
	Add(l2,1);
	Add(l2,5);
	cout << equalsREC(l1,l2);
	return 0;
}