#include <stdio.h>
#include <math.h> /*importando a biblioteca math.h para uso das funções pow(potenciação)
e log(logaritmo)*/


/*função para calcular o montante utilizando o capital, taxa e período
como parâmetros de entrada*/
float montante(float cap, float tax, float per){
	return (cap * pow(1 + tax/100, per));
}

/*função para calcular o capital utilizando os juros, a taxa e o período
como parâmetros de entrada*/
float capital(float jur, float tax, float per){
	return (jur/(pow(1 + tax/100, per) - 1));
}

/*função para calcular a taxa utilizando o capital, o montante e o período
como parâmetros de entrada*/
float taxa(float cap, float mont, float per){
	return ((100 * (pow(cap/mont, 1/per) - 1)) * (-1));
}

/*função para calcular o período utilizando o capital, o montante e a taxa
como parâmetros de entrada*/
float periodo(float cap, float mont, float tax){
	return (log(cap/mont)/log(1 + tax/100) * (-1));
}

/*função para fazer a conversão de taxa em uma medida de tempo para a taxa em
outra medida de tempo. Utilizando a taxa, sua medida de tempo e a medida a qual
essa taxa será convertida*/
double convert_taxa(float tax, char med_entrada, char med_saida){
	double tax_diaria, tax_saida;
/*tax: taxa a ser convertida
med_entrada: medida da taxa a ser convertida
med_saida: medida da taxa convertida
tax_diaria: recebe a taxa convertida medida em dias
tax_saida: recebe a taxa convertida na medida de saída*/
    
	
	switch(med_entrada){
	
		case 'a':/*caso a taxa for medida em anos ela será convertida em taxa diária*/
			tax_diaria = pow(1 + (double)tax/100, (double)1/360);
		break;       
		case 'm':/*caso a taxa for medida em meses ela será convertida em taxa diária*/
			tax_diaria = pow(1 + (double)tax/100, (double)1/30);
		break;
		case 'd':/*caso a taxa for medida em dias ela será convertida em taxa diária*/
			tax_diaria = pow(1 + (double)tax/100, 1/1);
		break;
	}
	
	switch(med_saida){
        
		case 'a':/*caso a taxa convertida for medida em anos a taxa diária será convertida em taxa anual*/
			tax_saida = pow(tax_diaria, 360);
		break;
		case 'm':/*caso a taxa convertida for medida em meses a taxa diária será convertida em taxa mensal*/
			tax_saida = pow(tax_diaria, 30);
		break;
		case 'd':/*caso a taxa convertida for medida em dias a taxa diária será convertida em taxa diária*/
			tax_saida = pow(tax_diaria, 1);
		break;
    }
    
    return ((tax_saida - 1)*100);/*retornando taxa convertida*/
}

int main(){
	float j, c, i, t, m, taxa_convert;
	int opc;
	char med_entrada, med_saida;
/*j: juros, c: capital, i: taxa, t: período, m: montante e taxa_convert: taxa convertida
opc: número da opção a ser escolhida
med_entrada: medida de tempo da taxa a ser convertida
med_saida: medida de tempo da taxa convertida*/
	
	printf("\n1 - Juros e Montante");
	printf("\n2 - Capital e Montante");
	printf("\n3 - Taxa e Montante");
	printf("\n4 - Periodo e Montante");
	printf("\n5 - Converter taxa");
	printf("\nOpcao: ");
	scanf("%i", &opc);
	
	switch(opc){
		case 1:/*caso a opção digitada for 1 os juros e montante serão calculados*/
			printf("\nCapital: ");
			scanf("%f", &c);
			printf("\nTaxa: ");
			scanf("%f", &i);
			getchar();/*limpando buffer do teclado*/
			printf("\na - ao ano\nm - ao mes\nd - ao dia\nOpcao: ");
			scanf("%c", &med_entrada);
			printf("\nPeriodo: ");
			scanf("%f", &t);
			getchar();/*limpando buffer do teclado*/
			printf("\na - anos\nm - meses\nd - dias\nOpcao: ");
			scanf("%c", &med_saida);
			
			i = convert_taxa(i, med_entrada, med_saida);
			m = montante(c, i, t);/*calculando montante*/
			j = m - c;/*calculando juros*/
    
			printf("\nJuros: %8.10f",j);
			printf("\nMontante: %8.10f",m);
		break;
		case 2:/*caso a opção digitada for 2 o capital e montante serão calculados*/
			printf("\nJuros: ");
			scanf("%f", &j);
			printf("\nTaxa: ");
			scanf("%f", &i);
			getchar();/*limpando buffer do teclado*/
			printf("\na - ao ano\nm - ao mes\nd - ao dia\nOpcao: ");
			scanf("%c", &med_entrada);
			printf("\nPeriodo: ");
			scanf("%f", &t);
			getchar();/*limpando buffer do teclado*/
			printf("\na - anos\nm - meses\nd - dias\nOpcao: ");
			scanf("%c", &med_saida);
			
			i = convert_taxa(i, med_entrada, med_saida);
    
			c = capital(j, i, t);/*calculando capital*/
			m = c + j;/*calculando montante*/
    
			printf("\nCapital: %8.10f",c);
			printf("\nMontante: %8.10f",m);
		break;
		case 3:/*caso a opção digitada for 3 a taxa e o montante serão calculados*/
			printf("\nCapital: ");
			scanf("%f", &c);
			printf("\nJuros: ");
			scanf("%f", &j);
			printf("Periodo: ");
			scanf("%f", &t);
    
			m = c + j;/*calculando o montante*/
			i = taxa(c, m, t);/*calculando a taxa*/
    
			printf("\nTaxa: %8.10f",i);
			printf("\nMontante: %8.10f",m);
		break;
		case 4:/*caso a opção digitada for 4 o período e o montante serão calculados*/
			printf("\nCapital: ");
			scanf("%f", &c);
			printf("\nTaxa: ");
			scanf("%f", &i);
			printf("Juros: ");
			scanf("%f", &j);
    
			m = c + j;/*calculando o montante*/
			t = periodo(c, m, i);/*calculando o período*/
    
			printf("\nPeriodo: %8.10f",t);
			printf("\nMontante: %8.10f",m);
		break;
		case 5:/*caso a opção digitada for 5 a taxa será convertida*/
			printf("\nTaxa: ");
			scanf("%f", &i);
			getchar();/*limpando buffer do teclado*/
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
			
		    taxa_convert = 100 * (pow(1 + convert_taxa(i, med_entrada, med_saida)/100, t) - 1);/*convertendo a taxa*/
			
			printf("\n%.2f %% a.%c = %8.10f %% em %.2f %c", i, med_entrada, taxa_convert, t, med_saida);
		break;
	}
	
	
	
	return 0;
}
