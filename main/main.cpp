
#include <iostream>
#include <dlfcn.h>
#include <string>
#include <stdio.h>

static int calc(int data1, int data2, std::string composant){

	int (*func)(int,int);
	int value=0;
	void *handle;

	if(composant.compare("Composant1")==0){
		handle = dlopen("./libComposant1.so", RTLD_LAZY);
	}else if(composant.compare("Composant2")==0){
		handle = dlopen("./libComposant2.so", RTLD_LAZY);
	}
	if (handle == NULL) {
                /* fail to load the library */
                fprintf(stderr, "Error: %s\n", dlerror());
                return EXIT_FAILURE;
	}


	std::cout <<"COMPOSANT TO USE : " << composant << "\n";

	if(composant.compare("Composant1") == 0){
		*(void **)(&func) = dlsym(handle,"composant1");
		std::cout << "\nUsing Composant1\n";
		if(func == NULL){
			printf("Error occured\n");
                        printf("erreur dlsym : %s\n", dlerror());
                        dlclose(handle);
                        exit(EXIT_FAILURE);
		}

	}
	else{
		*(void **)(&func) = dlsym(handle, "composant2");
		std:: cout << "\nUsing Composant 2\n";
		if(func == NULL){
			printf("Error occured\n");
                        printf("erreur dlsym : %s\n", dlerror());
                        dlclose(handle);
                        exit(EXIT_FAILURE);
		}
	}
	value = func(data1,data2);
	dlclose(handle);

	return value;
}







int main(int argc, char ** argv)
{

	if(argc !=4) exit(EXIT_FAILURE);
	int data1 = std::stoi(argv[2]);
	int data2 = std::stoi(argv[3]);

	int valeur=0;

	
	valeur=calc(data1,data2,argv[1]);


	std::cout << std::endl << "valeur :" << valeur << std::endl;
}
