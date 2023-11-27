#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct S{
	char Nome[65];
	int Num;
};

void inverti(char* A, int n){
	char tmp;
	for(int i=0;i<n/2;i++){
		tmp=A[i];
		A[i]=A[n-i-1];
		A[n-i-1]=tmp;
	}
}

int main(){
	/*char parola[101];
	cout << "parola: ";
	cin.getline(parola,101);
	ifstream f1;
	f1.open(strcat(parola,".txt"));
	ofstream f2;
	char prefisso[200]="inverso di ";
	f2.open(strcat(prefisso,parola));
	char c;
	int i;
	char v[1000];
	while(f1 >> c){
		v[i]=c;
		cout << v[i];
		i++;
	}
	cout << endl;
	inverti(v,i);
	for(int j=0;j<i;j++){
		f2 << v[j];
		cout << v[j];
	}*/
	int mode=1;
	S T[100];
	int k=0;
	while(mode!=4){
		cout << endl << " selezionare modalita':"
		<< endl << "1: inserisci"
		<< endl << "2: ricerca"
		<< endl << "3: salva"
		<< endl << "4: esci";
		cin >> mode;
		cin.ignore();
		switch(mode){
			case 1:{
				int n;
				char stringa[65];
				cout << endl << "inserisci stringa: ";
				cin.getline(stringa,65);
				cout << endl << "inserisci n: ";
				cin >> n;
				cin.ignore();
				bool full=true;
				for(int i=0;i<100;i++)
					if(i==k && k <100){
						strcpy(T[i].Nome,stringa);
						T[i].Num=n;
						k++;
						full=false;
						break;
					}
				if(full)
					cout << endl << "pieno";
				break;
			}
			case 2:{
				char N[65];
				cout << "inserisci stringa: ";
				cin.getline(N,65);
				bool notfound=true;
				for(int i=0;i<100;i++)
					if(strcmp(T[i].Nome,N)==0){
						notfound=false;
						cout << endl << "elemento: " << T[i].Num;
					}
				if(notfound)
					cout << endl << "non c'e quello che cerchi ";
				break;
			}
			case 3:{
				ofstream salva;
				salva.open("dati_salvati.txt");
				for(int i=0;i<k;i++){
					cout << T[i].Nome << " " << T[i].Num << "\n";
					salva << T[i].Nome << " " << T[i].Num << "\n";
				}
				cout << endl << "salvato";
				break;
			}
			case 4:{
				cout << endl << "ciao";
				break;
			}
			default:{
				cout << "non esiste questa modalita'";
				break;
			}
		}
	}
	return 0;
}