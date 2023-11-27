#include <iostream>
#include <cstring>
using namespace std;

struct strutture{
	char nome[100];
	int v;
};

int ricerca(strutture* T, int n, char* S){
	for(int i=0;i<n;i++)
		if(strcmp(T[i].nome,S)==0)
			return i;
	return -1;
}

bool calcola(int *A, int n, int x, int& q){
	int somma=0;
	for(int i=0;i<n;i++)
		somma+=A[i];
	if(somma!=0){
		q=x/somma;
		return true;
	}
	else return false;
}

int main(){
	/*char stringa[32];
	char stop[]="stop";
	strutture TAB[100];
	int k=0;
	cout << "inserisci stringa: ";
	cin >> stringa;
	while(strcmp(stringa,stop)!=0){
		if(ricerca(TAB,k,stringa)==-1){
			strcpy(TAB[k].nome,stringa);
			TAB[k].v=strlen(stringa);
			k++;
		}
		cout << endl << "inserisci stringa: ";
		cin >> stringa;
	}
	cout << endl << "stringa piu' lunga: ";
	int max=TAB[0].v;
	for(int i=0;i<k;i++)
		if(TAB[i].v>=max)
			max=TAB[i].v;
	for(int i=0;i<k;i++)
		if(TAB[i].v==max)
			cout << TAB[i].nome << endl;*/

	int A[]={1,-1,2,-2};
	int f=0;
	cout << endl;
	if(calcola(A,4,5,f))
		cout << "la divisione si puo' effettuare e il quoziente vale: " << f;
	else cout << "non posso dividere per zero...";

	return 0;
}