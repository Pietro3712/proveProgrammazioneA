#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct S{
	char c;
	int x1;
	int x2;
	int x3;
	int x4;
	int x5;
};

int compatta(int* A, int n, int* B){
	int counter=0;
	int k1=0;
	int k2=0;
	int i=0;
	while(i<n){
		if(A[i]==1){
			while(A[i]==1 && i<n){
				k1++;
				i++;
			}
			B[counter++]=k1;
			k1=0;
		}
		else{
			while(A[i]==0 && i<n){
				k2++;
				i++;
			}
			B[counter++]=-k2;
			k2=0;
		}
	}
	return counter;
}

void vocali(S &V){
	if(V.c=='a' || V.c=='A' )
		V.x1++;
	else if(V.c=='e' || V.c=='E' )
		V.x2++;
	else if(V.c=='i' || V.c=='I' )
		V.x3++;
	else if(V.c=='o' || V.c=='O' )
		V.x4++;
	else if(V.c=='u' || V.c=='U' )
		V.x5++;
}

int main(){
	char nomefile[101];
	cout << "inserire nome file: ";
	cin.getline(nomefile,101);
	char copia[101];
	strcpy(copia,nomefile);
	int bin[1000];
	ifstream f1;
	f1.open(strcat(nomefile,".txt"));
	int counter=0;
	while(!f1.eof()){
		f1 >> bin[counter];
		if(bin[counter]!=1 && bin[counter]!=0){
			cout << endl << "errore";
			return 1;
		}
		counter++;
	}
	f1.close();
	int ris[1000];
	int k=compatta(bin,counter,ris);
	ofstream f2;
	f2.open(strcat(copia,".cmp.txt"));
	for(int i=0;i<k;i++)
		f2 << ris[i] << endl;
	f2.close();
	S D;
	D.x1=0;
	D.x2=0;
	D.x3=0;
	D.x4=0;
	D.x5=0;
	char c='a';
	int counter=0;
	while(c!='.'){
		cout << endl << "inserire un carattere: ";
		cin >> c;
		if(c!= '.' && c!=' ' && c!='\n'){
			D.c=c;
			vocali(D);
			counter++;
		}
	}
	cout << endl;
	cout << endl << "pecentuale vocale a: " << (float)D.x1/counter*100 << " % ";
	cout << endl << "pecentuale vocale e: " << (float)D.x2/counter*100 << " % ";
	cout << endl << "pecentuale vocale i: " << (float)D.x3/counter*100 << " % ";
	cout << endl << "pecentuale vocale o: " << (float)D.x4/counter*100 << " % ";
	cout << endl << "pecentuale vocale u: " << (float)D.x5/counter*100 << " % ";
	return 0;
}