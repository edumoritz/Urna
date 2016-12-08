#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SENHA 3326
struct candidato {
	char nome[20];
	int numero;
	int votos;
};
typedef candidato candidatos;
int apuracaoFUNC(int s);
int main(){
	const int t = 5;
	candidatos vet[t];
	int num = 0, escolhaA = 0, escolhaB = 0, escolhaC = 0, soma = 0, 
	igual = 0, votoBranco = 0, votoNulo = 0, eleitores = 1, somaV = 0;
	int i, j, x, k, y, a, b, auxA, auxB;
	char auxC[20];
	double media = 0;
	bool apuracao = true;
	
	for(i = 0; i < t;i++){
		printf("Candidato %d de %d: \n",i+1,t);
		printf("Digite o nome do candidato: \n");
		scanf("%s",&vet[i].nome);
		fflush(stdin);
		printf("Digite o numero do candidato: \n");
		scanf("%d",&vet[i].numero);
		fflush(stdin);
		vet[i].votos = 0;
		system("cls");
	}
	while(apuracao){
		printf("Eleitor %d\n\n",eleitores++);
		printf("Digite:\n1 - Votar\n2 - Apurar Votos\n");
		scanf("%d",&escolhaA);
		system("cls");
		switch(escolhaA){
		case 1:
			printf("1 - Votar em branco\n2 - Votar em Candidato\n");
			scanf("%d",&escolhaB);
			system("cls");
				switch(escolhaB){
				case 1:
					votoBranco++;
					printf("\n\n");
					printf("=========================================\n");
					printf("\tVoce votou em BRANCO!\n");
					printf("=========================================\n");
					printf("\n\n");
					system("pause");
					system("cls");
					break;
				case 2:
					printf("Digite o numero do candidato:\n");
					scanf("%d",&num);
						for(j = 0; j < t; j++){
							if(num == vet[j].numero){
								igual++;
							} 
						}
						if(igual == 0){
							votoNulo++;
							printf("\n\n");
							printf("=========================================\n");
							printf("\tVoce votou NULO!!\n");
							printf("=========================================\n");
							printf("\n\n");
							system("pause");
							system("cls");
						}
						igual = 0;
						for(x = 0; x < t; x++){
							if(num == vet[x].numero){
								printf("============================================\n");
								printf("\tVoce esta votando em %s \n\n",vet[x].nome);
								printf("1 - Confirmar\n2 - Corrigir\n");
								scanf("%d",&escolhaC);
								system("cls");
								switch(escolhaC){
								case 1:
									printf("\n\n");
									printf("=========================================\n");
									printf("=========================================\n");
									printf("\tVoce votou no %s \n",vet[x].nome);
									vet[x].votos += 1;
									printf("=========================================\n");
									printf("=========================================\n");
									printf("\n\n");
									soma += 1;
									system("pause");
									system("cls");
									break;
								case 2:
									eleitores--;
									x = t;
									break;
								default:
									printf("=========================================\n");
									printf("====Erro na escolha, tente novamente.====\n");
									printf("=========================================\n");
									system("pause");
									system("cls");
									eleitores--;
									x--;
									break;
								}							
							}
						}
					break;
				default:
					printf("=========================================\n");
					printf("====Erro na escolha, tente novamente.====\n");
					printf("=========================================\n");
					system("pause");
					system("cls");
					eleitores--;
					break;
				}
			
			break;
		case 2:
			if(apuracaoFUNC(SENHA) == 1){
				for(k = 0; k < t; k++){
					for(y = 0; y < t -1; y++){
						if(vet[y].votos < vet[y + 1].votos){
							auxA = vet[y].votos;
							auxB = vet[y].numero;
							strcpy(auxC, vet[y].nome);
							vet[y].votos = vet[y + 1].votos;
							vet[y].numero = vet[y + 1].numero;
							strcpy(vet[y].nome, vet[y + 1].nome);
							vet[y + 1].votos = auxA;
							vet[y + 1].numero = auxB;
							strcpy(vet[y + 1].nome, auxC);
						}
					}
				}
				media = (soma / t) + 1;
				printf("Candidatos:\n\n");
				for(a = 0; a < t; a++){
					printf("Nome...........: %s\n",vet[a].nome);
					printf("Numero.........: %d\n",vet[a].numero);
					printf("Votos..........: %d\n",vet[a].votos);
					printf("---------------------------------------\n");
					if(vet[a].votos > media){
						somaV += 1;
					}
				}
				printf("Votos Brancos.......: %d\n",votoBranco);
				printf("Votos Nulos.........: %d\n\n",votoNulo);
				system("pause");
				system("cls");
				if(somaV > 1){
					printf("\n\n");
					printf("================================================\n");
					printf("\tEleicoes teram o segundo turno.\n");
					printf("================================================\n");
					printf("\n\n");
					system("pause");
					system("cls");
					printf("\n\n\tCandidatos mais votados: \n\n");
				}
				for(b = 0; b < t; b++){
					if(vet[b].votos > media){
						if(somaV > 1){
							printf("\t%s\n",vet[b].nome);
						} else {
							printf("\n\n");
							printf("=========================================\n");
							printf("\tCandidato Vencedor: \n");
							printf("\t%s\n",vet[b].nome);
							printf("=========================================\n");
						}
					}
				}
				printf("\n\n");
				system("pause");
				system("cls");
				apuracao = false;
			} else {
				printf("\n\n");
				printf("=========================================\n");
				printf("\tSenha incorreta!!\n");
				printf("=========================================\n");
				printf("\n\n");
				system("pause");
				system("cls");
			}
			break;
		default:
			printf("=========================================\n");
			printf("====Erro na escolha, tente novamente.====\n");
			printf("=========================================\n");
			system("pause");
			system("cls");
			eleitores--;
			break;
		}
	}
		
	system("pause");
	return 0;
}
int apuracaoFUNC(int s){
	int senha = 0;
	printf("Digite a senha: \n");
	scanf("%d",&senha);
	system("cls");
	if(senha == s){
		return 1;
	} else {
		return 0;
	}
	
}
