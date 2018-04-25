
/**
Integrantes:
Jaime Cuartas Granada 1632664
Juan Camilo Perez 1630779
Emily Esmeralda Carvajal Camelo 1630436

Enunciado: "Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child and parent
access the file descriptor returned by open()? What happens when they are
writing to the file concurrently, i.e., a t the same time?"**/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> //libreria para archivos


int main(int argc, char **argv) {                                                      
  // Usar estas variables                                                              
  int x;                                                                               
  pid_t pid;                                                                           
  char *filename="code-02.txt";                                                        
  int fd;                                                                                                                                                                    
  //                                                                                   
  // Instrucciones para abrir archivo de lectura/escritura) 
  close(STDOUT_FILENO);                           
  fd = open(filename,O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  //                                                                                                                                                                       
  x = 100;                                                                             
  pid = fork();                                                                        
  if (pid == 0) {                                                                      
    x++;                                                                               
    // Instruccion para escribir en archivo una cadena                                 
    // acompanada del valor de 'x'
    dprintf(fd,"El padre escribe, x = %d\n",x);                                                   
  } else {                                                                             
    x+=2;                                                                              
    // Instruccion para escribir en archivo una cadena                                 
    // acompanada del valor de 'x'           
    dprintf(fd,"El hijo tambien escribe, x = %d\n",x);                                          
  }                                                                                    
                                                                                       
  close(fd);                                                                           
} 