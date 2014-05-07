#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
		struct _node  *l;
		struct _node  *r;
		char v;
}node;

node *mk(node *l,node *r,char val)
{
	node *f=(node *)malloc(sizeof(*f));
	f->l=l;
	f->r=r;
	f->v=val;
	return f;
}

void nodefr(node *n)
{
	if(n)
	{
		nodefr(n->l);
		nodefr(n->r);
		free(n);
	}
}
void fun1()
{
	int *p=(int *)malloc(10*sizeof(int));
	p[10]=0;
}

int fun2()
{
	int len=4,i;
	int *pt=(int *)malloc(len*sizeof(int));
	int *p=pt;

	for(i=0;i<len;i++)
	{
		p++;
	}

	*p=5;
	printf("the value of p equal:%d",*p);
	return 0;
}



int badleak()
{
	node *tree1,*tree2,*tree3;
	tree1=mk(mk(mk(0,0,'3'),0,'2'),0,'1');
	tree2=mk(0,mk(0,mk(0,0,'6'),'5'),'4');
	tree3=mk(mk(tree1,tree2,'8'),0,'7');
	return 0;
}

int fun3()
{
	char *p=NULL;
	p=(char *)malloc(sizeof(char));
        *p='s';
	free(p);
	*p='q';
	return 0;	
}

int main(int argc,char * argv[])
{
   	int a[5];
	int i,s;
	char my_string[]="hello there";
	a[0]=a[1]=a[3]=a[4]=0;
	s=0;
	for(i=0;i<5;i++)
			s+=a[i];
	if(s==377)
			printf("sum is %d\n",s);
	fun1();
	fun2();
	fun3();
	badleak();
	return 0;
}
