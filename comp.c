#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
//יובל חג'בי - 207797424
//חן שלו- 313584906
int main(int argc, char* argv[]) {
	if (argc != 3) {
		exit(1);
	}
	char ch1, ch2;
	int x1, x2, fd1, fd2;
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0) {
		exit(1);
	}
	fd2 = open(argv[2], O_RDONLY);
	if (fd2 < 0) {
		close(fd1);
		exit(1);
	}
	while (1) {
		x1 = read(fd1, &ch1, 1);
		if (x1 < 0) {
			close(fd1);
			close(fd2);
			exit(1);
		}
		x2 = read(fd2, &ch2, 1);
		if (x2 < 0) {
			close(fd1);
			close(fd2);
			exit(1);
		}
		if (x1 == 0 && x2 == 0) {
			close(fd1);
			close(fd2);
			exit(2);
		}

		if (x1 == 0 || x2 == 0) {
			close(fd1);
			close(fd2);
			exit(1);
		}
		if (ch1 != ch2) {
			close(fd1);
			close(fd2);
			exit(1);
		}
	}
}


