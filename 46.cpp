#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct tabella{
	float entrate;
	float uscite;
	float saldo;
};

void inserisci(char* A, char* B, int i){
	char sup1[101];
	for(int j=0;j<i;j++)
		sup1[j]=A[j];
	sup1[i]='\0';
	int len=strlen(B);
	strcat(sup1,B);
	for(int j=i;j<strlen(A);j++)
		sup1[j+len]=A[j];
	sup1[strlen(A)+len]='\0';
	strcpy(A,sup1);
}

int main(){
	char s1[101];
	char s2[101];
	int pos=0;
	cout << endl << "inserire s1: ";
	cin.getline(s1,101);
	cout << endl << "inserire s2: ";
	cin.getline(s2,101);
	cout << endl << "inserire pos: ";
	cin >> pos;
	inserisci(s1,s2,pos);
	cout << endl << "s1 modificata: " << s1;
	ifstream file1;
	ifstream file2;
	ofstream file3;
	file1.open("modulo.txt");
	file2.open("info.txt");
	file3.open("compilato.txt");
	while(!file1.eof()){
		char str[101];
		file1 >> str;
		if(strcmp(str,"#,")==0){
			file2.getline(str,101);
			strcat(str,",");
		}
		else if(strcmp(str,"#")==0)
			file2.getline(str,101);
		file3 << str << " ";
	}
	file1.close();
	file2.close();
	file3.close();
	tabella T[31];
	int numrighe;
	do{
	cout << "quante righe vuoi inserire? (max 31) ";
	cin >> numrighe;
	} while(numrighe<0 || numrighe >31); 
	for(int i=0;i<numrighe;i++){
		cout << endl << "inserisci entrate della riga " << i << ": ";
		cin >> T[i].entrate;
		cout << endl << "inserisci uscite della riga " << i << ": ";
		cin >> T[i].uscite;
	}
	cout << endl << endl << "entrate\tuscite\tsaldo" << endl;
	int sommaentrate=0;
	int sommauscite=0;
	int saldofinale=0;	// opzionale
	int negativecounter=0;
	for(int i=0;i<numrighe;i++){
		if((T[i].saldo=T[i].entrate-T[i].uscite)<0)
			negativecounter++;
		cout << T[i].entrate << "\t" << T[i].uscite << "\t" << T[i].saldo << endl;
		sommaentrate+=T[i].entrate;
		sommauscite+=T[i].uscite;
		saldofinale+=T[i].saldo;	// opzionale poiche' potrei stampare sommaentrate-sommauscite	
	}
	cout << endl << endl << "somma delle entrate:" << sommaentrate
	<< endl << "somma delle uscite: " << sommauscite
	<< endl << "saldo finale: " << saldofinale
	<< endl << "numero di volte saldo negativo: " << negativecounter;
	return 0;
}