#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link;
};



struct node* append(struct node* root,int n){
	struct node* p;
	struct node* temp;
	int i;
	
	for(i=0;i<n;i++){
	temp = (struct node*)malloc(sizeof(struct node));
	here: printf("Enter Data: ");
	scanf("%d",&(temp->data));
	temp->link = NULL;
	if(root == NULL)
		root = temp;
	else{
		
		if(search(root,temp->data)){
			printf("Already existed. Try again.\n");
			goto here;
		}
		else{
			p = root;
			while(p->link != NULL)
				p = p->link;
			p->link = temp;
		}	
	}
}
	return root;
}

void display(struct node* root){
	struct node* p;
	p = root;
	int count = 1;
	while(p!=NULL){
		printf("\n\n\nData %d: \nValue: %d\nAddress: %x",count++,p->data,p->link);
		p = p->link;
	}
}

int search(struct node* root,int value){
	struct node* p;
	p = root;
	
	while(p!= NULL){
		if(p->data == value)
			return 1;
		p = p->link;
	}
	return 0;
}


void update(struct node* root,int value,int value2){
	struct node* p;
	p = root;
	
	while(p!= NULL){
		if(p->data == value)
			p->data = value2;
		p = p->link;
	}
}
void deletelast(struct node* root){
	struct node* p,*pre;
	p = root;
	
	while(p->link!= NULL){
		pre = p;
		p = p->link;
	}
	pre->link = NULL;
}
int main(){
	struct node* root = NULL;
	int n,opt,num,num2;
	printf("Enter how many nodes: ");
	scanf("%d",&n);
	root = append(root,n);
	
	while(1){
		system("cls");
		printf("\n\n1. Search \n");
		printf("2. Add Node\n");
		printf("3. Display All Nodes.\n");
		printf("4. Update Node.\n");
		printf("5. Delete Last Node.\n");
		printf("Enter option: ");
		fflush(stdin);
		scanf("%d",&opt);
		switch(opt){
			case 1:
				system("cls");
				printf("Enter number to be searched: ");
				scanf("%d",&num);
				if(search(root,num))
					printf("Found");
				else
					printf("Not found");
				getch();
				break;
			case 2:
				printf("Enter how many nodes: ");
				scanf("%d",&n);
				append(root,n);
				break;
			case 3:
				system("cls");
				display(root);
				getch();
				break;
			case 4:
				system("cls");
				printf("Enter number to be changed: ");
				scanf("%d",&num);
				if(search(root,num)){
			 there: printf("Enter number: ");
					scanf("%d",&num2);
					if(search(root,num2)){
						printf("Try again new number.\n");
						goto there;
					}	
					update(root,num,num2);
					printf("Successfully updated.");
				}
				else
					printf("Not found");
				getch();
				break;
			case 5:
				deletelast(root);
				break;
		}
		
	}
	
	return 0;
}
