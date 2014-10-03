/*! \file userlist.h
 * \brief Contains function declarations.
*/

/*! \var typedef struct node_type s
 * \brief A type definition for structure node_type
 */
 
/*! \fn struct node_type *ord_ins(char string[10],struct node_type *f)
  \brief Insert the username at correct place in Linked List.
  \param string[10] Username to be inserted in the list
  \param f The pointer to the first node of Linked List.
*/

/*! \fn display(struct node_type *f)
  \brief Display the usernames in correct order
  \param f The pointer to the first node of Linked List.
*/

#include<malloc.h>
#include<string.h>

typedef struct node
{
	/*! \var char data[10]
	 * \brief Contains the username of the node
	 */
	/*! \var struct node_type *link
	 * \brief Contains the address of the next node in the list
	 */
	char data[10];
	struct node *link;
}s;
struct node *ord_ins(char string[10],struct node *f)
{
	s *n,*save,*pred;
	n=(s *)malloc(sizeof(s));
	strcpy((n->data),string);
	
	//Check if List is Empty
	if(f==NULL)
	{
		f=n;
		(n->link)=NULL;
		return f;
	}
	else
	{
		pred=f;
		save=f;
	}
	
	//Check if element to be inserted at begining
	if(strcmp(string,(save->data))<0)
	{
		(n->link)=save;
		return n;
	}
	
	while(strcmp(string,(save->data))>=0 && (save->link)!=NULL)
	{
		pred = save;
		save = (save->link);
	}
	
	//Check for duplicate entry
	if(strcmp(string,(save->data))==0)
	{
		printf("Username already present\n");
		return f;
	}
	
	//Check if element to be inserted at last
	if(strcmp(string,(save->data))>0 && (save->link)==NULL)
	{
		(save->link)=n;
		(n->link)=NULL;
		return f;
	}
	else
	{
		(pred->link)=n;
		(n->link)=save;
	}
	return f;
}
struct node *del(char str[10],struct node *f)
{
	s *save,*pred;
	if(strcmp(str,f->data)==0)
		return (f->link);
	
	save=f;
	pred=f;
	
	while(strcmp(str,save->data)!=0 && (save->link)!=NULL)
	{
		pred=save;
		save=(save->link);
	}
	if((save->link)==NULL)
	{
		free(save);
		pred->link=NULL;
		return f;
	}
	(pred->link)=(save->link);
	free(save);
	return f;
}
void display(struct node *f)
{
	s *save;
	save=f;
	while((save->link)!=NULL)
	{
		printf("%s\n",(save->data));
		save = (save->link);
	}
	printf("%s\n",(save->data));
	return ;
}
