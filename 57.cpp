#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Data{
	int g;
	int m;
	int a;
};

bool ricerca(Data* v[], int n, Data d){
	for(int i=0;i<n;i++)
		if(v[i]->g==d.g && v[i]->m==d.m && v[i]->a==d.a)
			return true;
	return false;
}

void rimuovi(char* T){
	int k=0;
	for(int i=0;T[i]!='\0';i++){
		if(T[i]=='-' || T[i]=='.' || T[i]==' ');
		else T[k++]=T[i];
	}
	T[k]='\0';
}

int main(){
	/*char nomefile[33];
	cout << "inserire nome file: " << endl;
	cin.getline(nomefile,33);
	ifstream f1;
	f1.open(nomefile);
	if(f1.fail()){
		f1.clear();
		f1.open(strcat(nomefile,".txt"));
	}
	if(f1.fail())
		return 1;
	ofstream f2;
	f2.open("output.txt");
	int lette=0;
	int modificate=0;
	char str[101];
	int len1, len2;
	while(!f1.eof()){
		f1.getline(str,101);
		lette++;
		len1=strlen(str);
		rimuovi(str);
		len2=strlen(str);
		if(len1!=len2)
			modificate++;
		f2 << str << endl;
	}
	f1.close();
	f2.close();
	cout << "finito" << endl << "lette: " << lette << endl << "modificate: " << modificate;*/
	Data* A[100];
	int g=1;
	int m=1;
	int a=1;
	int k=0;
	Data speciale;
	speciale.a=1994;
	speciale.m=8;
	speciale.g=15;
	while(g!=0 || m!=0 || a!=0){
		cout << "inserire g,m,a: ";
		cin >> g >> m >> a;
		A[k]=new Data;
		A[k]->a=a;
		A[k]->m=m;
		A[k]->g=g;
		k++;
		if(ricerca(A,k,speciale)){
			cout << endl << "trovato";
			return 0;
		}
	}

	return 0;
}