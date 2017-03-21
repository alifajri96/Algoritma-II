#include <stdio.h>

int iteration_fibonacci(int n)
{
	int a = 0, b= 1 ,c,loop, sum=0;
	for(loop=0;loop<n;loop++)
	{
		//jika variabel loop mulai tidak dari angka 1 maka loop = 0;
		if (loop <= 1)
		{
			c = loop;
		}
		else {
		//c = a + b;
		c=a+b;
		a=b;
		b=c;
		
	}
	//cetak c
	printf("%d  ",c);
	//jumlahkan c
	sum += c;
	}
	printf("\nJumlah dari deretan angka fibonacci di atas adalah %d", sum);
	return a;
}

int main()
{
int i;
int angka;
printf("Masukan angka nya ");
scanf("%d", &angka);
	
iteration_fibonacci(angka);
}
