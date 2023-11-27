#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Dati{
	float d;
	char s[81];
};

int trova_tutti(Dati* A, int n, int m, int* Ris){
	int k=0;
	for(int i=0;i<n;i++)
		if(A[i].d!=0 && A[i].d<=m)
			Ris[k++]=i;
	return k;
}

int main(){
	/*Dati M[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			M[i][j].d=0;
	ifstream in1;
	in1.open("mappa.txt");
	if(in1.fail()){
		cout << endl << "file non esistente";
		return 1;
	}
	while(!in1.eof()){
		int i,j;
		in1 >> i;
		in1 >> j;
		in1 >> M[i][j].d;
		in1 >> M[i][j].s;
	}
	in1.close();
	int r;
	int lim;
	do{
		cout << endl << "inserire r: ";
		cin >> r;
		cout << endl << "inserire lim: ";
		cin >> lim;
	} while(r<0 || r>=10 || lim<=0);
	int t[10];
	int k=trova_tutti(M[r],10,lim,t);
	cout << endl;
	for(int i=0;i<k;i++)
		cout << t[i] << " ";*/
	ifstream file1;
	ifstream file2;
	char nomefile[101];
	cout << endl << "inserisci nome file: ";
	cin.getline(nomefile,101);
	file1.open(nomefile);
	char supportstring[107]="nuovo_";
	file2.open(strcat(supportstring,nomefile));
	if(file1.fail() || file2.fail())
		return 1;
	int riga=0;
	while(!file1.eof() && !file2.eof()){
		char str1[101];
		file1.getline(str1,101);
		char str2[101];
		file2.getline(str2,101);
		if(strcmp(str1,str2)!=0){
			cout << endl << "i file sono diversi"
			<< endl << "riga numero: " << riga
			<< endl << "righe: " << endl 
			<< str1 << endl << str2;
			return 0;
		}
		else riga++;
	}
	if(file1.eof() && file2.eof())
		cout << endl << "i file sono identici";
	return 0;
}