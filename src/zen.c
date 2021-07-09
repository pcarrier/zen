#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define INCBIN_STYLE INCBIN_STYLE_SNAKE
#include <incbin.h>
INCBIN(Pragmata, "../../res/PragmataProR_0829.ttf");

#define UNUSED(x) (void)(x)

void fail(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

int main(int argc, char **argv) {
	UNUSED(argc);
	UNUSED(argv);
}
