Create hide_openat.so 
gcc -shared -fPIC -o hide_openat.so openat_hide.c -ldl

Create hide_write.so
gcc -shared -fPIC -o hide_write.so write_hide.c -ldl

make test1 from test_openat.c
gcc -o test1 test_openat.c 

make test2 from test_write.c
gcc -o test2 test_write.c 


run the test1
D_PRELOAD=$(pwd)/hide_openat.so ./test1 

run the test2
D_PRELOAD=$(pwd)/hide_write.so ./test2

Before compiling, configure the openat_hide.c to show on the tcp file that is included in the files in this github, with the right path 
of the folder that you are in, you can use this using the $pwd command. 
to create all the .so and executables run: $make

