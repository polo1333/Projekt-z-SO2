#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int a, b, x;
	printf("a = ");
	scanf("%d",&a);
	printf("b = ");
	scanf("%d",&b);
	printf("\n");

	if (a < b) {
		x = a;
		a = b;
		b = x;
	}
    x = log10(a) + 1;

	//  tebPrze = zbiera dziesi¹tki
	int tabA[x], tabB[x], Wynik[x+1], tabPrze[x], i;

	for (i=0; i<x; i++) {
		tabA[i] = a%10;
		tabB[i] = b%10;
        a = a/10;
		b = b/10;

		if (i==0) {
			Wynik[i] = tabA[i] + tabB[i];
		} else {
			Wynik[i] = tabA[i] + tabB[i] + tabPrze[i-1];
		}

		if (Wynik[i]>9) {
			Wynik[i] = Wynik[i] - 10;
			tabPrze[i] = 1;
		}
		else {
			tabPrze[i] = 0;
		}
	}

	Wynik[x] = tabPrze[x-1];
    //wypisywanie dziesiatek
    printf(" ");
	for (i = x-1; i>=0; i--) {
		if (tabPrze[i]) {
			printf("%d",tabPrze[i]);}
        else {
			printf(" ");
		}
	}

	printf("\n  ");
    for (i = x-1; i>=0; i--) {
        printf("%d",tabA[i]);}

	printf("\n");
	printf("+ ");
    i = x-1;

	while (tabB[i]==0) {
		printf(" ");
		i--;
	}
	for (i; i>=0; i--) {
		printf("%d",tabB[i]);}

	printf("\n");
	for (i=0; i<x+2; i++) {
		printf("-");}

	printf("\n ");
	if (Wynik[x]) {
		printf("%d",Wynik[x]);}
	else {
		printf(" ");
	}
	for (i = x-1; i>=0; i--) {
		printf("%d",Wynik[i]);
	}
	return 0;
}
