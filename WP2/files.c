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

void search_by_firstname(char *name, int *ptrChoice); // Prints out the person if
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
            int choice = 0;
            int *ptrChoice = &choice;
            printf("1: Search for a firstname\n");
            printf("2: Search for a famName\n");
            scanf("%d", ptrChoice);
            printf("Search: ");
            scanf("%19s", name); // Using %19s to prevent buffer overflow
            search_by_firstname(name, ptrChoice);
        }
        else if (input == 4)
        {
            printfile();
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
    // Initialize the dummy data
    strcpy(dummy.firstname, "Josef");
    strcpy(dummy.famname, "almasri");
    strcpy(dummy.pers_number, "20000");

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
}

void search_by_firstname(char *name, int *ptrChoice)
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

    int found = 0; // Flag to track if the name was found

    while (*ptrChoice != 1 && *ptrChoice != 2)
    {

        if (*ptrChoice == 1)
        {
            while (fread(&person, sizeof(PERSON), 1, fptr) == 1)
            {
                if (strcmp(name, person.firstname) == 0)
                {
                    printf("First Name: %s\n", person.firstname);
                    printf("Last Name: %s\n", person.famname);
                    printf("Personal Number: %s\n", person.pers_number);
                    found = 1;
                }

            }
        }
        else if (*ptrChoice == 2)
        {
            while (fread(&person, sizeof(PERSON), 1, fptr) == 1)
            {
                if (strcmp(name, person.famname) == 0)
                {
                    printf("First Name: %s\n", person.firstname);
                    printf("Last Name: %s\n", person.famname);
                    printf("Personal Number: %s\n", person.pers_number);
                    found = 1;
                }
            }
        }

        if (!found)
        {
            printf("No person with that name.\n");
        }

        // Seek back to the beginning of the file for another search
        rewind(fptr);
    }

    // Close the file
    fclose(fptr);
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