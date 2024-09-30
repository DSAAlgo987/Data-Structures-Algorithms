#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int coeff;
	int pow;
	struct Node* next;
}*start1 , *start2 , *result;
struct Node* createNode(int coeff , int power){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coeff = coeff;
	temp->pow = power;
    temp->next = NULL;

    return temp;
}

struct Node *create(struct Node *start){
    struct Node *temp , *newNode;
    int n , c , p;

    printf("Enter the no of terms to insert :");
    scanf("%d" , &n);

    for(int i = 0 ; i < n ; i++){
        printf("Enter the coeff & power for %d : " ,i+1);
        scanf("%d %d" , &c , &p);

        newNode = createNode(c , p);

        // If LL is not created
        if(start == NULL){
            start = newNode;
        }else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

	return start;
}


void displayPolynomial(struct Node* poly)
{
	printf("\nPolynomial expression is: ");
	while(poly != NULL)
	{
		printf("%dX^%d", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+");
	}
}

void createResult(int c , int p){
    struct Node *temp , *newNode;
    newNode = createNode(c , p);
    if(result == NULL){ 
        result = newNode;
    }else{
        temp = result;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void add(){
    struct Node *temp1 = start1 , *temp2 = start2;
    int c , p;
    
    while(temp1 !=NULL && temp2!=NULL){
        if(temp1->pow == temp2->pow){
            c = temp1->coeff + temp2->coeff;
            p = temp1->pow;
            temp1= temp1->next;
            temp2= temp2->next;
            createResult(c , p);
        }else if(temp1->pow > temp2->pow){
            c = temp1->coeff;
            p = temp1->pow;
            temp1 = temp1->next;
            createResult(c , p);
        }else{
             c = temp2->coeff;
            p = temp2->pow;
            temp2 = temp2->next;
            createResult(c , p);
        }
    }
    
    while(temp1 !=NULL){
        c = temp1->coeff;
        p = temp1->pow;
        temp1 = temp1->next;
        createResult(c , p);
    }
    
    while(temp2 !=NULL){
        c = temp2->coeff;
        p = temp2->pow;
        temp2 = temp2->next;
        createResult(c , p);
    }
}


void subtract(){
    struct Node *temp1 = start1 , *temp2 = start2;
    int c , p;
    
    while(temp1 !=NULL && temp2!=NULL){
        if(temp1->pow == temp2->pow){
            c = temp1->coeff - temp2->coeff;
            p = temp1->pow;
            temp1= temp1->next;
            temp2= temp2->next;
            createResult(c , p);
        }else if(temp1->pow > temp2->pow){
            c = temp1->coeff;
            p = temp1->pow;
            temp1 = temp1->next;
            createResult(c , p);
        }else{
             c = temp2->coeff;
            p = temp2->pow;
            temp2 = temp2->next;
            createResult(c , p);
        }
    }
    
    while(temp1 !=NULL){
        c = temp1->coeff;
        p = temp1->pow;
        temp1 = temp1->next;
        createResult(c , p);
    }
    
    while(temp2 !=NULL){
        c = temp2->coeff;
        p = temp2->pow;
        temp2 = temp2->next;
        createResult(c , p);
    }
}



