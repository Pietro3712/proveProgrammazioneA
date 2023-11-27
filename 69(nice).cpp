#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>
using namespace std;

struct P{
	int c1;
	char c2[81];
};

struct elem{
	int data;
	elem* next;
};

int restringi(P R[], int A[], int n, int m, P S[]){	// ipotizzo m lunghezza di A
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(R[i].c1==A[j]){
				S[k++]=R[i];
				break;
			}
		}
	}
	return k;
}
void Add(elem* &list, int x){  
    elem* nuovo = new elem;
    nuovo->data=x;
    nuovo->next=NULL;
    if(list==NULL){
        list=nuovo;
    }
    else{
        elem* cursor=list;
        while(cursor->next!=NULL)
            cursor=cursor->next;
        cursor->next=nuovo;
    }
}

bool contains(elem* list, int x){
	while(list!=NULL){
		if(list->data==x)
			return true;
		list=list->next;
	}
	return false;
}

bool self_loop(elem* A[], int n){
	for(int i=0;i<n;i++)
		if(contains(A[i], i))
			return false;
	return true;
}

int main(){
	P R1[]={{23,"aaa"},{19,"bbb"},{25,"ddd"},{23,"ccc"}};
	int A1[]={19,23,27};
	P S1[50];
	int l=restringi(R1,A1,4,3,S1);
	for(int i=0;i<l;i++)
		cout << S1[i].c2 << "   " << S1[i].c1 << endl;

	bool M[100][100];
	char nomefile[69];
	cout << "inserire il nome del file: ";
	cin.getline(nomefile,65);
	strcat(nomefile,".txt");
	ifstream f1;
	f1.open(nomefile);
	if(f1.fail())
		return 1;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			M[i][j]=false;
	int i,j;
	for(int a=0;!f1.eof();a++){
		f1>>i;
		cout << i << endl;
		if(f1.eof())
			break;
		f1>>j;
		cout << j << endl;
		if(i<0 || i>99 || j<0 || j>99){
			cout << "errore" << endl;
			continue;
		}
		M[i][j]=true;
	}
	f1.close();
	bool diagonale=true;
	for(int i=0;i<100;i++)
		if(M[i][i]==true)
			diagonale=false;
	if(diagonale)
		cout << endl << "la diagonale e' composta solo da false " << endl;
	else cout << "la diagonale presenta almeno un true " << endl;
	/*
	elem* A1[4];
	A1[0]=NULL;
	A1[1]=NULL;
	A1[2]=NULL;
	A1[3]=NULL;
	Add(A1[0],5);
	Add(A1[0],7);
	Add(A1[1],3);
	Add(A1[1],8);
	Add(A1[2],9);
	Add(A1[2],9);
	Add(A1[3],12);
	Add(A1[3],11);
	Add(A1[3],25);
	if(self_loop(A1,4))
		cout << "true";
	else cout << "false";*/
	return 0;
}