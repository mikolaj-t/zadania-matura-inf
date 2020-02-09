#include <iostream>
#include <fstream>

//4.1 (256,8) (200, 400); 7852
//4.2 3.228, 3.1656, 3.1416

using namespace std;

int main(){
	fstream plik;
 	plik.open("punkty.txt");
	int s;
	int x, y;
	int ilosc;
	double tysiac,piectysiecy,dziesiectysiecy;
	for(int i=0; i<20000; i++){
		plik>>s;
		if(i%2 == 0){
			x=s;
		}else if(i%2 == 1){
			y=s;
			int jeden = x-200;
			int dwa = y-200;
			if(((jeden*jeden) + (dwa*dwa)) == 40000){
				cout<<"x "<<x<<" y "<<y<<endl;
				dziesiectysiecy++;
				if(i<2000){
					tysiac++;
				}
				if(i<10000){
					piectysiecy++;
				}
			}else if((jeden*jeden) + (dwa*dwa) < 40000){
				ilosc++;
				dziesiectysiecy++;
				if(i<2000){
					tysiac++;
				}
				if(i<10000){
					piectysiecy++;
				}
			}
		}
	}
	cout<<ilosc<<endl;
	double j_wynik = 4*(tysiac/1000);
	double p_wynik = 4*(piectysiecy/5000);
	double d_wynik = 4*(dziesiectysiecy/10000);
	cout<<"tysiac "<<j_wynik<<endl;
	cout<<"piec tysiecy "<<p_wynik<<endl;
	cout<<"calosc "<<d_wynik<<endl;
	return 0;
}


