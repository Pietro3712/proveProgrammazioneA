#include <iostream>
#include <cstring>
using namespace std;

struct struttura{
	int A;
	int B;
};
int coincidenti(char *A, char *B, int n, int m){
	int counter=0;
	int max;
	int min;
	if(n>m)
		min=m;
	else min=n;
	for(int i=0;i<min;i++)
		if(A[i]==B[i])
			counter++;
	return counter;
}
int main(){
	/*char P[51];
	cout << "inserire P: ";
	cin >> P;
	char ris[51];
	int len1=strlen(P);
	int max=0;
	while(1){
		cout << "inserire parola: ";
		char parola[51];
		cin >> parola;
		if(parola[0]=='.')
			break;
		int len2=strlen(parola);
		int c=coincidenti(P,parola,len1,len2);
		if(c>max){
			max=c;
			strcpy(ris,parola);
		}
	}
	cout << endl << ris;*/
	struttura M[4][4];
	int risposta=0;
	int somma=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			cout << endl << "vuoi inserire un valore? [1/0] ";
			cin >> risposta;
			if(risposta==1){
				int k;
				cout << endl << "inserisci valore k: ";
				cin >> k;
				M[i][j].A=k;
				somma+=k;
				M[i][j].B=1;
			}
			else
				M[i][j].B=0;
		}
		cout << endl << "somma: " << somma;
	return 0;
}