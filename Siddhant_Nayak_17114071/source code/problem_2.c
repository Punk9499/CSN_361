
/**
* @file problem_2.c
* @brief Program for zombie and orphan process.
* 
*
*
* @author Siddhant Nayak (17114071)
*
* @date 8/1/2019
*/

#include <stdio.h> 
#include<stdlib.h>
#include<unistd.h>

int main() 
{ 
  
    int x; 
    x = fork(); 
  
    if (x > 0) 
        printf("IN PARENT PROCESS MY PROCESS ID  : %d\n", getpid()); 
  
    else if (x == 0) { 
        sleep(5); 
        x = fork(); 
  
        if (x > 0) { 
   printf("(ORPHAN PROCESS) IN CHILD PROCESS MY PROCESS ID :%d PARENT PROCESS ID : %d\n", getpid(), getppid()); 
  
    
     sleep(4); 
  
   printf("IN CHILD PROCESS MY PARENT PROCESS ID  : %d\n", getppid()); 
        } 
  
        else if (x == 0) 
            printf("(ZOMBIE PROCESS) IN CHILD'S CHILD PROCESS MY PARENT ID : %d\n", getppid()); 
    } 
  
    return 0; 
} 
