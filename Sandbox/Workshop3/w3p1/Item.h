#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    const double TAX_RATE = 0.13;

    class Item {

        char m_itemName[21] = {};
        double m_price = 0.0;
        bool m_taxed = false;
        void setName(const char* name);

    public:

        void setEmpty();
        void set(const char* name, double price, bool taxed);
        void display()const;
        bool isValid()const;
        double price()const;
        double tax()const;
    };
}

#endif // !SDDS_SUBJECT_H
