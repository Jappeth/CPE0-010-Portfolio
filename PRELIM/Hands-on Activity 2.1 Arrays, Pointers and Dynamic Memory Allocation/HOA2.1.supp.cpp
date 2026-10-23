#include <iostream>
#include <string.h>
#include <iomanip>

//OOP time...

class Item{ //parent class
    protected: // default members for children
        std::string itemName; 
        float itemPrice;
        int itemQuantity;
    public:
        //constructor
        Item(std::string newName = "", float newPrice = 0.0, int newQuantity = 0) {
            itemName = std::move(newName);
            itemPrice = newPrice;
            itemQuantity = newQuantity;
            std::cout << "Item constructor called!\n";
        }

        //destructor
        virtual ~Item() { //virtual to clean child class along with parent
            std::cout << "Deleting item '" << itemName << "'\n";
        }

        Item(const Item& other) { //copy constructor for item class
            itemName = other.itemName;
            itemPrice = other.itemPrice;
            itemQuantity = other.itemQuantity;
            std::cout << "Item Copy Constructor called\n";
        }

        Item& operator=(const Item& other) { //copy assignment operator for item class
            std::cout << "Item Copy Assignment Operator called\n";
            if (this != &other) {
                itemName = other.itemName;
                itemPrice = other.itemPrice;
                itemQuantity = other.itemQuantity;
            }
            return *this;
        }

        float sumPrice() { //basic multiplication for price of each item type
            return this->itemPrice * this->itemQuantity;
        }

        void printDetails() { //print details for each item
            std::cout << std::left << std::setw(15) //formatting for nice output
            << this->itemName 
            << "\tPhp: " << this->itemPrice 
            << "\tAmount: x" << this->itemQuantity
            << "\tTotal Price: Php " << this->sumPrice() << '\n';
        }
};

class Fruit : public Item { //child class for fruit
public:
    Fruit(std::string newName = "", float newPrice = 0.0, int newQuantity = 0) {//constructor for fruit class
        itemName = std::move(newName);
        itemPrice = newPrice;
        itemQuantity = newQuantity;
        std::cout << "Fruit constructor called!\n";
    }

    ~Fruit() override { //override to clean child class along with parent
        std::cout << "Fruit destructor called!\n";
    }

    Fruit(const Fruit& other) : Item(other) { //copy constructor for fruit class
        std::cout << "Fruit Copy Constructor called\n";
    }

    Fruit& operator=(const Fruit& other) { //copy assignment operator for fruit class
        std::cout << "Fruit Copy Assignment Operator called\n";
        if (this != &other) {
            Item::operator=(other);
        }
        return *this;
    }

    float fruitTotal() { //function to calculate total price of fruits
        return this->itemPrice * this->itemQuantity;
    }
};

class Vegetable : public Item { //child class for vegetable
public:
    Vegetable(std::string newName = "", float newPrice = 0.0, int newQuantity = 0) {//constructor for vegetable class
        itemName = std::move(newName);
        itemPrice = newPrice;   
        itemQuantity = newQuantity;
        std::cout << "Vegetable constructor called!\n";
    }

    ~Vegetable() override { //override to clean child class along with parent
        std::cout << "Vegetable destructor called!\n";
    }

    Vegetable(const Vegetable& other) : Item(other) { //copy constructor for vegetable class
        std::cout << "Vegetable Copy Constructor called\n";
    }

    Vegetable& operator=(const Vegetable& other) { //copy assignment operator for vegetable class
        std::cout << "Vegetable Copy Assignment Operator called\n";
        if (this != &other) {
            Item::operator=(other);
        }
        return *this;
    }

    float vegetableTotal() { //function to calculate total price of vegetables
        return this->itemPrice * this->itemQuantity;
    }

};

float TotalSum(Item* GroceryList[]) { //function TotalSum that will calculate the sum of all objects
    float totalPrice = 0.0;
    for(int i = 0; i < 4; i++) {
        totalPrice += GroceryList[i]->sumPrice();
    }
    return totalPrice;
}

int main() {
    Item* GroceryList[4] = {}; //array of pointers to Item objects
    
    GroceryList[0] = new Fruit("Apple", 10, 7); //creating objects in the heap and assigning them to the array of pointers
    GroceryList[1] = new Fruit("Banana", 10, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50, 10);

    //Printing the details of each item in the grocery list
    std::cout << std::endl;
    for (int i = 0; i < 4; i++) {
        GroceryList[i]->printDetails();
    }

    //Total price
    std::cout << "\nTotal Price: Php " << TotalSum(GroceryList) << '\n';

    //Delete the Lettuce from Jenna’s GroceryList list and de-allocate the memory assigned.
    if (GroceryList[3] != nullptr) {
        delete GroceryList[3];
        GroceryList[3] = nullptr;
    }

    std::cout << std:: endl;
    for (int i = 0; i < 4; i++) {//deleting the objects in the heap and de-allocating the memory assigned
        if (GroceryList[i] != nullptr) {
            delete GroceryList[i];
            GroceryList[i] = nullptr;
        }
    }

    return 0;
}