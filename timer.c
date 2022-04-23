#include <stdio.h>
#ifdef WIN32
#include<Windows.h>
#else
#include <unistd.h>
#endif

int main () {
	int jj, mm, dd;
	int sama;
	int initial = 1;
	
	printf("Masukkan waktunya (formatnya jam menit detik) : ");
	scanf("%d %d %d", &jj, &mm, &dd);

	if (jj > 12 || mm > 60 || dd > 60 || jj < 0 || mm < 0 || dd < 0) {
		printf ("Input yang kamu masukkan tidak valid.\n");
	}

	while (initial == 1) {
		dd--;

		if (dd < 0 && mm != 0) {
			dd = 59;
			mm--;
		}

		if (dd < 0 && mm >= 0 && jj != 0) {
			dd = 59;
			mm = 59;
			jj--;
		}
	
		if (dd == 0 && mm == 0 && jj == 0) {
			printf("Time's up.\n");
			break;
		}

		system("clear");
		printf("%02d:%02d:%02d\n", jj, mm, dd);
		sleep(1);
		system("clear");

	}

	system("notify-send GTimer \"Time's up\"");

	while (1) {
		system("mpg123 sound.mp3");
		system("clear");
	}	

	return 0;
}
