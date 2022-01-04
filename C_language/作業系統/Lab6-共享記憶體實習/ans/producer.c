/**

 * Simple program demonstrating shared memory in POSIX systems.

 *

 * This is the producer process that writes to the shared memory region.

 *

 * Figure 3.17

 *

 * @author Silberschatz, Galvin, and Gagne

 * Operating System Concepts  - Ninth Edition

 * Copyright John Wiley & Sons - 2013

 */





#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <fcntl.h>

#include <sys/shm.h>

#include <sys/stat.h>

#include <sys/mman.h>

#include <unistd.h>



int main()

{

	const int SIZE = 4096;

	const char *name = "OS";

	const char *message0="The sum is ";

	const char *message1;
	const char *message2="\n";




	int shm_fd;

	void *ptr;



	/* create the shared memory segment */

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);



	/* configure the size of the shared memory segment */

	ftruncate(shm_fd,SIZE);



	/* now map the shared memory segment in the address space of the process */

	ptr = mmap(0,SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);



	/**

	 * Now write to the shared memory region.

 	 */

	/*sprintf(ptr,"%s",message0);

	ptr += strlen(message0);

	sprintf(ptr,"%s",message1);

	ptr += strlen(message1);*/



	sprintf(ptr,"%s",message0);

	int i,count=0,n;

	printf("Input an integer:");

	scanf("%d",&n);

	for(i=1;i<=n;i++)

		count += i;

	ptr += strlen(message0);

	

        
	/*以下為將count轉到字元陣列裡*/
	int l,j,k=0;
	char a[80],b[80];
	
	for(l=0;count!=0;l++)
	{
		a[l] = count % 10+'0';
		count /= 10;
	}
	
	for(j=l-1;j>=0;j--)
	{
		b[k++] = a[j];
	}
	//puts(b);
	/*以上為將count轉到字元陣列裡*/



	message1 = b;

	



	sprintf(ptr,"%s",message1);

	ptr += strlen(message1);

	sprintf(ptr,"%s",message2);

	ptr += strlen(message2);

	

	return 0;

}
