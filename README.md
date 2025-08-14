# 💧 Water Billing System

A comprehensive **Drinking Water Billing Management System** developed in **C programming language** for efficient customer management and automated bill generation.

---

## 📋 Table of Contents

- [💧 Water Billing System](#-water-billing-system)
  - [📋 Table of Contents](#-table-of-contents)
  - [🌟 Overview](#-overview)
  - [✨ Features](#-features)
    - [🏢 Customer Management](#-customer-management)
    - [💰 Billing System](#-billing-system)
    - [💾 Data Management](#-data-management)
    - [🎯 User Experience](#-user-experience)
  - [💻 System Requirements](#-system-requirements)
  - [🚀 Installation \& Setup](#-installation--setup)
    - [1️⃣ Download or Clone](#1️⃣-download-or-clone)

---

## 🌟 Overview

The **Water Billing System** is a console-based application designed to automate the process of **water bill generation** and **customer management** for water utility companies.  
It provides a simple yet effective way to:

- Manage customer data
- Track water consumption
- Generate accurate bills

**Developed by:** Rupesh Chaudhary  
**Course:** C Programming
**Institution:** Itahari Namuna College(INC)
**Language:** C Programming  
**Platform:** Cross-platform (Windows / Linux / macOS)

---

## ✨ Features

### 🏢 Customer Management

- ➕ **Add New Customers** with auto-generated unique IDs
- 👥 **View All Customers** in tabular format
- 🔍 **Customer Validation** during billing

### 💰 Billing System

- 📊 **Generate Bills** with tiered rate calculation
- 📈 **Meter Reading Tracking** (previous & current)
- 💵 **Automatic Calculation** based on usage tiers
- 📋 **Bill History** for all customers

### 💾 Data Management

- 📁 **File-Based Storage** (`customers.txt`, `bills.txt`)
- 🔄 **Auto File Creation** if missing
- 📊 **Structured Data Format** with error handling

### 🎯 User Experience

- 🖥 **Interactive Menu**
- ⚡ **Real-Time Processing**
- 🛡 **Error Handling** with input validation

---

## 💻 System Requirements

**Minimum:**

- **OS:** Windows 7/8/10/11, Linux, macOS
- **Compiler:** GCC (GNU Compiler Collection)
- **RAM:** 512 MB
- **Storage:** 10 MB free
- **Processor:** Any x86/x64

**Development Environment:**

- **IDE/Editor:** VS Code, Dev-C++, Code::Blocks, or any text editor
- **C Standard:** C99+
- **Compiler Version:** GCC 4.8+ recommended

---

## 🚀 Installation & Setup

### 1️⃣ Download or Clone

```bash
git clone https://github.com/yourusername/water-billing-system.git
```

=== DRINKING WATER BILLING SYSTEM ===

=== MAIN MENU ===

1. Add New Customer
2. View All Customers
3. Generate Bill
4. View Customer Bills
5. # Exit
   Enter your choice:

=== ADD NEW CUSTOMER ===
Customer ID: 1001 (Auto-generated)
Enter Customer Name: John Smith
Enter Address: 123 Main Street
Enter Phone Number: +1-234-567-8900

Customer added successfully!

=== GENERATE BILL ===
Enter Customer ID: 1001
Customer: John Smith
Enter Month (1-12): 12
Enter Year: 2023
Enter Previous Reading: 1500
Enter Current Reading: 1750

=== BILL GENERATED ===
Units Consumed: 250
Amount: Rs. 650.00

| Units   | Rate (₹/Unit) |
| ------- | ------------- |
| 0–100   | ₹2.00         |
| 101–300 | ₹3.00         |
| 301+    | ₹5.00         |


Copyright (c) 2025 Rupesh Chaudhary.
Educational use only. All rights reserved.
