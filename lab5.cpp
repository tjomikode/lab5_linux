#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "hs::f:";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"size",optional_argument,NULL,'s'},
		{"file",required_argument,NULL,'f'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index;

	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(rez){
			case 'h': {
				printf("Arg: help (--help or -h)\n");
				break;
			};
			case 's': {
				if (optarg!=NULL)
					printf("Arg: size(found size with value %s)\n",optarg);
				else
					printf("Arg: size(found size without value)\n");
				break;
			};
	
			case 'f': {
				printf("Arg: file = %s\n",optarg);
				break;
			};
			case '?': default: {
				printf("found unknown option\n");
				break;
			};
		};
	};
	return 0;
};
