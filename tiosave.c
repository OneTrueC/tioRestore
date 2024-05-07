/* save termios to file */
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

	if (tcgetattr(STDIN_FILENO, &terms) < 0) {
		perror("tiosave: termios failed");
		return errno;
	}

	termfd = fopen(SAVELOC, "w");

	if (termfd == NULL) {
		perror("tiosave: file open failed");
		return errno;
	}

	if (fwrite(&terms, sizeof(struct termios), 1, termfd) < 1) {
		fprintf(stderr, "tiosave: file write failed");
		return 9;
	}

	fclose(termfd);

	return 0;
}
