//touch.c
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
char buf[512];
int
main(int argc, char *argv[])
{
	int i;
	if (argc == 1)
	{
		printf(1, "touch SOURCE FILE");
		exit();
	}
	
	for (i = 1; i < argc; i++)
	{
		int file;
		if ((file = open(argv[i], O_RDONLY)) < 0)
		{
			file = open(argv[i], O_CREATE|O_RDONLY);
			printf(1, "created %s\n", argv[i]);
		}
		else
		{
			printf(1, "failed to create %s", argv[i]);
		}
		close(file);
	}
	exit();
}