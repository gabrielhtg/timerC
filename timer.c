#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
	int jj, mm, dd;

	printf("Masukkan waktunya (format jam<spasi>menit<spasi>detik): ");
	scanf("%d %d %d", &jj, &mm, &dd);

	if ((jj > 12) || (mm > 60) || (dd > 60) || (jj < 0) || (mm < 0) || (dd < 0)) {
		printf("Input yang kamu masukkan tidak valid. \n");
	}
	
	else {
		while (1) {
			dd--;

			if (dd < 0 && mm != 0) {
				dd = 59;
				mm --;
			}

			if (dd < 0 && mm >= 0 && jj != 0) {
				dd = 59;
				mm = 59;
				jj--;
			}

			if (dd == 0 && mm == 0 && jj == 0) {
				break;
			} 

			system("clear");
			printf("%02d:%02d:%02d\n", jj, mm, dd);
			sleep(1);
			system("clear");
		}	

		system("notify-send GTimer \"Time's up.\"");
		printf("Tekan Ctrl+c untuk mematikan timer.\n\n");
		system("mpg123 sound.mp3 && clear");
		printf("--------------------------------------------------------------\n");
		printf("Terima kasih telah menggunakan.\n");
		printf("--------------------------------------------------------------\n");
		printf("Made with love by : Gabriel Cesar Hutagalung\n");
		printf("--------------------------------------------------------------\n");

	}

	return 0;
}