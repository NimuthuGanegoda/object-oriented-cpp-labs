#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Overloading operators for a simple list application
// Martin Masek - ECU, 2024

// class to represent an item that might be sold in a store
class StoreItem
{
    string name;           // name of the item
    int quantity;           // how many of this item the store has

public:
    // simple constructor - for an item with a quantity that defaults to 1 if only 1 argument provided
    StoreItem(string name, int quantity = 1)
    {
        this->name = name;
        this->quantity = quantity;
    }

    int getQuantity()
    {
        return quantity;
    }

    string getName()
    {
        return name;
    }

    // postfix overloaded operators ++ and --
    void operator++(int)
    {
        quantity++;
    }

    void operator--(int)
    {
        quantity--;
    }

    void operator+=(StoreItem x)
    {
        quantity += x.getQuantity();
    }
};

// For keeping track of all the items in a store
class StoreStock
{
protected:
    vector<StoreItem> stock;           // holds all the items in the store

public:
    // list the items in the store and their quantities
    void stockTake()
    {
        cout << "These are the items in the store: \n\n";
        cout << "Item Name\t|\tQuantity\n";
        cout << "-------------------------------------\n";
        for (StoreItem i : stock)
        {
            cout << i.getName() << "\t\t|\t" << i.getQuantity() << "\n";
        }
    }

    // add an item to the store
    void addItem(StoreItem newItem)
    {
        stock.push_back(newItem);
    }
};

ostream& operator<<(ostream& out, StoreStock& stock)
{
    stock.stockTake();
    return out;
}

// BetterStoreStork - A more polished version of StoreStock
// An example of using inheritence - this protects the original class from change
// (ie. existing programs that use the base class StoreStock will not be affected)
// whilst still allowing the class to be extended.
class BetterStoreStock : public StoreStock
{
public:
    // add an item to the store (override)
    // input: StoreItem newItem - the item to be added
    // function: If an item by the name newItem.getName() already exists in the stock vector, update its quantity
    // otherwise add the newItem to the stock vector.
    void addItem(StoreItem newItem)
    {
        // check if the named item exists
        bool itemFound = false;
        // Need reference to modify 'i' in the vector
        for (StoreItem& i : stock)
        {
            if (i.getName() == newItem.getName())
            {
                // the item is in the store, update the quantity
                i += newItem;
                itemFound = true;
                break;
            }
        }

        if (!itemFound)
        {
            // add a new item, since we dont have such an item in the store.
            StoreStock::addItem(newItem);           // calling the parent version of addItem
        }
    }

    // overloaded += to make adding items more intutitive
    void operator+=(StoreItem newItem)
    {
        addItem(newItem);
    }
};

int main()
{
    BetterStoreStock petStore;
    petStore.addItem(StoreItem("dog"));           // adding 1 dog
    petStore.addItem(StoreItem("cat"));
    petStore.addItem(StoreItem("dog"));
    petStore.addItem(StoreItem("dog", 5));           // adding dogs
    petStore.addItem(StoreItem("dog"));

    petStore += StoreItem("dog");

    cout << petStore;
    return 0;
}
