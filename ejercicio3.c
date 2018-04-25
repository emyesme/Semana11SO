/**
Integrantes:
Jaime Cuartas Granada 1632664
Juan Camilo Perez 1630779
Emily Esmeralda Carvajal Camelo 1630436

Enunciado: "Write another program using fork() . The child process should
print "hello"; the parent process should print "goodbye". You should try to  
ensure that the child process always prints first; can you do this without
calling waitpid() in the parent?"
**/                                                                                                                            
#include <string.h>                                                              
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {                                                                                                                                
  int status;                                                                          
  // invoque la llamada al sistema fork()                                              
  pid_t pid = fork();
  if (pid != 0) {                                                                      
    // esta es la parte del padr-e que debe imprimir 'goodbye'
  	waitpid(pid,NULL,0);
  	printf("goodbye\n");
                              
  } else {                                                                             
    // esta es la parte del hijo que debe imprimir 'hello'
  	printf("hello\n");  
	sleep(2);                          
  }                                                                                    
}
