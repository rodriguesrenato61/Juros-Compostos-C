#include <stdio.h>
#include <math.h>

float montante(float cap, float tax, float per){
	return (cap * pow(1 + tax/100, per));
}

float capital(float jur, float tax, float per){
	return (jur/(pow(1 + tax/100, per) - 1));
}

float taxa(float cap, float mont, float per){
	return ((100 * (pow(cap/mont, 1/per) - 1)) * (-1));
}

float periodo(float cap, float mont, float tax){
	return (log(cap/mont)/log(1 + tax/100) * (-1));
}

float convert_taxa(float tax, char med_entrada, char med_saida){
	float tax_diaria, tax_saida;
	
	switch(med_entrada){
	
		case 'a':
			tax_diaria = pow(1 + tax/100, 1/360);
		break;       
		case 'm':
			tax_diaria = pow(1 + tax/100, 1/30);
		break;
		case 'd':
			tax_diaria = pow(1 + tax/100, 1/1);
		break;
	}
	
	switch(med_saida){
        
		case 'a':
			tax_saida = pow(tax_diaria, 360);
		break;
		case 'm':
			tax_saida = pow(tax_diaria, 30);
		break;
		case 'd':
			tax_saida = pow(tax_diaria, 1);
		break;
    }
    
    return ((tax_saida - 1)*100);
}

int main(){
	float j, c, i, t, m, taxa_convert;
	int opc;
	char med_entrada, med_saida;
	
	printf("\n1 - Juros e Montante");
	printf("\n2 - Capital e Montante");
	printf("\n3 - Taxa e Montante");
	printf("\n4 - Periodo e Montante");
	printf("\n5 - Converter taxa");
	printf("\nOpcao: ");
	scanf("%i", &opc);
	
	switch(opc){
		case 1:
			printf("\nCapital: ");
			scanf("%f", &c);
			printf("\nTaxa: ");
			scanf("%f", &i);
			printf("Periodo: ");
			scanf("%f", &t);
    
			m = montante(c, i, t);
			j = m - c;
    
			printf("\nJuros: %.2f",j);
			printf("\nMontante: %.2f",m);
		break;
		case 2:
			printf("\nJuros: ");
			scanf("%f", &j);
			printf("\nTaxa: ");
			scanf("%f", &i);
			printf("Periodo: ");
			scanf("%f", &t);
    
			c = capital(j, i, t);
			m = c + j;
    
			printf("\nCapital: %.2f",c);
			printf("\nMontante: %.2f",m);
		break;
		case 3:
			printf("\nCapital: ");
			scanf("%f", &c);
			printf("\nJuros: ");
			scanf("%f", &j);
			printf("Periodo: ");
			scanf("%f", &t);
    
			m = c + j;
			i = taxa(c, m, t);
    
			printf("\nTaxa: %.2f",i);
			printf("\nMontante: %.2f",m);
		break;
		case 4:
			printf("\nCapital: ");
			scanf("%f", &c);
			printf("\nTaxa: ");
			scanf("%f", &i);
			printf("Juros: ");
			scanf("%f", &j);
    
			m = c + j;
			t = periodo(c, m, i);
    
			printf("\nPeriodo: %.2f",t);
			printf("\nMontante: %.2f",m);
		break;
		case 5:
			printf("\nTaxa: ");
			scanf("%f", &i);
			getchar();
			printf("\na - ao ano");
			printf("\nm - ao mes");
			printf("\nd - ao dia");
			printf("\nOpcao: ");
			scanf("%c", &med_entrada);
			
			printf("\nPeriodo: ");
			scanf("%f", &t);
			getchar();
			printf("\na - ao ano");
			printf("\nm - ao mes");
			printf("\nd - ao dia");
			printf("\nOpcao: ");
			scanf("%c", &med_saida);
			
		    tax_convert = 100 * (pow(1 + convert_taxa(i, med_entrada, med_saida)/100, t) - 1);
			
			printf("\n%.2f %% a.%c = %.2f %% em %.2f %c", i, med_entrada, taxa_convert, t, med_saida);
		break;
	}
	
	
	
	return 0;
}
