#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Read_Whole_File(FILE * fp, char *buffer, __int64 flength)
{
	const int bsize = 4096;
	int a = flength / bsize + 1;
	char *ptr;
	ptr = &buffer[0];
	for(int i=0;i<a;++i)
	{
		fread(ptr,1,bsize,fp);
		ptr+=bsize;
	}
}
int main(int argc, char * argv[])
{
	system("color 1e");
	printf("#File to copy\nLOL#:");
	char * file = new char[100];
	char * sfile = new char[100];
	int esize = 0;
	scanf("%s",file);
	FILE * fpointer = fopen((const char*)file,"r");
	if(fpointer == NULL)
	{
		printf("#FILE DOESN'T EXIST!\n");
		scanf("%*c");
		scanf("%*c");
		return 0;
	}
	fseek(fpointer, 0, SEEK_END);
	__int64 len = (__int64)ftell(fpointer);
	fseek(fpointer, 0, SEEK_SET);	
	char * buffer = new char[len];
	Read_Whole_File(fpointer,buffer,len);
	fclose(fpointer);
	printf("#File to save as\nLOL#:");
	scanf("%s",sfile);
	printf("#How big?(in MegaBytes)\nLOL#:");
	scanf("%d",&esize);
	fpointer = fopen((const char*)sfile,"w+");
	int b = 0;
	int intRem = (esize*1048576) - len;
	for(int i=0;i<(esize*1048576) + intRem;i++)
	{
		if(b == len)
			b = 0;
		fwrite(&buffer[b],1,1,fpointer);
		++b;
	}
	fclose(fpointer);
	printf("#DONE!!!!!!!!!!!");
		scanf("%*c");
		scanf("%*c");	
	
}