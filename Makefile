#!/bin/bash

mdceuit: down.o mdceuit.o displaymenu.o compression.o decompression.o openfile.o creatMarray.o codelength.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o findindex.o decompress2.o  decompress3.o decompress4.o decompress5.o decompress6.o decompress7.o
	  gcc -o mdc -lncurses down.o mdceuit.o displaymenu.o compression.o decompression.o openfile.o creatMarray.o codelength.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o findindex.o decompress2.o  decompress3.o decompress4.o decompress5.o decompress6.o decompress7.o

down.o: down.c header.h declarations.h
	gcc -c down.c

creatMarray.o: creatMarray.c header.h declarations.h
		gcc -c creatMarray.c

codelength.o: codelength.c header.h declarations.h
		gcc -c codelength.c

compress2.o: compress2.c header.h declarations.h
		gcc -c compress2.c

compress3.o: compress3.c header.h declarations.h
		gcc -c compress3.c

compress4.o: compress4.c header.h declarations.h
		gcc -c compress4.c

compress5.o: compress5.c header.h declarations.h
		gcc -c compress5.c

compress6.o: compress6.c header.h declarations.h
		gcc -c compress6.c

compress7.o: compress7.c header.h declarations.h
		gcc -c compress7.c

mdceuit.o: mdceuit.c header.h declarations.h
	   gcc -c mdceuit.c

displaymenu.o: displaymenu.c header.h declarations.h
	       gcc -c displaymenu.c

compression.o: compression.c header.h declarations.h
	       gcc -c compression.c	

decompression.o: decompression.c header.h declarations.h
	       gcc -c decompression.c	

openfile.o: openfile.c header.h declarations.h
	     gcc -c openfile.c	

findindex.o: findindex.c header.h declarations.h
	     gcc -c findindex.c	

decompress2.o: decompress2.c header.h declarations.h
		gcc -c decompress2.c

decompress3.o: decompress3.c header.h declarations.h
		gcc -c decompress3.c

decompress4.o: decompress4.c header.h declarations.h
		gcc -c decompress4.c

decompress5.o: decompress5.c header.h declarations.h
		gcc -c decompress5.c

decompress6.o: decompress6.c header.h declarations.h
		gcc -c decompress6.c

decompress7.o: decompress7.c header.h declarations.h
		gcc -c decompress7.c

clean:
	rm *.o
	rm mdc

clean2:
	rm CFile2
	rm EFile2
	rm DFile2

clean3:
	rm CFile3
	rm EFile3
	rm DFile3

clean4:
	rm CFile4
	rm EFile4
	rm DFile4
clean5:
	rm CFile5
	rm EFile5
	rm DFile5
clean6:
	rm CFile6
	rm EFile6
	rm DFile6
clean7:
	rm CFile7
	rm EFile7
	rm DFile7
