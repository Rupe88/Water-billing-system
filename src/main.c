#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store customer information
struct Customer {
    int id;
    char name[50];
    char address[100];
    char phone[15];
};

// Structure to store bill information
struct Bill {
    int customer_id;
    int month;
    int year;
    int previous_reading;
    int current_reading;
    int units_consumed;
    float amount;
};

// Function declarations
void addCustomer();
void viewCustomers();
void generateBill();
void viewBills();
void displayMenu();
int calculateBillAmount(int units);
int getLastCustomerId();
void createDataFiles();

int main() {
    int choice;
    
    // Create data files if they don't exist
    createDataFiles();
    
    printf("=== DRINKING WATER BILLING SYSTEM ===\n\n");
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                viewCustomers();
                break;
            case 3:
                generateBill();
                break;
            case 4:
                viewBills();
                break;
            case 5:
                printf("Thank you for using Water Billing System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        if(choice != 5) {
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
        }
        
    } while(choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\n=== MAIN MENU ===\n");
    printf("1. Add New Customer\n");
    printf("2. View All Customers\n");
    printf("3. Generate Bill\n");
    printf("4. View Customer Bills\n");
    printf("5. Exit\n");
    printf("==================\n");
}

void createDataFiles() {
    FILE *file;
    
    // Create customers.txt if it doesn't exist
    file = fopen("data/customers.txt", "a");
    if(file != NULL) {
        fclose(file);
    }
    
    // Create bills.txt if it doesn't exist
    file = fopen("data/bills.txt", "a");
    if(file != NULL) {
        fclose(file);
    }
}

void addCustomer() {
    struct Customer customer;
    FILE *file;
    
    printf("\n=== ADD NEW CUSTOMER ===\n");
    
    customer.id = getLastCustomerId() + 1;
    
    printf("Customer ID: %d (Auto-generated)\n", customer.id);
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", customer.name);
    printf("Enter Address: ");
    scanf(" %[^\n]", customer.address);
    printf("Enter Phone Number: ");
    scanf(" %[^\n]", customer.phone);
    
    file = fopen("data/customers.txt", "a");
    if(file == NULL) {
        printf("Error: Unable to open customers file!\n");
        return;
    }
    
    fprintf(file, "%d|%s|%s|%s\n", customer.id, customer.name, customer.address, customer.phone);
    fclose(file);
    
    printf("\nCustomer added successfully!\n");
    printf("Customer ID: %d\n", customer.id);
}

void viewCustomers() {
    FILE *file;
    struct Customer customer;
    char line[200];
    
    printf("\n=== ALL CUSTOMERS ===\n");
    printf("%-5s %-20s %-30s %-15s\n", "ID", "Name", "Address", "Phone");
    printf("---------------------------------------------------------------------\n");
    
    file = fopen("data/customers.txt", "r");
    if(file == NULL) {
        printf("No customers found!\n");
        return;
    }
    
    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%[^|]|%[^|]|%[^\n]", &customer.id, customer.name, customer.address, customer.phone);
        printf("%-5d %-20s %-30s %-15s\n", customer.id, customer.name, customer.address, customer.phone);
    }
    
    fclose(file);
}

void generateBill() {
    struct Bill bill;
    FILE *file;
    int found = 0;
    struct Customer customer;
    char line[200];
    
    printf("\n=== GENERATE BILL ===\n");
    
    printf("Enter Customer ID: ");
    scanf("%d", &bill.customer_id);
    
    // Check if customer exists
    file = fopen("data/customers.txt", "r");
    if(file == NULL) {
        printf("No customers found!\n");
        return;
    }
    
    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%[^|]|%[^|]|%[^\n]", &customer.id, customer.name, customer.address, customer.phone);
        if(customer.id == bill.customer_id) {
            found = 1;
            break;
        }
    }
    fclose(file);
    
    if(!found) {
        printf("Customer not found!\n");
        return;
    }
    
    printf("Customer: %s\n", customer.name);
    printf("Enter Month (1-12): ");
    scanf("%d", &bill.month);
    printf("Enter Year: ");
    scanf("%d", &bill.year);
    printf("Enter Previous Meter Reading: ");
    scanf("%d", &bill.previous_reading);
    printf("Enter Current Meter Reading: ");
    scanf("%d", &bill.current_reading);
    
    if(bill.current_reading < bill.previous_reading) {
        printf("Error: Current reading cannot be less than previous reading!\n");
        return;
    }
    
    bill.units_consumed = bill.current_reading - bill.previous_reading;
    bill.amount = calculateBillAmount(bill.units_consumed);
    
    // Save bill to file
    file = fopen("data/bills.txt", "a");
    if(file == NULL) {
        printf("Error: Unable to open bills file!\n");
        return;
    }
    
    fprintf(file, "%d|%d|%d|%d|%d|%d|%.2f\n", 
            bill.customer_id, bill.month, bill.year, 
            bill.previous_reading, bill.current_reading, 
            bill.units_consumed, bill.amount);
    fclose(file);
    
    printf("\n=== BILL GENERATED ===\n");
    printf("Customer: %s\n", customer.name);
    printf("Month/Year: %d/%d\n", bill.month, bill.year);
    printf("Previous Reading: %d\n", bill.previous_reading);
    printf("Current Reading: %d\n", bill.current_reading);
    printf("Units Consumed: %d\n", bill.units_consumed);
    printf("Amount: Rs. %.2f\n", bill.amount);
}

void viewBills() {
    FILE *file;
    struct Bill bill;
    struct Customer customer;
    char line[200];
    char customer_line[200];
    int customer_id;
    
    printf("\n=== ALL BILLS ===\n");
    printf("%-5s %-20s %-8s %-6s %-10s %-10s %-8s %-10s\n", 
           "CID", "Customer", "Month", "Year", "Prev", "Curr", "Units", "Amount");
    printf("--------------------------------------------------------------------------------\n");
    
    file = fopen("data/bills.txt", "r");
    if(file == NULL) {
        printf("No bills found!\n");
        return;
    }
    
    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%d|%d|%d|%d|%d|%f", 
               &bill.customer_id, &bill.month, &bill.year,
               &bill.previous_reading, &bill.current_reading,
               &bill.units_consumed, &bill.amount);
        
        // Find customer name
        FILE *customer_file = fopen("data/customers.txt", "r");
        strcpy(customer.name, "Unknown");
        
        if(customer_file != NULL) {
            while(fgets(customer_line, sizeof(customer_line), customer_file)) {
                sscanf(customer_line, "%d|%[^|]|%[^|]|%[^\n]", 
                       &customer.id, customer.name, customer.address, customer.phone);
                if(customer.id == bill.customer_id) {
                    break;
                }
            }
            fclose(customer_file);
        }
        
        printf("%-5d %-20s %-8d %-6d %-10d %-10d %-8d Rs.%-7.2f\n",
               bill.customer_id, customer.name, bill.month, bill.year,
               bill.previous_reading, bill.current_reading,
               bill.units_consumed, bill.amount);
    }
    
    fclose(file);
}

int calculateBillAmount(int units) {
    int amount = 0;
    
    // Water billing rate structure
    if(units <= 100) {
        amount = units * 2;  // Rs. 2 per unit for first 100 units
    }
    else if(units <= 300) {
        amount = (100 * 2) + ((units - 100) * 3);  // Rs. 3 per unit for next 200 units
    }
    else {
        amount = (100 * 2) + (200 * 3) + ((units - 300) * 5);  // Rs. 5 per unit beyond 300 units
    }
    
    return amount;
}

int getLastCustomerId() {
    FILE *file;
    int last_id = 0;
    int current_id;
    char line[200];
    char name[50], address[100], phone[15];
    
    file = fopen("data/customers.txt", "r");
    if(file == NULL) {
        return 0;
    }
    
    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%d|%[^|]|%[^|]|%[^\n]", &current_id, name, address, phone);
        if(current_id > last_id) {
            last_id = current_id;
        }
    }
    
    fclose(file);
    return last_id;
}