/*! \file userlist.c
	\brief The utility file.
*/
/*! \fn main()
  \brief The main executing function.
*/

#include<stdio.h>
//#include "userlist.c" 
int main() 
{
	char string[10];char nl[2];char x;

	x='y';
	
	struct node *first;
	first=NULL;
	while(x!='n')
	{
		printf("Enter user name : ");
		gets(string);
		first = ord_ins(string,first);
		printf("\nPress d to delete Element\nDo you wish to continue ?");
		scanf("%c",&x);
		gets(nl);
		if(x=='d')
		{
			printf("\nEnter username to be deleted : ");
			gets(string);
			gets(nl);
			first=del(string,first);
		}
	}
	printf("Sorted List : \n");
	display(first);
	return 0;
}
