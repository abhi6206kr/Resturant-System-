# Resturant-System
# Resturant System

## Project Overview

The **Restaurant System** project is a comprehensive solution for managing restaurant operations. This system includes modules for billing, displaying menu items, managing product inventory, and handling shopping cart functionality. The project is written in C and provides a console-based interface for ease of use.

## Modules

### Bill Module

This module handles the billing process for the restaurant. It allows for the calculation of total costs based on selected menu items and quantities.

**File:** `Bill Module.c`

### Display Module

This module is responsible for displaying the available menu items to the user. It reads the product information from a file and prints it in a formatted manner.

**File:** `Display Module.C`

### Product Management

This module allows for the creation and management of product records. It includes functionality to add new products, update existing ones, and display all products.

**File:** `product_management.c`

### Shopping Cart

This module manages the shopping cart functionality. It allows users to add items to their cart, view the cart, and generate an invoice.

**File:** `shopping_cart.c`

### Restaurant System Main

This file serves as the main entry point for the restaurant system. It integrates all the modules and provides a user-friendly interface for the restaurant operations.

**File:** `Resturant.c`

## How to Run

Compile the Code:
gcc product_management.c -o product_management
gcc Bill\ Module.c -o bill_module
gcc Display\ Module.C -o display_module
gcc shopping_cart.c -o shopping_cart
gcc Resturant.c -o resturant



Run the Program:
./resturant

File Descriptions
Bill Module.c: Handles billing operations.
Display Module.C: Displays menu items.
product_management.c: Manages product inventory.
shopping_cart.c: Manages the shopping cart and generates invoices.
Resturant.c: Main entry point that integrates all modules.


Future Enhancements
Add a graphical user interface (GUI) for a better user experience.
Integrate with a database for persistent storage of menu items and orders.
Implement user authentication for secure access to the system.




License
This project is licensed under the MIT License. See the LICENSE file for details.
