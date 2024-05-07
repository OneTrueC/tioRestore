/* load termios from file */
#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <errno.h>

#include <termios.h>

int
main()
{
	FILE* termfd;
	struct termios terms;

	termfd = fopen(SAVELOC, "r");

	if (termfd == NULL) {
		perror("tioload: file open failed");
		return errno;
	}

	if (fread(&terms, sizeof(struct termios), 1, termfd) < 1) {
		fprintf(stderr, "tioload: file read failed");
		return 9;
	}

	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &terms) < 0) {
		perror("tioload: termios failed");
		return errno;
	}

	fclose(termfd);

	return 0;
}
