#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct dati{
	int c1[1000];
	int c2;
	char c3;
};

void disgiungi(int* I, int n, dati &I1, dati &I2){
	int k1=0;
	int k2=0;
	for(int i=0;i<n;i++){
		if(I[i]%2==0)
			I1.c1[k1++]=I[i];
		else I2.c1[k2++]=I[i];
	}
	I1.c2=k1;
	I2.c2=k2;
	I1.c3='p';
	I2.c3='d';
}

bool sottostringa(char* S, char i, char f, char* SS){
	int Slen=strlen(S);
	int firstindex=-5;
	int lastindex=-5;
	for(int j=0;j<Slen && firstindex==-5;j++)
		if(S[j]==i)
			firstindex=j;
	for(int j=0;j<Slen && lastindex==-5;j++)
		if(S[j]==f && j>firstindex)
			lastindex=j;
	if(i=='#')
		firstindex=-1;
	if(f=='#')
		lastindex=Slen;
	if(firstindex==-5 || lastindex==-5 || firstindex>=lastindex)
		return false;
	int k=0;
	for(int j=firstindex+1;j<lastindex;j++)
		SS[k++]=S[j];
	SS[k]='\0';
	return true;
}

int main(){
	/*char S[]="mario.verdi@studenti.unipr.it";
	char SS[101];
	if(sottostringa(S,'s','@',SS))
		cout << SS;
	else cout << "false";*/
	/*ifstream f1;
	f1.open("indirizzi.txt");
	while(!f1.eof()){
		char S[65];
		char SS[65];
		f1.getline(S,65);
		if(sottostringa(S,'@','.',SS) && strcmp(SS,"studenti")==0){
			char nome[33];
			char cognome[33];
			if(sottostringa(S,'.','@',cognome))
				cout << cognome << " ";
			if(sottostringa(S,'#','.',nome))
				cout << nome << endl;
		}
	}
	f1.close();*/
	int n;
	cout << "inserisci n: " << endl;
	cin >> n;
	int prova[1000];
	int k=0;
	for(int i=0;i<n;i++){
		cout << "inserisci num: ";
		cin >> prova[k++];
	}
	dati A;
	dati B;
	disgiungi(prova,k,A,B);
	for(int i=0;i<A.c2;i++)
		cout << A.c1[i] << " ";
	cout << endl << A.c2
	<< endl << A.c3;
	cout << endl << endl;
	for(int i=0;i<B.c2;i++)
		cout << B.c1[i] << " ";
	cout << endl << B.c2
	<< endl << B.c3;
	return 0;
}