hello:
	cc -o hello hello.c -I ../../inc libsask.so -Og

run: hello
	LD_LIBRARY_PATH=. ./hello 

clean:
	rm -f hello