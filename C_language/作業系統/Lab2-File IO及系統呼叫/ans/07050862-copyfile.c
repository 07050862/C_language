#include<stdio.h> 
#include<fcntl.h> 
#include <unistd.h>

#define BUFSIZE 50

int main() 
{   
    FILE *fdIn,*fdOut;
    int count;
    char inFilename[]="input.dat";
    char outFilename[]="output.dat";
    char buf[BUFSIZE];

    fdIn = fopen("input.dat","r");  
    if (fdIn == NULL) {
        printf("%s does not exist.\n", inFilename);
        return -1;
    }

    fdOut = fopen("output.dat","w");  
    if (fdOut == NULL) {
        printf("%s creation failed.\n", outFilename);
        return -1;
    }

    do {
        count = fread(buf, 1,BUFSIZE,fdIn);
        printf("Read %d bytes\n", count);
        count = fwrite(buf,1,count,fdOut);
        printf("Write %d bytes\n", count);
    } while (count == BUFSIZE);

    fclose(fdIn);
    fclose(fdOut);
    return 0; 
} 
