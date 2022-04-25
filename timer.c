#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
	int jam, menit, detik;

	printf("Masukkan waktunya (format jam<spasi>menit<spasi>detik): ");
	scanf("%d %d %d", &jam, &menit, &detik);

	if ((jam > 12) || (menit > 60) || (detik > 60) || (jam < 0) || (menit < 0) || (detik < 0)) {
		printf("Input yang kamu masukkan tidak valid. \n");
	}
	
	else {
		while (1) {
			if (detik < 0 && menit != 0) {
				detik = 59;
				menit --;
			}

			if (detik < 0 && menit >= 0 && jam != 0) {
				detik = 59;
				menit = 59;
				jam--;
			}

			if (detik == 0 && menit == 0 && jam == 0) {
				break;
			} 

			system("clear");
			printf("				%02d:%02d:%02d\n", jam, menit, detik);
			sleep(1);
			system("clear");

			detik--;
		}	

		system("notify-send GTimer \"Time's up.\"");
		printf("Tekan Ctrl+c untuk mematikan timer.\n\n");
		system("mpg123 sound.mp3 && clear");
		printf("--------------------------------------------------\n");
		printf("Terima kasih telah menggunakan.\n");
		printf("--------------------------------------------------\n");
		printf("Made with love by : Gabriel Cesar Hutagalung\n");
		printf("--------------------------------------------------\n");

	}

	return 0;
}
