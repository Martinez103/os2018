#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Main before fork()\n");
	int pid= fork();
	int pid1 = fork();
   if(pid==0){
	if(pid1==0){
	printf("I am the child after fork(),launching free -h\n");
	char *args1[] = {"free","-h",NULL};
	execvp("/bin/free",args1);
}	else{
	printf("I am the child after fork(), launching ps -ef\n");
	char *args[] = {"/bin/ps","-ef",NULL};
	execvp("/bin/ps",args);}
		
}
return 0;
	
}
