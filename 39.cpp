#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct d{
	char alfa[33];
	float val;
};

int aggiungi_o_aggiorna(d* A, int n, d x){
	for(int i=0;i<n;i++)
		if(strcmp(A[i].alfa,x.alfa)==0){
			A[i].val+=x.val;
			return n;
		}
	A[n]=x;	
	return n+1;
}

int main(){
	/*ifstream f1;
	f1.open("config.txt");
	d dati[1000];
	int k=0;
	d supporto;
	char supportinome[133];
	ifstream fsupport;
	while(!f1.eof() && k<1000){
		f1.getline(supportinome,133); 
		fsupport.open(strcat(supportinome,".txt"));
		if(fsupport.fail()){
				cout << endl << "errore" << endl;
				fsupport.clear();
				continue;
			}
		while(!fsupport.eof()){
			fsupport >> supporto.alfa;
			fsupport >> supporto.val;
			k=aggiungi_o_aggiorna(dati,k,supporto);
		} 
		fsupport.close();
	}
	f1.close();
	cout << endl << "finito" << endl;
	ofstream f2;
	f2.open("risultati.txt");
	for(int i=0;i<k;i++)
		f2 << dati[i].alfa << " " << dati[i].val << endl;*/

	int M[10][10];
	//int n;
	/*for(int i=0;i<10;i++)		// troppo noioso dover scrivere 100 numeri ogni volta
		for(int j=0;j<10;j++){
		cout << endl << "inserire: ";
		cin >> n;
		M[i][j]=n;
		}*/
	ifstream f1;
	f1.open("centonum.txt");
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			f1 >> M[i][j];
	int k=0;
	int contatore=0;
	int cord1;
	int cord2;
	cout << endl << "inserire k: ";
	cin >> k;
	while(k>0){
	if(k>10){
		cout << endl << "reinserire: ";
		cin >> k;
		continue;
	}
	bool end=false;
	for(int i=0;i<10 && !end;i++){
		for(int j=0;j<10;j++){
			if(M[i][j]==0)
				contatore++;
			else contatore=0;
			if(contatore==1){
				cord1=i;
				cord2=j;
			}
			if(contatore==k){
				cout << endl << "cord1: " << cord1;
				cout << endl << "cord2: " << cord2;
				end=true;
			}
		}
		contatore=0;
	}
	cout << endl << "inserire k: ";
	cin >> k;
	}
	return 0;
}