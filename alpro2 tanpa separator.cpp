# Largest
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main (){
  struct {
    char maskapai[10]; 
    int jumlah_penerbangan; 
    char tujuan [50];
  }flight;

  FILE *PointerFile;
  PointerFile = fopen("flight data.txt","rt");
  fscanf (PointerFile, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
  int sum, sum_all;
  char current [10];

  if (feof(PointerFile)){
      cout<<"File Kosong,proses konsolidasi dibatalkan...!!!"<<endl;
  }
  else{
    //fscanf (PointerFile, "%s %d %s\n", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);
    sum_all = 0;
    sum = 0;
    strcpy(current, flight.maskapai);
    do{

      if(strcmp(flight.maskapai,current) == 0){
        sum += flight.jumlah_penerbangan;
      }else{
        cout<<"Jumlah Penerbangan Maskapai "<<current<<" "<<sum<<endl;
        sum = flight.jumlah_penerbangan;
        strcpy(current, flight.maskapai);
      }                                                             

      sum_all = sum_all + flight.jumlah_penerbangan;
      fscanf (PointerFile, "%s %d %s", flight.maskapai, &flight.jumlah_penerbangan, flight.tujuan);

    }while (!feof(PointerFile));

    cout<<"Jumlah Penerbangan Maskapai "<<current<<" "<<sum<<endl;
    cout<<"Jumlah Seluruh Penerbangan "<<sum_all<<" "<<endl;
  }

  fclose (PointerFile);
  return 0;
}

