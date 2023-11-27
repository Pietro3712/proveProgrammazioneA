#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;

struct spesa{
	char causale[33];
	float importo=0;
};

int compatta(float* A, int n, float* B){
	int k=0;
	for(int i=0;i<n;i++){
		bool inserire=true;
		for(int j=0;j<k;j++)
			if(abs(A[i]-B[j])<=0.5)
				inserire=false;
		if(inserire)
			B[k++]=A[i];
	}
	return k;
}

int main(){
	/*float V1[6]={1.3,2.7,3.12,0.81,0.75,5.55};
	float V2[6];
	int size=compatta(V1,6,V2);
	for(int i=0;i<size;i++)
		cout << V2[i] << " ";*/
	/*char scambio[3];
	cout << endl << "quali due caratteri vuoi scambiare? (senza spazi) ";
	cin >> scambio;
	ifstream f1;
	f1.open("testo48.txt");
	if(f1.fail())
		return 1;
	ofstream f2;
	f2.open("testo_codificato.txt");
	while(!f1.eof()){
		char supportstring[31];
		f1 >> supportstring;
		for(int i=0;i<strlen(supportstring);i++){
				if(supportstring[i]==scambio[0])
					supportstring[i]=scambio[1];
				else if(supportstring[i]==scambio[1])
					supportstring[i]=scambio[0];
			}
		f2 << supportstring << " ";
	}
	f1.close();
	f2.close();*/
	const int RIGHE=2;
	const int COLONNE=3;
	spesa M[RIGHE][COLONNE];
	for(int i=0;i<RIGHE;i++){
		bool stop=false;	// per evitare di usare break 
		cout << endl << endl << "Dai causale e importo per ciascuna spesa del giorno " << i+1 << endl;
		for(int j=0;!stop && j<COLONNE;j++){
			cout << "Causale: ";
			cin.getline(M[i][j].causale,33);
			if(strcmp(M[i][j].causale,"stop")==0)
				stop=true;
			if(!stop){
				cout << "Importo: ";
				cin >> M[i][j].importo;
				cin.ignore();
			}
		}
	}
	char str[33];
	cout << endl << endl << "Dai causale di cui calcolare la somma: ";
	cin.getline(str,33);
	cout << endl; 
	for(int i=0;i<RIGHE;i++){
		float sum=0;
		for(int j=0;j<COLONNE;j++)
			if(strcmp(M[i][j].causale,str)==0)
				sum+=M[i][j].importo;
		cout << endl << "somma importi giorno " << i+1 << ": " << sum;
	}
	return 0;
}