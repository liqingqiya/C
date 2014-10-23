#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(){
	struct utsname sysinfo;
	if(uname(&sysinfo)==-1){
		perror("uname");
		return EXIT_FAILURE;	/*declared in stdlib.h*/
	}
	printf("system name:%s\n",sysinfo.sysname);
	printf("node name:%s\n", sysinfo.nodename);
	printf("release name:%s\n", sysinfo.release);
	printf("version name:%s\n", sysinfo.version);
	return EXIT_SUCCESS;/*declared in stdlib.h*/
}
