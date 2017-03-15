#include <stdio.h>
#include <string.h>

int main()
{
	struct {
		char prodi[3];
		char nama[100];
		char nilai[3];
	} rekaman;
	
	//pembuatan file arsipmatkul dan arsipmatkulupdate
	FILE *arsipMatkul;
	FILE *arsipMatkulUpdate;
	
	//membaca ArsipMatkul.dat
	arsipMatkul = fopen("ArsipMatkul.dat","r");
	//menulis ArsipMatkulUpdate.dat
	arsipMatkulUpdate = fopen("ArsipMatkulUpdate.dat","w");
	
	//membaca File ArsipMatkul.dat
	fscanf(arsipMatkul, "%s %s %s\n", &rekaman.prodi, &rekaman.nama, &rekaman.nilai);
	
	do {
		//jika prodi "IF" dan nama = "MhsE"
		if((strcmp(rekaman.prodi, "IF") == 0) && (strcmp(rekaman.nama, "MhsE") == 0))
		{
			//mengganti nilai menjadi 80
			strcpy(rekaman.nilai,"80");
		}
		//jika prodi IF" dan nama = "MhsJ"
		if((strcmp(rekaman.prodi, "IF") == 0) && (strcmp(rekaman.nama, "MhsJ") == 0))
		{
			//mengganti nilai menjadi 80
			strcpy(rekaman.nilai,"80");
		}
		//menulis data ke file ArsipMatkulUpdate.dat
		fprintf(arsipMatkulUpdate, "%s %s %s\n", rekaman.prodi, rekaman.nama, rekaman.nilai);
		
		//membaca data selanjutnya
		fscanf(arsipMatkul, "%s %s %s\n", &rekaman.prodi, &rekaman.nama, &rekaman.nilai);
		
	}while(!feof(arsipMatkul)); //proses looping berhenti jika file sudah selesai terbaca
	
	printf("Success Update"); //menampilkan pesan success update
	
	fclose(arsipMatkul);
	fclose(arsipMatkulUpdate);

	return 0;
}
