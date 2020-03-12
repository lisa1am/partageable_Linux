COMPONENTS_DIRNAMES=

all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=.; \
       	./main Composant1 10 2; \
	./main Composant2 10 2;

install:
	cd main && ${MAKE} install
clean:
	cd main && ${MAKE} clean
