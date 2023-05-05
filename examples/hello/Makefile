hello:
	cc -o hello hello.c -I ../../inc libsask.so

run: hello
	LD_LIBRARY_PATH=. ./hello 

clean:
	rm -f hello