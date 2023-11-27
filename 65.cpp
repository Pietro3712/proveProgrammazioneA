#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Dati{
	int d;
	char s[81];
};

struct elem{
	int info;
	elem* punt;
};

bool estrai_testa(elem* Elenco[], int n, int& ris){
	bool trovato=false;
	for(int i=0;i<n;i++)
		if(Elenco[i]!=NULL){
			trovato=true;
			ris=Elenco[i]->info;
			delete Elenco[i];
			break;
		}
	return trovato;
}

int trova(Dati* A, int n, char* r, int* Ris){
	int k=0;
	for(int i=0;i<n;i++)
		if(strcmp(A[i].s,r)<0)
			Ris[k++]=i;
	return k;
}

int main(){
	/*Dati A[]={{27,"ddd"},{30,"aaa"},{40,"fff"},{35,"bbb"}};
	int *Ris;
	int counter = trova(A,4,"ccc",Ris);
	int k=0;
	for(int i=0;i<4;i++)
		if(i==Ris[k]){
			cout << A[i].d << "  ";
			k++;
		}*/
	/*float M[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			M[i][j]=0;
	ifstream f1;
	f1.open("dati65.txt");		// ho aggiunto 65 nella stringa per evitare confusione nella cartella
	if(f1.fail())
		return 1;
	int i;
	int j;
	float n;
	while(!f1.eof()){
		f1 >> n;
		do{
			cout << endl << "inserire i: ";
			cin >> i;
			cout << endl << "inserire j: ";
			cin >> j;
		} while(i>9 || i<0 || j>9 || j<0 || M[i][j]!=0);
		M[i][j]=n;
	}
	cout << endl << endl;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			cout << M[i][j] << " ";
		cout << endl;
	}*/
	elem* Elenco[]={NULL,NULL,NULL,NULL};
	int risul=0;
	Elenco[2]=new elem;
	Elenco[2]->info=5;
	Elenco[2]->punt=new elem;
	Elenco[2]->punt->info=7;
	Elenco[2]->punt->punt=NULL;
	bool sex=estrai_testa(Elenco,4,risul);
	cout << endl << risul;
	return 0;
}