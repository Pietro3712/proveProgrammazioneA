#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct S{
	int val;
	int occ;
};

void aggiorna(S* R, int &m, int x){
	for(int i=0;i<m;i++)
		if(R[i].val==x){
			R[i].occ++;
			return;
		}
	R[m].val=x;
	R[m++].occ=1;
}

void ordina(S* A, int n){
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1;j++){
			if(A[j].occ<A[j+1].occ){
				S tmp=A[j];
				A[j]=A[j+1];
				A[j+1]=tmp;
			}
		}
}

int main(){
	bool risposta=false;;
	do{
		char nomefile[81];
		cout << "dai un nome al file: ";
		cin.getline(nomefile,81);
		ifstream f1;
		f1.open(nomefile);
		if(f1.fail())
			return 1;
		S dati[1000];
		int daticounter=0;
		while(!f1.eof() && daticounter < 1000){
			int n;
			f1 >> n;
			aggiorna(dati,daticounter,n);
		}
		f1.close();
		ordina(dati,daticounter);
		char prefix[122]="statistiche_per";
		ofstream f2;
		f2.open(strcat(prefix,nomefile));
		for(int i=0;i<daticounter;i++)
			f2 << dati[i].val << " " << dati[i].occ << endl;
		cout << endl << "continuare? [0/1] ";
		cin >> risposta;
		cin.ignore();
	} while(risposta==true);
	return 0;
}