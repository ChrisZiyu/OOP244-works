#include <iostream>
#include "cstring.h"
#include "Bill.h"

using namespace std;

namespace sdds {

    void Bill::setEmpty() {
        deallocate();
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid() const {
        if (m_title[0] == '\0' || m_items == nullptr)
            return false;

        for (int i = 0; i < m_noOfItems; i++) {
            if (!m_items[i].isValid())
                return false;
        }

        return true;
    }

    double Bill::totalTax() const {
        double total = 0.0;

        for (int i = 0; i < m_noOfItems; i++) {
            total += m_items[i].tax();
        }

        return total;
    }

    double Bill::totalPrice() const {
        double total = 0.0;

        for (int i = 0; i < m_noOfItems; i++) {
            total += m_items[i].price();
        }

        return total;
    }

    void Bill::Title()const {
        cout << "+--------------------------------------+\n";
        if (isValid()) {
            cout.setf(ios::fixed);
            cout.setf(ios::left);

            cout << "| ";
            cout.width(36);
            cout << m_title << " |";

            cout.unsetf(ios::fixed);
        }
        else cout << "| Invalid Bill                         |";
        cout << '\n';

        cout << "+----------------------+---------+-----+\n"
            << "| Item Name            | Price   + Tax |\n"
            << "+----------------------+---------+-----+\n";
    }
    void Bill::footer()const {
        cout << "+----------------------+---------+-----+\n";
        if (isValid()) {
            cout.setf(ios::fixed);
            cout.setf(ios::right);

            cout << "|                Total Tax: ";
            cout.width(10); cout.precision(2);
            cout << totalTax() << " |\n";

            cout << "|              Total Price: ";
            cout.width(10); cout.precision(2);
            cout << totalPrice() << " |\n";

            cout << "|          Total After Tax: ";
            cout.width(10); cout.precision(2);
            cout << totalTax() + totalPrice() << " |";

            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
        }
        else cout << "| Invalid Bill                         |";

        cout << "\n+--------------------------------------+\n";
    }

    void Bill::init(const char* title, int noOfItems) {
        if (title == nullptr || noOfItems <= 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_noOfItems = noOfItems;
            m_items = new Item[m_noOfItems];
           
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        else {
            return false;
        }
    }

    void Bill::display() const {
        Title();

        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }

        footer();
    }

    void Bill::deallocate() {
        if (m_items) {
            delete[] m_items;
        }
        m_items = nullptr;
    }


} // namespace sdds