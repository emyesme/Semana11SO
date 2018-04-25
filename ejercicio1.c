
/**
Integrantes:
Jaime Cuartas Granada 1632664
Juan Camilo Perez 1630779
Emily Esmeralda Carvajal Camelo 1630436

Write a program that calls fork(). Before calling fork(), have 
the main process access a variable (e.g.,x) and set its value 
to some-thing (e.g.,100). What value is the variable in the child
process? What happens to the variable when both the child and 
parent change the value of x?
**/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char *argv[]){
	int x = 100;
	pid_t pid = fork();
	if(!pid){
		//hijo	
		x = 99;
		printf("Soy el hijo con pid %d y mi x es %d\n",getpid(),x);	
			
	}else{
		//padre
		wait(NULL);
		x=1;
		printf("Soy el padre con pid %d y mi x es %d\n",getpid(),x);
	}
	return 0;
}







