#include <stdio.h>

int main(void)
	char  input[120];
	fgets(input, sizeof(input), stdin);
	printf("%s\n", input);
	return 0;
}
