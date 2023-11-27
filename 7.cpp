#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct S{
	float A;
	char B;
};

int COINCIDENTI(char *A1, char* A2, int d1, int d2){
	int minimo=min(d1,d2);
	int counter=0;
	for(int i=0;i<minimo;i++)
		if(A1[i]==A2[i])
			counter++;
	return counter;
}

int main(){
	/*ifstream f1;
	char F[85];
	cout << "inserire nome file: ";
	cin.getline(F,81);
	f1.open(strcat(F,".txt"));
	if(f1.fail()){
		cout << endl << "file non esistente";
		return 1;
	}
	char P[41];
	int max=0;
	cout << endl << "inserire parola P: ";
	cin.getline(P,41);
	int len1=strlen(P);
	bool trovato=false;
	char ris[41];
	while(!f1.eof()){
		char word[41];
		f1 >> word;
		int c=COINCIDENTI(word,P,strlen(word),len1);
		if(c>max){
			trovato=true;
			max=c;
			strcpy(ris,word);
		}
	}
	if(!trovato)
		cout << endl << "non ci sono parole con almeno una coincidenza";
	else{
		cout << endl << "parola: " << ris << endl << "coincidenze: " << max;
	}
	f1.close();*/
	S T[100];
	int counter=0;
	char mode='d';
	while(mode!='c' && counter<100){
		cout << endl << "a.\tinserisci"
		<< endl << "b.\tstampa"
		<< endl << "c.\tsmetti" << endl;
		cin >> mode;
		switch(mode){
			case 'a':
				cout << endl << "inserire campo A: ";
				cin >> T[counter].A;
				cout << endl << "inserire campo B: ";
				cin >> T[counter].B;
				counter++;
				break;
			case 'b':
				cout << endl;
				for(int i=0;i<counter;i++)
					cout << endl << T[i].A << " " << T[i].B;
				break;
			case 'c':
				cout << endl << "fine";
				break;
			default:
				cout << endl << "non esiste questa possibilita'";
				break;
		}
	}
	if(counter==100)
		cout << endl << "il programma si arresta in quanto e' finito lo spazio disponibile";
	return 0;
}