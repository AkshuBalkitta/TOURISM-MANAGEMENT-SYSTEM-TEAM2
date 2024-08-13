#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mynode {
	char name[20];
	char gen[6];
	int age;
	struct Passenger* link;
} Node;
Node* start = NULL;

struct Package{
	int code;
	char destination[50];
	int price;
};

//Functions
void heading();
void details();
void inter();
void india();
void receipt();

// Global variables
int num,amount;
char place[20],date[20];

void main()
{
	int choice;

	heading();

	printf("\n\t\t\t\t1. International "
		"Tour Packages\n");
	printf("\t\t\t\t2. India Tour Packages\n");
	printf("\t\t\t\tEnter Choice: ");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		inter();
		break;
		
	case 2:
		india();
		break;

	default:
		printf("\nEnter Right Choice...");
		break;
	}

	details();

	receipt();
}

void india()
{
	int package,i;

	// Clearing Screen
	system("cls");
	
	heading();
	
	struct Package ind[]={{1,"Goa",800},{2,"Shimla",1500},{3,"Uttar Pradesh",2000}};
	int n_ind=sizeof(ind)/sizeof(ind[0]);
	
	printf("\n\t\t\t\tIndia Tour Packages:");
	for(i=0;i<n_ind;i++){
	  printf("\n\t\t\t\t%d: %s-Rs.%d\nZ",ind[i].code,ind[i].destination,ind[i].price);
	}
	
	printf("\n\t\t\t\tEnter Choice: ");
	scanf("%d", &package);
	if (package == 1) {
		strcpy(place, "Goa Tour");
		amount = ind[package-1].price;
	}
	else if (package == 2) {
		strcpy(place, "Shimla Tour");
		amount = ind[package-1].price;
	}
	else if (package == 3) {
		strcpy(place, "UP Tour");
		amount = ind[package-1].price;
	}
	else
		printf("\nEnter Correct Choice...");
}

void inter()
{
	int package,i;

	// Clearing Screen
	system("cls");

	heading();
	
	struct Package intern[]={{1,"Paris",15000},{2,"London",12000},{3,"New York",20000}};
	int n_int=sizeof(intern)/sizeof(intern[0]);
	
	printf("\n\t\t\t\tInternational Tour Packages:");
	for(i=0;i<n_int;i++){
	  printf("\n\t\t\t\t%d: %s-Rs.%d\n",intern[i].code,intern[i].destination,intern[i].price);
	}
	
	printf("\n\t\t\t\tEnter Choice: ");
	scanf("%d", &package);
	if (package == 1) {
		strcpy(place, "Paris Tour");
		amount = intern[package-1].price;
	}
	else if (package == 2) {
		strcpy(place, "London Tour");
		amount = intern[package-1].price;
	}
	else if (package == 3) {
		strcpy(place, "New York Tour");
		amount = intern[package-1].price;
	}
	else
		printf("\nEnter Correct Choice...");
}

void details()
{
	int i, pass_age;
	char pass_name[20], gen[6];

	// Clearing Screen
	system("cls");

	heading();
	
	printf("\n\t\t\t\tEnter Number Of "
		"Passengers: ");
	scanf("%d", &num);
	printf("\n\t\t\t\tEnter Date "
		"(DD/MM/YY): ");
	fflush(stdin);
	gets(date);
	for (i = 1; i <= num; i++) {
		system("cls");
		heading();
		printf("\n\t\t\t\tEnter passenger %d name: ",
			i);
		fflush(stdin);
		gets(pass_name);
		printf("\n\t\t\t\tEnter passenger %d gender(F/M): ",
			i);
		fflush(stdin);
		gets(gen);
		printf("\n\t\t\t\tEnter passenger %d age: ",
			i);
		fflush(stdin);
		scanf("%d", &pass_age);

		// Calling add_node() function
		add_node(pass_name, gen, pass_age);
	}
}

// Node for each passenger
void add_node(char n[20],
			char g[6], int a)
{
	Node *newptr = NULL, *ptr;
	newptr = (Node*)malloc(sizeof(Node));
	strcpy(newptr->name, n);
	strcpy(newptr->gen, g);
	newptr->age = a;
	newptr->link = NULL;
	if (start == NULL)
		start = newptr;
	else {
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newptr;
	}
}

// Printing Receipt
void receipt()
{
	int i, bill;
	Node* ptr = start;
	system("cls");
	heading();
	printf("\n\t\t\t\t**Take Screenshot "
		"For Further Use**");
	printf("\n");
	for (i = 1; i <= num; i++) {
		printf("\n\t\t\t\tPassenger %d "
			"Name: ",
			i);
		puts(ptr->name);
		printf("\n\t\t\t\tPassenger %d "
			"Gender: ",
			i);
		puts(ptr->gen);
		printf("\n\t\t\t\tPassenger %d "
			"Age: %d\n\n",
			i, ptr->age);
		ptr = ptr->link;
	}
	printf("\n\t\t\t\tPackage: ");
	puts(place);
	printf("\n\t\t\t\tDate: ");
	puts(date);
	bill = amount * num;
	printf("\n\t\t\t\tTotal Amount: %d", bill);
	printf("\n");
	printf("\n\t\t\t\t**Thank You For "
		"registration**");
}

void heading()
{
	printf("\n\t\t\t\t***Tourism "
		"Management System***\n");
}

