#include<stdio.h> 
#include<fcntl.h> 
#include <unistd.h>

#define BUFSIZE 100

int main() 
{   
    int fdIn, fdOut, size, count;
    char inFilename[]="input.dat";
    char outFilename[]="output.dat";
    char buf[BUFSIZE];

    fdIn = open(inFilename, O_RDONLY);  
    if (fdIn == -1) {
        printf("%s does not exist.\n", inFilename);
        return -1;
    }

    fdOut = open(outFilename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);  
    if (fdOut == -1) {
        printf("%s creation failed.\n", outFilename);
        return -1;
    }

    do {
        count = read(fdIn, buf, BUFSIZE);
        printf("Read %d bytes\n", count);
        count = write(fdOut, buf, count);
        printf("Write %d bytes\n", count);
    } while (count == BUFSIZE);

    close(fdIn);
    close(fdOut);
    return 0; 
} 
