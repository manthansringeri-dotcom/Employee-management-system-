#include <stdio.h>
#include <string.h>

struct Employee
{
int id;
char name[50];
float salary;
};

struct Employee emp[1000];
int count = 0;

void addEmployee()
{
if (count < 1000)
{
printf("\nEnter Employee ID: ");
scanf("%d", &emp[count].id);

    printf("Enter Employee Name: ");
    scanf("%50s", emp[count].name);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp[count].salary);

    count++;

    printf("\nEmployee Added Successfully!\n");
}
else
{
    printf("\nEmployee Limit Reached\n");
}

}

void displayEmployees()
{
int i;

if (count == 0)
{
    printf("\nNo Employees Found!\n");
    return;
}

printf("\n===== EMPLOYEE DETAILS =====\n");

for (i = 0; i < count; i++)
{
    printf("\nEmployee ID: %d", emp[i].id);
    printf("\nEmployee Name: %s", emp[i].name);
    printf("\nEmployee Salary: %.2f\n", emp[i].salary);
}

}

void deleteEmployee()
{
int id, i, j, found = 0;

printf("\nEnter Employee ID to Delete: ");
scanf("%d", &id);

for (i = 0; i < count; i++)
{
    if (emp[i].id == id)
    {
        for (j = i; j < count - 1; j++)
        {
            emp[j] = emp[j + 1];
        }

        count--;
        found = 1;
        break;
    }
}

if (found == 1)
    printf("\nEmployee Deleted Successfully!\n");
else
    printf("\nEmployee Not Found!\n");

}

int main()
{
char username[30];
char password[30];
int choice;

printf("===== LOGIN =====\n");

printf("Enter Username: ");
scanf("%29s", username);

printf("Enter Password: ");
scanf("%29s", password);

if (strcmp(username, "bca") == 0 &&
    strcmp(password, "2026") == 0)
{
    printf("\nLogin Successful!\n");

    while (1)
    {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                deleteEmployee();
                break;

            case 4:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}
else
{
    printf("\nInvalid Username or Password!\n");
}

return 0;

}
