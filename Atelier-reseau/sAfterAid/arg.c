#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// **argv hiya tableau w fi kol case fiha argument
// ya3ni kan 7atit 2 argumet haka ./arg 4 isetn
// rahi ta3ni argv[1] hiya 4
// w argv[2] hiya isetn
// ps: argv[0] bech ikoun fiha isem program fil exemple hetha bech tji ./arg

// argc fiha nombre de argument fil exemple hetha argc hiya 3

//bech tcompili program hetha a3mel
// gcc arg.c -o arg
// ./arg 4

void main(int argc, char **argv) { 
	for(int i = 0; i<atoi(argv[1]) ; i++) {
		printf("%d) hello world\n",i+1);
	}
}
