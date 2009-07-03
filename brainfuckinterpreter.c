#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MEMORYCELLS 1000 
#define CODESIZE 1000

struct Machine
	{
	char memory[ MEMORYCELLS ];
	char *pointer;
	};

void initializeMachine(struct Machine *a)
{
int i;
a->pointer=&(a->memory[0]);
for (i=0; i< MEMORYCELLS; i++)
	a->memory[i]=0;
}

char translate(char in)
{
switch (in)
		{
		case '>': return 1;
		case '<': return 2;
		case '+': return 3;
		case '-': return 4;
		case '.': return 5;
		case ',': return 6;
		case '[': return 7;
		case ']': return 8;
		}
return in;
}



void execute(struct Machine *a, char *code)
{
while (0==0)
	{
	switch (translate(*code))
		{
		case 0: return;						break;
		case 1:	a->pointer++;				break;
		case 2:	a->pointer--;				break;
		case 3:	(*(a->pointer))++;			break;
		case 4:	(*(a->pointer))--;			break;
		case 5:	putchar(*(a->pointer));		break;
		case 6:	*(a->pointer)=getchar();	break;
		case 7:	{
					if (*(a->pointer)==0) 
						while (*code!=']')
							code++;
					}							break;
		case 8:   {
					if (*(a->pointer)!=0) 
						while (*code!='[')
							code--;
					}							break;
		}
	code++;
	}
}

int main(int argc, char *argv[])
{
struct Machine a;
char codeinmemory[CODESIZE];
char* code;

if (argc>2)
	{printf("wrong number of arguments"); return 0;}
if (argc==2)
	code=argv[1];
if (argc==1)
	{	
	int c,i=0;
	while ((c=getchar())!=EOF)
		codeinmemory[i++]=c;
	codeinmemory[i]=0;
	}

initializeMachine(&a);
execute(&a, code);
return 0;
}

