#pragma once

#include<iostream>

using namespace std;


struct Admin {
	char* username;
	char* password;
};

struct Product {
	char* name;
	double price;
	double discount;
};

struct ProductItem {
	Product product;
	int quantity;
};

struct Order {
	ProductItem item;
	bool accepted = false;
	bool hasRed = false;
};

struct Database {
	Admin** admins;
	int admin_count = 0;
	ProductItem** items;
	int item_count = 0;
	Order** orders;
	int order_count = 0;
};


