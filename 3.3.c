#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
	int pipefds[2];
	char buffer[5];

		if (pipe(pipefds) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
		}

	char *pin = "4128\0";

	printf("Nyatakan PIN DEKAT pipe...\n");
	write(pipefds[1],pin, 5);
	printf("Selesai.\n\n");

	printf("Baca PIN dari pipe...\n");
	read(pipefds[0],buffer,5);
	printf("Selesai.\n\n");



		printf("PIN daripada pipe: %s\n", buffer);
		return EXIT_SUCCESS;
}
