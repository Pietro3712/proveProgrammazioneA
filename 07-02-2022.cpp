#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
};

void ruota(int a[], int dim){
	int tmp=a[dim-1];
	for(int i=0;i<dim-1;i++){
		a[dim-i-1]=a[dim-i-2];
	}
	a[0]=tmp;
}
void ruotasucarta(int* a, int len){
	int tmp=a[0];
	for(int i=0;i<len-1;i++)
		a[i]=a[i+1];
	a[len-1]=tmp;
}
void ruotaGPT(int a[], int n) {	// fatto da chatGPT
  int temp = a[n-1];
  for(int i = n-1; i > 0; i--) {
    a[i] = a[i-1];
  }
  a[0] = temp;
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

bool isDescending(node* l){
	if(l==NULL || l->next==NULL)
		return true;
	else{
		while(l->next!=NULL){
			if(l->data <= l->next->data)
				return false;
			l=l->next;
		}
		return true;
	}
}

bool isDescendingREC(node* l){
	if(l==NULL)
		return true;
	else if(l->next->next==NULL)
		return ( l->data > l->next->data);
	else{
		if(isDescendingREC(l->next))
			return l->data > l->next->data;
		else return false;
	}
}
bool isDescendingREC2(node* l){
	if(l==NULL)
		return true;
	if(l->next->next==NULL)
		return ( l->data >= l->next->data);
	if(l->data <= l->next->data)
		return false;
	else return isDescendingREC2(l->next);
}
bool isDescendingGPT(node* head) { 	// fatto da chatGPT
    if (head == nullptr) return true; // empty list is considered descending
    node* current = head;
    while (current->next != nullptr) {
        if (current->data <= current->next->data) return false; // not strictly descending
        current = current->next;
    }
    return true; // all elements are strictly descending
}

bool isDescendingHelper(node* current, int previousData) { // fatto da chatGPT
    if (current == nullptr) return true;
    if (current->data >= previousData) return false;
    return isDescendingHelper(current->next, current->data);
}

bool isDescendingRECGPT(node* head) {		// fatto da chatGPT
    if (head == nullptr) return true; // empty list is considered descending
    return isDescendingHelper(head->next, head->data);
}

int main () {
	int x [6] = {2 , 3 , 4 , 5, 12, 13};
	ruota (x , 6);
	for(int i=0;i<6;i++)
		cout << x[i] << " ";
	/*int* a=new int[1000];
	int n;
	int k=0;
	cout << "Inserire n: ";
	cin >> n;
	while(n>=0){
		a[k++]=n;
		cout << "Inserire n: ";
		cin >> n;
	}
	// Stampo array
	cout << endl;
	for(int i=0;i<k;i++)
		cout << a[i] << " "; 
	int* b=new int[1000];
	int min=a[0];
	int max=a[0];
	for(int i=0;i<k;i++){
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
	}
	int f=0;
	cout << endl;
	for(int i=0;i<k;i++)
		if(a[i]!=min && a[i]!=max)
			b[f++]=a[i];
	for(int i=0;i<f;i++)
		cout << b[i] << " ";
	delete[] a;
	delete[] b;*/
	node* list=NULL;
	Add(list,12);
	Add(list,3);
	Add(list,3);
	Add(list,-7);
	cout << endl;
	print(list);
	cout << endl;
	if(isDescendingREC(list))
		cout << "la lista e' strettamente decrescente";
	else cout << "la lista non e' strettamente decrescente";
	cout << endl << endl;
	if(isDescendingREC2(list))
		cout << "la lista e' strettamente decrescente";
	else cout << "la lista non e' strettamente decrescente";
	return 0;
}