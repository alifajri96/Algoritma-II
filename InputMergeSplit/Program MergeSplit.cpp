#include <stdio.h>
#include <string.h>


main()
{
FILE *Bus, *BusSplit, *BusMerge;

struct{
	char Nama[30];
	char Tujuan[50];
	int Harga;
}Bis;


	char lagi;
	int pil;
	
	do {
		printf("File \n1. Input\n2. Split\n3. Merge\n Pilih : ");
		scanf("%d", &pil);
		switch(pil)
		{
			case 1:
				{
					Bus = fopen("Bus.txt", "a");
					gets(Bis.Nama);
					printf("Nama Bus : ");
					gets(Bis.Nama);
					printf("Tujuan : ");
					gets(Bis.Tujuan);
					printf("Harga");
					scanf("%d", &Bis.Harga);
					fprintf(Bus, "%s %s %d\n", Bis.Nama, Bis.Tujuan, Bis.Harga);
					fclose(Bus);
					break;
				}
			
			case 2:
				{
					char cari[50];
					printf("Pisahkan berdasarkan nama bis : ");
					scanf("%s", &cari);
					Bus = fopen("Bus.txt", "r");
					BusSplit = fopen("Bus Split.txt", "a");
					while (!feof(Bus)){
						fscanf(Bus, "%s %s %d", Bis.Nama, Bis.Tujuan, &Bis.Harga);
						if(strcmp(Bis.Nama, cari)==0){
							fprintf(BusSplit, "%s %s %d", Bis.Nama, Bis.Tujuan, Bis.Harga);
						}
					}
					fclose(Bus);
					fclose(BusSplit);
					break;
				}
			
			case 3:
				{
					Bus = fopen("Bus 1.txt", "r");
					BusMerge = fopen("Bus Merge.txt","a");
					
					while(!feof(Bus)){
						fscanf(Bus, "%s %s %d", Bis.Nama, Bis.Tujuan, &Bis.Harga);
						fprintf(BusMerge,"%s %s %d", Bis.Nama, Bis.Tujuan, Bis.Harga);
					}
					fprintf(BusMerge,"\n");
					fclose(Bus);
					
					Bus = fopen("Bus 2.txt", "r");
					
					while(!feof(Bus)){
					fscanf(Bus, "%s %s %d", Bis.Nama, Bis.Tujuan, &Bis.Harga);
						fprintf(BusMerge,"%s %s %d", Bis.Nama, Bis.Tujuan, Bis.Harga);
					}
					fclose(Bus);
					fclose(BusMerge);
					break;
				}
		}
		printf("Lagi ?");
		scanf("%c", lagi);
	}while (lagi != 'n');
	}
