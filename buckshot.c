#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define tamborDaArma 6
#define danoBala 1
#define vidaMax 4

int   comeco, maxBalas, qtdBalas, botTiro, balasVerdadeiras, vidaPlayer, vidaBot, rodada;
float chanceDeAcerto;
char  respostaTiro;

void aleatoriezar() {
	srand(time(0));
	maxBalas = tamborDaArma;
	if (rodada != 1) comeco = rand() % 2;
	qtdBalas = rand() % maxBalas + 1;
	balasVerdadeiras = rand() % qtdBalas;
	chanceDeAcerto   = 100.0 / maxBalas * balasVerdadeiras;
}

void quemComeca() {
	switch (comeco) {
	case 0:
		printf("Sua vez. ");
		sleep(2);
		printf("Deseja dar o tiro em si ou no BOT?(s/b): ");
		scanf("%c", &respostaTiro);

		if (respostaTiro != 's' && respostaTiro != 'b') exit(0);

		if (respostaTiro == 's') {
			if (rand() % 100 < chanceDeAcerto) {
				qtdBalas--;
				balasVerdadeiras--;
				vidaPlayer = vidaPlayer - danoBala;
				chanceDeAcerto = (100.0 / maxBalas) * balasVerdadeiras;
				printf("Voce foi atingido!\n");
				respostaTiro = 'b';
			} else {
				chanceDeAcerto = (balasVerdadeiras > 0) ? (100.0 / maxBalas) * balasVerdadeiras : 0;
				printf("Estava vazio.\n");
			}
		} else if (respostaTiro == 'b') {
			if (rand() % 100 < chanceDeAcerto) {
				qtdBalas--;
				balasVerdadeiras--;
				vidaBot  = vidaBot  - danoBala;
				chanceDeAcerto = (100.0 / maxBalas) * balasVerdadeiras;
				printf("Voce o acertou!\n");
				respostaTiro = 'b';
			} else {
				chanceDeAcerto = (balasVerdadeiras > 0) ? (100.0 / maxBalas) * balasVerdadeiras : 0;
				printf("Estava vazio.\n");
			}
		}
		botTiro = 0;
		break;
	case 1:
		printf("Vez do BOT.");
		sleep(2);

		if (botTiro == 0) {
			printf("Ele tentou atirar em si");
			sleep(2);
			if (rand() % 100 < chanceDeAcerto) {
				qtdBalas--;
				balasVerdadeiras--;
				vidaBot  = vidaBot  - danoBala;
				chanceDeAcerto = (100.0 / maxBalas) * balasVerdadeiras;
				printf(" e acertou!\n");
				botTiro = 1;
			} else {
				chanceDeAcerto = (balasVerdadeiras > 0.0) ? (100.0 / maxBalas) * balasVerdadeiras : 0;
				printf(" mas estava vazio.\n");
			}
		} else {
			printf("Ele tentou atirar em voce");
			sleep(2);
			if (rand() % 100 < chanceDeAcerto) {
				qtdBalas--;
				balasVerdadeiras--;
				vidaPlayer = vidaPlayer - danoBala;
				chanceDeAcerto = (100.0 / maxBalas) * balasVerdadeiras;
				printf(" e acertou!\n");
				botTiro = 1;
			} else {
				chanceDeAcerto = (balasVerdadeiras > 0.0) ? (100.0 / maxBalas) * balasVerdadeiras : 0;
				printf(" mas estava vazio.\n");
			}
		}
		break;
	}
}

void jogo() {
	do {
		fflush(stdin);
		aleatoriezar();
		system("cls || clear");

		printf("\tSua vida = %i | Vida do BOT = %i\n", vidaPlayer, vidaBot);
		sleep(1);
		printf("\tA arma foi carregada com %i bala(s).\n\n", qtdBalas);
		sleep(2);

		for (int i = 0; i < tamborDaArma; i++) {
			fflush(stdin);
			botTiro = rand() % 2;
			respostaTiro = ' ';
			maxBalas--;
			quemComeca();
			if (respostaTiro == 'b' || botTiro == 1) break;
		}
		comeco = (comeco == 1) ? 0 : 1;
		for (int i = 0; i < tamborDaArma; i++) {
			fflush(stdin);
			botTiro = rand() % 2;
			respostaTiro = ' ';
			maxBalas--;
			quemComeca();
			if (respostaTiro == 'b' || botTiro == 1) break;
		}

		sleep(2);
		printf("A rodada terminou.\n\n");
		system("pause");
		rodada++;

	} while (vidaPlayer > 0 && vidaBot > 0);
}

int main() {
	char respostaMoeda;
	vidaPlayer = vidaMax;
	vidaBot    = vidaMax;
	rodada     = 1;

	system("cls || clear");

	printf("Jogar moeda para iniciar?(s/n): ");
	scanf("%c", &respostaMoeda);

	if (respostaMoeda != 's' && respostaMoeda != 'n') return 0;

	if (respostaMoeda == 'n') comeco = 1;
	else comeco = rand() % 2;
	jogo();

	if (vidaBot > vidaPlayer) printf("O BOT venceu!\n\n");
	else printf("Voce venceu!\n\n");

	return 0;
}