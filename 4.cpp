#include <iostream>
#include <cstring>
using namespace std;
struct struttura{
	int A;
	char B[51];
	bool c;
};

int RICERCA_VAL(struttura *Tab, int n, int h){
	for(int i=0;i<n;i++)
		if(Tab[i].A==h && Tab[i].c==1)
			return i;
	return -1;
}
int RICERCA_STR(struttura *Tab, int n, char *r){
	for(int i=0;i<n;i++)
		if(strcmp(Tab[i].B,r)==0 && Tab[i].c==1)
			return i;
	return -1;
}

int main(){
	struttura T[100];
	int mode=0;
	for(int i=0;i<100;i++)		// come suggerito
		T[i].c=0;
	int counter=0;
	do{
		cout << endl << endl << "1: ricerca per valore"
		<< endl << "2: ricerca per nome"
		<< endl << "3: inserimento"
		<< endl << "4: eliminazione"
		<< endl << "5: stampa"
		<< endl << "6: esci" << endl;
		cin >> mode;
		cin.ignore();
		switch(mode){
			case 1:{
				int x;
				cout << "inserire un intero: ";
				cin >> x;
				cin.ignore();
				int ris=RICERCA_VAL(T, counter, x);
				if(ris==-1)
					cout << endl << "non trovato";
				else
					for(int i=0;i<counter;i++)
						if(ris==i)
							cout << endl << "stringa: " << T[i].B;
				break;
				}
			case 2:{
				char s[51];
				cout << endl << "inserire stringa: ";
				cin.getline(s,51);
				int ris=RICERCA_STR(T,counter,s);
				if(ris==-1)
					cout << endl << "non trovato";
				else
					for(int i=0;i<counter;i++)
						if(ris==i)
							cout << endl << "valore: " << T[i].A;
				break;
				}
			case 3:{
				char s[51];
				int x;
				cout << endl << "inserire stringa: ";
				cin.getline(s,51);
				cout << endl << "inserire x: ";
				cin >> x;
				cin.ignore();
				bool possible=false;
				for(int i=0;i<100;i++)
					if(T[i].c==0){
						T[i].A=x;
						strcpy(T[i].B,s);
						T[i].c=1;
						counter++;
						possible=true;
						cout << endl << "inserito";
						break;
					}
				if(!possible)
					cout << endl << "non sono riuscito a inserire quello che dovevo";
				break;
			}
			case 4:{
				int x;
				cout << "inserire x: ";
				cin >> x;
				cin.ignore();
				int ris=RICERCA_VAL(T, counter, x);
				if(ris==-1)
					cout << endl << "tale elemento non esiste";
				else
					for(int i=0;i<counter;i++)
						if(ris==i){
							T[i].c=0;
							cout << endl << "eliminato";
						}
				break;
			}
			case 5:{
				cout << endl << "stampa: ";
				for(int i=0;i<counter;i++)
					if(T[i].c==1)
						cout << endl << T[i].B << " " << T[i].A;
				break;
				}
			case 6:{
				cout << endl << "salute";
				break;
			}
			default:{
				cout << endl << "non esiste quella modalita'";
			}
		}
	} while(mode !=6);
	return 0;
}