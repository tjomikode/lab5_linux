#include<iostream>
#include<getopt.h>

using namespace std;
int main (int argc, char *argv[]){

	const char* short_options = "vhs::f:";

	const struct option long_options[] = {
		{"var", no_argument, NULL,'v'},
		{"help",no_argument,NULL,'h'},
		{"size",optional_argument,NULL,'s'},
		{"file",required_argument,NULL,'f'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index=-1;
	int vctr = 0;
	int hctr = 0;
	int sctr = 0;
	int fctr = 0;
	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){
		switch(rez){
			case 'v': {				
				if (vctr==0)
					if (option_index<0)
						cout << "Argument: v"<<endl;
					else
						cout << "Argument: var"<<endl;
				
				vctr+=1;
				break;
			};
			case 'h': {
				if (hctr==0)
					if (option_index<0)
						cout << "Argument: h"<<endl;
					else
						cout << "Argument: help"<<endl;
				hctr++;
				break;
			};
			case 's': {
				if (sctr==0)
					if (option_index<0)	
						if (optarg!=NULL&&optarg!=" ")
							cout <<"Argument:s\tfound size with value "<<optarg<<endl;
						else
							cout <<"Argument:s\tfound size without value"<<endl;
					else
						if (optarg!=NULL)
							cout <<"Argument:size\tfound size with value "<<optarg<<endl;
						else
							cout <<"Argument:size\tfound size without value"<<endl;
				sctr++;
				break;
			};
			case 'f': {
				if (fctr==0)
					if (option_index<0)
						cout <<"Argument:f\tfile = "<<optarg<<endl;
					else
						cout << "Argument:file\tfile = "<<optarg<<endl;
				fctr++;
				break;
			};
			case '?': default: {
				cout <<"unknown option"<<endl;
				break;
			};
		};
		option_index=-1;
	};
	return 0;
}
