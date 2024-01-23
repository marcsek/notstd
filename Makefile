
EXE=main
CMAKE_OPTIONS=-DNOTSTD_MAKE_EXE=ON
ODIR=build

all:
	cd ./$(ODIR) && cmake $(CMAKE_OPTIONS) ..
	cd ./$(ODIR) && make

clean:
	cd ./$(ODIR) && make clean
	rm -rf ./$(ODIR)/*

run:
	cd ./$(ODIR) && make
	./$(ODIR)/$(EXE)

test: all
	cd ./$(ODIR) && ./test

