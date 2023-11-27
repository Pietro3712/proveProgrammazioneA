#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
// versione difficile senza usare array ausiliari (vedere in basso SIMILI2)

struct struttura{
	int O1;
	int O2;
	int RIS;
	char OP[101];
};

int SIMILI(int* A1, int* A2, int d1, int d2){
	int counter=0;
	int i=0;
	int j=0;
	if(d2>=d1){
		while(i<d2 && j<d1){
			while(A2[i]==0)
				i++;
			while(A1[j]==0)
				j++;
			if(i<d2 && j<d1 && (A1[j++]==A2[i++]))
				counter++;
			else return -1;
		}
	for(int i=0;i<d2;i++){
		bool esito=false;
		if(A2[i]!=0){
			for(int j=0;j<d1;j++){
				if(A2[i]==A1[j]){
				esito=true;
				break;
				}
			}
			if(!esito)
				return -1;
		}
	}
	}
	else{
		while(i<d1 && j<d2){
			while(A2[j]==0)
				j++;
			while(A1[i]==0)
				i++;
			if(i<d1 && j<d2 && (A1[i++]==A2[j++]))
				counter++;
			else return -1;
		}
		for(int i=0;i<d1;i++){
			bool esito=false;
			if(A1[i]!=0){
				for(int j=0;j<d2;j++){
					if(A1[i]==A2[j]){
					esito=true;
					break;
					}
				}
				if(!esito)
					return -1;
			}
		}
	}
	return counter;
}
// versione piu' semplice senza usare array ausiliari
int SIMILI2(int *A1, int* A2, int d1, int d2){
	int Aus1[d1];
	int Aus2[d2];
	int k1=0;
	int k2=0;
	for(int i=0;i<d1;i++){
		if(A1[i]!=0)
			Aus1[k1++]=A1[i];
	}
	for(int i=0;i<d2;i++){
		if(A2[i]!=0)
			Aus2[k2++]=A2[i];
	}
	if(k1==k2){
		for(int i=0;i<k1;i++)
			if(Aus1[i]!=Aus2[i])
				return -1;
	}
	else return -1;
	return k1;
}

int fatt(int n){
	int fattor = 1;
    for (int i = 1; i <= n; i++)
        fattor *= i;
    return fattor;
}

void VALUTA(struttura &S){
		if(strcmp(S.OP,"sum")==0)
			S.RIS=S.O1+S.O2;
		else if(strcmp(S.OP,"sub")==0)
			S.RIS=S.O1-S.O2;
		else if(strcmp(S.OP,"mul")==0)
			S.RIS=S.O1*S.O2;
		else if(strcmp(S.OP,"div")==0)
			S.RIS=S.O1/S.O2;
		else if(strcmp(S.OP,"**")==0)
			S.RIS=S.O1*S.O1;
		else if(strcmp(S.OP,"fatt")==0)
			S.RIS=fatt(S.O1);
		else cout << endl << "operatore inesistente";
}

int main(){
	/*int n;
	do{
	cout << "inserire n: (da 1 a 100) ";
	cin >> n;
	cin.ignore();
	} while(n<1 || n>100);
	char f[81];
	cout << endl << "ora inserire nome file: ";
	cin.getline(f,81);
	ifstream f1;
	f1.open(strcat(f,".txt"));
	if(f1.fail())
		return -1;
	int Arr[100];
	int k=0;
	int counter2=0;
	while(!f1.eof()){
		int e;
		f1 >> e;
		Arr[k]=e;
		if(Arr[k]==0)
			counter2++;
		k++;
	}
	bool risposta=0;
	do{
		int T[n];
		for(int i=0;i<n;i++){
			cout << endl << "inserire in pos: " << i <<" ";
			cin >> T[i];
			cin.ignore();
		}
		int c=SIMILI2(T,Arr,n,k);
		if(c==-1)
			cout << endl << "esito negativo";
		else{
			cout << endl << "esito positivo"
			<< endl << "non-zero: " << c 
			<< endl << "zero nel file: " << counter2;
		}
		cout << endl << "fornire altra sequenza? [0/1] ";
		cin >> risposta;
	} while(risposta==1);*/
	struttura S;
	S.O1=4;
	S.O2=3;
	S.RIS=0;
	strcpy(S.OP,"fatt");
	VALUTA(S);
	cout << endl << "ris: " << S.RIS;
	return 0;
}