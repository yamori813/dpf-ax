#include "dpf.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
int ret;
DPFHANDLE h;
unsigned char id[3];
unsigned char *buff;
int i, fd, size, offset;

	ret = dpf_open("/dev/sga", &h);
	flash_probe(h, id);
	printf("%2x %2x %2x\n", id[0], id[1], id[2]);
	size = 1024 * 4;
	buff = (unsigned char *)malloc(size);
	fd = open("dumpfile", O_WRONLY|O_CREAT|O_TRUNC, 0666);
	offset = 0;
	for (i = 0; i < 256; ++i) {
		flash_read(h, buff, offset, size);
		write(fd, buff, size);
		offset += size;
	}
        close(fd);

	dpf_close(h);
}
