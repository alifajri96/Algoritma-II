#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


int main () {

	struct
	{
		char maskapai[10];
		int jumlah_penerbangan;
		char tujuan [50];
	}
	flight;

	
	int sum, sum_all;
	char separator[10] = "*00*";
	char current [10];
	char tujuan[10];
	FILE* penerbangan = fopen("flight data separator.txt", "rt");
	
	sum_all = 0;

	if(feof(penerbangan)) {
    	cout<<"File Kosong,proses konsolidasi dibatalkan...!!!"<<endl;
    }
   	else {
   		
   		
  	fscanf (penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
  	
  	
  	do {
  		while(!feof(penerbangan) && strcmp(flight.maskapai,separator)==0) {
  			fscanf (penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
		}
		
  		sum = 0;
   		strcpy(current, flight.maskapai);
   		
	 
		while (!feof(penerbangan) && strcmp(flight.maskapai,separator)!=0) {
			sum += flight.jumlah_penerbangan;
		fscanf (penerbangan, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
		}
		cout<<"Jumlah penerbangan maskapai "<<current<<" "<<sum<<endl;
		sum_all+=sum;	 
	  } while (!feof(penerbangan));
	
	cout<<"Jumlah Seluruh Penerbangan " <<sum_all<<" "<<endl;
	} 
	fclose(penerbangan);
	return 0;
}
