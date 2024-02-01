#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// -----typedefs -------

typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.

void write_new_file(PERSON *inrecord); // Creates a file and

// writes the first record
void printfile(void); // Prints out all persons in the file

void search_by_firstname(char *name); // Prints out the person if
// in list
void append_file(PERSON *inrecord); // appends a new person to the file

int main(void)
{
    PERSON ppost;
    PERSON *ptrPpost = &ppost;
    int input = 0;
    char name[20];

    while (input != 5)
    {
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");
        scanf("%d", &input);

        if (input == 1)
        {
            write_new_file(ptrPpost);
        }
        else if (input == 2)
        {
            append_file(ptrPpost);
        }
        else if (input == 3)
        { 
    

            printf("Search: ");
            scanf("%19s", name); // Using %19s to prevent buffer overflow
            

            // Clear input buffer again
            while (getchar() != '\n');
                
            search_by_firstname(name);
        }
        else if (input == 4)
        {
            printfile();
        }
        else if (input > 5)
        {
            printf("Choose a number between 1-4\n");
        }
    }

    return 0;
}
void write_new_file(PERSON *inrecord)
{
    FILE *fptr;
    PERSON dummy;
    // Check if the file already exists
    fptr = fopen("filename.bin", "rb");

    strncpy(dummy.firstname, "Josef", sizeof(dummy.firstname) - 1);
    dummy.firstname[sizeof(dummy.firstname) - 1] = '\0'; // Explicitly null-terminate

    strncpy(dummy.famname, "almasri", sizeof(dummy.famname) - 1);
    dummy.famname[sizeof(dummy.famname) - 1] = '\0'; // Explicitly null-terminate

    strncpy(dummy.pers_number, "20000", sizeof(dummy.pers_number) - 1);
    dummy.pers_number[sizeof(dummy.pers_number) - 1] = '\0'; // Explicitly null-terminate

    if (fptr)
    {
        // File exists, close it
        fclose(fptr);

        // Delete the file
        remove("filename.bin");
    }

    // Open the file in "wb" mode to create a new file for writing
    fptr = fopen("filename.bin", "wb");

    if (!fptr)
    {
        printf("Cannot open file for writing.\n");
        return;
    }

    // Write the record to the file
    fwrite(&dummy, sizeof(PERSON), 1, fptr);

    // Close the file
    fclose(fptr);
}

void printfile(void)
{
    FILE *fptr;
    PERSON person;

    // Open the binary file in "rb" mode for reading
    fptr = fopen("filename.bin", "rb");
    if (!fptr)
    {
        printf("Cannot open file for reading.\n");
        return;
    }

    // Read and print each record until the end of the file
    while (fread(&person, sizeof(PERSON), 1, fptr) == 1)
    {
        printf("First Name: %s\n", person.firstname);
        printf("Last Name: %s\n", person.famname);
        printf("Personal Number: %s\n", person.pers_number);
        printf("\n"); // Print a new line for readability between records
    }

    // Close the file
    fclose(fptr);
}

void search_by_firstname(char *name)
{
    int found = 0; // Flag to track if the name was found

    do
    {
        FILE *fptr;
        PERSON person;

        // Open the binary file in "rb" mode for reading
        fptr = fopen("filename.bin", "rb");
        if (!fptr)
        {
            printf("Cannot open file for reading.\n");
            return;
        }

        while (fread(&person, sizeof(PERSON), 1, fptr) == 1)
        {
            if (strcmp(name, person.famname) == 0 || strcmp(name, person.firstname) == 0)
            {
                printf("First Name: %s\n", person.firstname);
                printf("Last Name: %s\n", person.famname);
                printf("Personal Number: %s\n", person.pers_number);
                found = 1;
                break; // Break after finding the name
            }
        }

        // Close the file
        fclose(fptr);

        if (!found)
        {
            printf("No person with that name.\n");

            int choice;
            printf("Search or go back by pressing 0: ");
            scanf("%d", &choice);

            if (choice == 0)
            {
                return; // Exit the function to go back to the main menu
            }
            else
            {
                printf("Enter a new name to search: ");
                scanf("%19s", name); // Using %19s to prevent buffer overflow
            }
        }

    } while (!found);
}

void append_file(PERSON *inrecord)
{
    FILE *fptr;

    fptr = fopen("filename.bin", "ab");
    if (!fptr)
    {
        printf("Error opening file for appending.\n");
        return;
    }
    printf("Provide firstname: \n");
    scanf("%19s", inrecord->firstname);

    printf("Provide lastname: \n");
    scanf("%19s", inrecord->famname);

    printf("Provide personNumber: \n");
    scanf("%12s", inrecord->pers_number);

    fwrite(inrecord, sizeof(PERSON), 1, fptr);

    fclose(fptr);
}