#include "dpf.h"
#include <stdio.h>

int main()
{
int ret;
DPFHANDLE h;
unsigned char id[3];

	ret = dpf_open("/dev/sga", &h);
	flash_probe(h, id);
	printf("%2d %2d %2d\n", id[0], id[1], id[2]);
	dpf_close(h);
}
