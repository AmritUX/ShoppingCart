#include <stdio.h>
#define MAX_INVENTORY_SIZE 10
#define TAX .13
#define CONST_LOW 1
#define CONST_HIGH 8
#define MAX_ITEMS 10

struct Cart{
	
	int sku[MAX_ITEMS];
	float price[MAX_ITEMS];
	int quantity[MAX_ITEMS];
	float totalCost;
	int size;

}; 

/* 



I declare that the attached assignment is wholly my own work in accordance with Seneca Academic Policy.  

No part of this assignment has been copied manually or electronically from any other source (including web sites) or distributed to other students.  

Name:   Amrit Singh  Student ID:  asingh396 



Milestone #1	

   

In this milestone, you are to write three functions and a main program to create a menu and input user’s selection.  

a) Write the following function to display a menu:  

void menu()  

This function takes no arguments and displays the following menu to the user.  

Please select from the following options:  

1) Display the inventory.  

2) Price check.  

3) Display my shopping cart.  

4) Add to cart.  

5) Remove from cart.  

6) Check out.  

7) Clear Screen.  

8)Exit. 

b) Write the following function that prompts the user to input an integer. 

This function verifies that the integer is within a specified range (low and high), 

if not, the function displays a warning and prompts the user again. 

This function requires two parameters (low and high range) and returns the validated input from the user. 

You can assume the user will only enter numbers.    int validate(const int low, const int high);  

c) Write the following clear screen function. 

This simple function prints out 40 newlines to clear the screen. 

It requires no parameters and returns nothing. void clear();  

d) Write the main function that  

• calls clear function to clear the screen,  

• displays a welcome massage, 

• calls the function menu to display a menu to the user,  

• calls the validate function to obtain the user’s input. 

Note that the user’s input must be within the range 1 and 8. 

• The program only exits when the user selects Exit on the menu screen (looping required). 

  

Milestone #2  

In this milestone, you are to write seven functions and a main program to allow the user select from a menu and perform the respective action.  

a) Write the following function to display an inventory. 

This function takes an integer array of SKU numbers, and a float array of price. 

The function displays an informative output. 

See “program completion” section for the format of the output.    

void displayInventory(const int sku[],const float price[]);  

b) This function performs a linear (naïve) search over the inventory array. 

This function receives an integer array SKU numbers, and an integer for the desired item. 

This function searches through the array for the desired item and returns the index of the item if it is found, -1 if it is not found. 

int searchInventory(const int sku[],const int item);  

c) Write the following function to check the price for an item. 

This function prompts the user to input the SKU number for the item they are looking for. 

Then, this function searches through the inventory and displays the cost of the item. 

Note that if the item does not exist in the inventory, the program displays an informative message.  

void checkPrice(const int sku[],const float price[]);  

d) Write the following four functions that simply display a “Not implemented” message. 

These functions will be implemented in MS3.  

   void displayCart();    

   void addCart();    

   void removeCart();    

   void checkout();   

e) Extend your main function from MS1 to   define two parallel arrays of size MAX_INVENTORY_SIZE o 

sku: initialize the array with {2358,7654,1209,1345}. 

o price: initialize the array with { 12.60,34.99,5.70,12.50}. 

 Call the appropriate function based on user’s input. 

“1- displayInventory”, 

“2- checkPrice”, 

“3- displayCart”, 

“4- addCart”, 

“5- removeCart”, 

“6- checkout”, 

“7- clear”, and 

“8-display a goodbye message.” 

   

 */ 



void menu(); //function prototype for menu selection of 8 selections //

void clear(); //function prototype for clearing screen 40 empty lines //

void displayInventory(const int sku[],const float price[]);//function prototype display inventory with constant 2 arguments

int searchInventory(const int sku[],const int item);//function prototype searchInventory with 2 arguments

void checkPrice(const int sku[],const float price[]);//function prototype checkprice with 2 arguments

int validate(int low, int high); // function prototype that validates input with 2 arguments 1, 8 //

void displayCart(const struct Cart* pShoppingCart);//function prototype display cart    
void addCart(struct Cart* pShoppingCart, const int sku[], const float price[]);//struct Cart* pShoppingCart, const int sku[], const float price);//function prototype add cart        
void removeCart(struct Cart* pShoppingCart);//function prototype remove cart       
void checkout(struct Cart* pShoppingCart);//function prototype checkout 
int readInventory(const char filename[],int sku[],float price[]);

void printReceipt(const char filename[], struct Cart* pShoppingCart); 









int main() //main function



{//Begiining bracket of main function

	
	int input; //Users input integer for selection 8 options menu //

	

	int exit =1;//Flag 

	

    int sku[MAX_INVENTORY_SIZE];

	

	float price[MAX_INVENTORY_SIZE];
	
	struct Cart myCart;
	
	myCart.size=0;
	myCart.totalCost=0;
	int status = readInventory("inventory.dat",sku, price);
	
	/*if (status != 0)
	{
		
		printf("Failed to load\n");
	
	
	}*/
	
	do//do/while loop with 8 cases of switch/case statements 
	
	
	{//Beginnin bracket for do/while loop

	
	menu(); // function call of 8 selections menu //
	input = validate(CONST_LOW, CONST_HIGH); // function call to validate the main menu's input where const low is 1 an const high is 8

	

	switch(input) //switch loop; started thats validating the input

	

	{// beginning bracket for switch statement of menu function

			

			

			case 1://Option 1: display inventory

			

					displayInventory(sku,price);//calling function display inventory with constant 2 arguments


				break; 

				

			case 2: 

					checkPrice(sku,price);//calling function checkPrice inventory with constant 2 arguments

		

				break; 

				

			case 3: 

					displayCart(&myCart);//calling function display cart

					

				break;

				

			case 4: 

					addCart(&myCart, sku, price);//calling function add from cart 

					

			

				break;

				

			case 5: removeCart(&myCart);//calling function remove from cart  

					

				break;

			

			case 6: 

					checkout(&myCart);//calling function to display
					printReceipt("receipt.dat", &myCart);
		
					

				break;

				

			case 7: 

					clear();//calling function for clearing screen 40 empty lines //

				break;

				

			case 8: 

					printf("\nThank you for shopping!\nHave a nice day!\n\n");//printing thank you message and have a nice day msg

					

					exit = 0; //when 8 is selected the program will exit

					

					break;

						

	} // ending bracket for switch statement of menu function //

	

		} //ending bracket for do/while loop of menu function//

		

	while (input!=8); //do/while loop; input should not be equal to 8. Note: 8 is selected the game will exit //


}//Ending bracket of main function


void menu() //function for menu selection of 8 selections

{//Beginning Bracket of menu function //	

		//Below printfs is displaying welcome message and giving menu selections to users//

		printf("\n\n\nWelcome to the Grocery Store");

		printf("\n============================\n");

		printf("\nPlease select from the following options:\n"); 

		printf ("\n1) Display the inventory\n2) Price Check\n3) Display my shopping cart\n4) Add to cart\n5) Remove from cart\n6) Check out \n7) Clear Screen \n8) Exit\n\nSelect:"); 

}//Ending Bracket of menu function //	





int validate(int low, int high) // function that validates input with 2 arguments



{//Beginning bracket of function validate //



		int input; //integer for scanf validation for menu function//



//starting do/while loop for int validate function //



	do//do/while loop validating input const low and const high

	

	{//Beginning Bracket of do/while loop //

				

		scanf ("%d", &input);//saving users input for main menu //

		

		if (input<low || input>high) //if condition the value is lower or higher than vinput //

			

			printf("Invalid Input!\nPlease select between 1 and 8!:"); //printing invalid input and prompt to try again untill input is validated //

			

	}//Ending Bracket of do/while loop //

	

	while (input<low || input>high); //while loop; while select is either lower than 1 or higher than 3 //

	

	return input; // return the value to input //



}//Ending Bracket of function validate //


void clear()//function that clears buffer



{// Beginning bracket of function clearScreen //

		

	int i;//integer value definition for loop 

	

	for(	i=1	;	i<40	;	i++	)// Looping value i = 1 up to 40 empty lines //

	

	{//Beginning Bracket of for loop//

		

	printf("\n");//new line

	

	}//Ending Bracket of for loop//



}// Ending bracket of function clearScreen //


void displayInventory(const int sku[],const float price[])//function that displayInventory with 2 constant arguments

{//Beginning bracket displayInventory

	

	//Below printfs is displaying  inventory and sku items and price

	printf("\n\n\nInventory");

	printf("\n==================="); 

	printf("\nSku\tPrice(in $)\n\n");


    for (int i = 0; i < MAX_INVENTORY_SIZE; i++ )//for loop with MAX INVENTORY SIZE

	

	{//Beginning bracket for loop

		

		 printf("%d\t%.2f\n", sku[i], price[i]);//printing the sku items and price with it

		 

	}//Ending bracket for loop

	

	printf("===================");//print end display for sku items and price

	
}//Ending bracket displayInventory



 

int searchInventory(const int sku[],const int item)//function searchInventory with 2 arguments

{//Beginning bracket of searchInventory function



	int itemFound = -1;//item found -1

	 

	for(int i = 0; i < MAX_INVENTORY_SIZE; i++)//for loop checking max inventory size of 4

	

		{//Beginning bracket for loop max inventory size

			

			if (sku[i] == item)//sku item checker equals item

				

			itemFound = i;//return array index if item is found


		}//Ending bracket for loop max inventory size



	

	return itemFound;//return to itemFound

	

}//Ending bracket of searchInventory function


void checkPrice(const int sku[],const float price[])//function checkprice with 2 arguments

{//Beginning bracket checkPrice function



	int item;
	
	

printf("\nPlease enter the appropriate SKU number: ");
scanf("%d",&item);

int itemfound = searchInventory(sku, item);

	while (itemfound == -1)
			{
				printf("\nItem is not recognized in the shop! Please try again!");
				printf("\nEnter the appropriate SKU number:");
				scanf("%d", &item);
				itemfound = searchInventory(sku, item);
			}
			
	if (itemfound != -1)//sku item checker equals the actual input from users

	{//Beginning bracket if statement itemfound != 1

		printf("\nItem:\tPrice(in $):\n%d\t%.2f",sku[itemfound], price[itemfound]);//print the item type

	}//Ending bracket if statement itemfound != 1
	
}//Ending bracket checkPrice function


void displayCart(const struct Cart* pShoppingCart)//function displaying cart

{//Beginning bracket displaying cart function



	//if (pShoppingCart->quantity >= 1)
	printf("\n=========================");
	printf("\nShopping Cart");
	printf("\n=========================");
	printf("\nSku:\tQty:\tPrice:");
	
	//if (pShoppingCart->size => 0)
	//
		
	//{
		
		
		
	for (int i = 0; i < pShoppingCart->size; i++)
			
	{
	if(pShoppingCart->quantity[i] >= 1 && pShoppingCart->size >= 0)	
	
	printf("\n%d\t%d\t%.2f", pShoppingCart->sku[i], pShoppingCart->quantity[i], pShoppingCart->price[i]);//print the item type
	
	}
	
	printf("\n=========================");


}//Ending bracket displaying cart function


void addCart(struct Cart* pShoppingCart, const int sku[], const float price[])//function adding cart

{//Beginning bracket adding cart function

int item, quantity;

printf("\nPlease enter the appropriate SKU number: ");
scanf("%d",&item);

int itemfound = searchInventory(sku, item);

while (itemfound == -1)
{
	printf("\nItem is not recognized in the shop! Please try again!");
	printf("\nEnter the appropriate SKU number:");
	scanf("%d", &item);
	itemfound = searchInventory(sku, item);
}

		if (itemfound != -1)
		{
			printf("\nQuantity:");
			scanf("\n%d", &quantity);
			
		pShoppingCart->sku[pShoppingCart->size] = sku[itemfound];

		pShoppingCart->quantity[pShoppingCart->size] = quantity;

		pShoppingCart->price[pShoppingCart->size] = price[itemfound];

		pShoppingCart->size = pShoppingCart->size ++;
	
		
		((*pShoppingCart).size)++;
		
		printf("\nItem is added.\n");
			
		}
	
}//Ending bracket adding cart function

    
void removeCart(struct Cart* pShoppingCart)//removing displaying cart

{//Beginning bracket removing cart function
	
	if(pShoppingCart -> size <= 0)
	{

	printf("\nThe cart is already empty!");
	
	}
	else 
		
			{
				for (int i = 0; i < pShoppingCart->size; i++)
				{
				pShoppingCart->sku[i] = 0;
				pShoppingCart->quantity[i] = 0;
	
				}
				pShoppingCart->size = 0;
				pShoppingCart->totalCost = 0;
				printf("The cart is succesfully removed!");
				
			}
			
}//Ending bracket checking out function


void checkout(struct Cart* pShoppingCart)//function checking out

{//Beginning bracket checking out function

pShoppingCart->totalCost = 0;

	for(int i = 0; i < pShoppingCart->size; i++)
		
		{	
	pShoppingCart->totalCost = pShoppingCart->totalCost + (pShoppingCart->price[i] * pShoppingCart->quantity[i]);
		}
		
		printf("\n=========================");	
			printf("\nTotal price sum = $%.2f",pShoppingCart->totalCost);
			printf("\n=========================");	
			
}//Ending bracket checking out function


int readInventory(const char filename[],int sku[],float price[])
{
	
	int i = 0;
	int status = 0;
	FILE *fp = fopen("inventory.dat","r");  //creating a file pointer
	
	//make fp point to week10.txt
	
	if(fp!=NULL)
		
		{
		//good pointer process the file, write the code here

		while(!feof(fp))//reading while its not the end of file
		{
		
		fscanf(fp,"%d, %f\n",&sku[i], &price[i]);
		i++;
		
		}
		fclose(fp);
	}
	
	else//bad pointer
	{
	
	status=1;	
	
	}
return status;
}



void printReceipt(const char filename[], struct Cart* pShoppingCart)


{
	
	

	FILE *fp=fopen(filename,"w");   //creating a file pointer

	
	if(fp!=NULL){
			
	fprintf(fp, "\n=========================");		
	fprintf(fp, "%s", "\nShopping Cart -- Receipt");
	fprintf(fp, "\n=========================");
	fprintf(fp, "%s", "\nSku:\tQty:\tPrice:\n");
	
	//if (pShoppingCart->size => 0)
	for (int i = 0; i < pShoppingCart->size; i++)
			
	{
		
	if(pShoppingCart->quantity[i] != 0)	
	
	{
	fprintf(fp, "\n%d\t%d\t%.2f", pShoppingCart->sku[i], pShoppingCart->quantity[i], pShoppingCart->price[i]);//print the item type
	
	}
		}
		
		pShoppingCart->totalCost = 0;

		for(int i = 0; i < pShoppingCart->size; i++)
		
		{
			
		pShoppingCart->totalCost = pShoppingCart->totalCost + (pShoppingCart->price[i] * pShoppingCart->quantity[i]);
		
		}
		
			fprintf(fp, "\n=========================");
			
			fprintf(fp, "\nTotal price sum = $%.2f",pShoppingCart->totalCost);
			
			fprintf(fp, "\n=========================\n");
			
		fclose(fp);	
			}

else
{
	printf("File can't be open!");
}

}