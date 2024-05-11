//PHONEBOOK
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{
	struct Phonebook
	{
	    char name[50];
	    int age;
	    char address[100];
	    char phone[15];
	};
	int serial_to_delete;
	int n,c;
	char ch;
	struct Phonebook *people;
	printf(" Welcome to PHONEBOOK!! :)\n ");
	int num_people;
    printf("Enter the number of people: ");
    scanf("%d", &num_people); 
	people = (struct Phonebook *)malloc(num_people * sizeof(struct Phonebook));
    if (people == NULL) {
        printf("\nMemory allocation failed. Exiting...\n");
        return 1;
    }
    int *serial_numbers = (int *)malloc(num_people * sizeof(int));
    if (serial_numbers == NULL) {
        printf("\nMemory allocation failed. Exiting...\n");
        free(people);
        return 1;
    }
    
	int i=0;
	while(1){
		printf("\nEnter your choice:\n1.Add A phone number\n2.Delete a number\n3.Display a particular number\n Press ? to exit\nEnter: ");
		scanf("%ch",&ch);
		switch(ch)
		{
			case '1': 
					if(i>num_people)
					printf("\n Phonebook does not have more space to add!!");
					else
					{
						serial_numbers[i] = i + 1; // Serial numbers start from 1
				
				        printf("\nEnter details for Person %d:\n", serial_numbers[i]);
				        printf("Name: ");
				        scanf("%s", people[i].name);
				        printf("Age: ");
				        scanf("%d", &people[i].age);
				        printf("Address: ");
				        scanf("%s", people[i].address);
				        printf("Phone: ");
				        scanf("%s", people[i].phone);
				        i++;
					}
					break;
			case '2':
				    printf("\nEnter the serial number of the person you want to delete: ");
				    scanf("%d", &serial_to_delete);
				
				    int delete_index = -1; // Index to delete
				
				    // Finding the index of the person to delete
				    for (int i = 0; i < num_people; i++) {
				        if (serial_numbers[i] == serial_to_delete) {
				            delete_index = i;
				            break;
				        }
				
				    if (delete_index == -1)
				        printf("Person with serial number %d not found.\n", serial_to_delete);
					else 
					{
				        // Shift elements after the delete_index one position to the left
				        for (int i = delete_index; i < num_people - 1; i++) {
				            people[i] = people[i + 1];
				            serial_numbers[i] = serial_numbers[i + 1];
				        }
				
				        // Decrease the count of people by one
				        num_people--;
				
				        printf("Person with serial number %d deleted successfully.\n", serial_to_delete);
				    }

					break;
			case '3':
					printf("\nEnter the particular serial number of the person you want the details about:\n");
					scanf("%d",&n);
					printf("\nPerson %d:\n", serial_numbers[n-1]);
			        printf("Name: %s\n", people[n-1].name);
			        printf("Age: %d\n", people[n-1].age);
			        printf("Address: %s\n", people[n-1].address);
			        printf("Phone: %s\n", people[n-1].phone);
					break;
			case '?':
					printf("Sure you want to exit press 1 to yess or else 0:\n Enter");
					scanf("%d",&c);
					if(c==1)
					{
						exit(0);
					}	
					else
					printf("Great continue your search!");
					break;	
			default: 
					break;
		}
	}
	}
	return 0;
}