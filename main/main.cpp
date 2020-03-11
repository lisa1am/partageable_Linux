
#include <iostream>
#include <dlfcn.h>


int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int valeur1;
	int valeur2;

	void *handle;
	void (*func_name)(const char*);

	handle=dlopen("../bin/libComposant1.so", RTLD_LAZY);
	*(void**)(&func_name) = dlsym(handle,"composant1");

	handle=dlopen("../bin/libComposant2.so", RTLD_LAZY);
        *(void**)(&func_name) = dlsym(handle,"composant2");

	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
}
