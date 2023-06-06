#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}
	void Item::setEmpty() {
		m_itemName[0] = '\0';
		m_price = 0.0;
		m_taxed = false;
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (name != nullptr && price >= 0) {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}
	void Item::display()const {
		if (isValid()) {
			cout.setf(ios::fixed);
			cout.setf(ios::left);

			cout << "| ";
			cout.width(20);
			cout.fill('.');
			cout << m_itemName;
			cout << " | ";

			cout.setf(ios::right);
			cout.precision(2);
			cout.width(7);
			cout.fill(' ');
			cout << m_price << " | ";

			cout << (m_taxed ? "Yes" : "No ") << " |";

			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
		}
		else cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |";
		cout << '\n';
	}
	bool Item::isValid()const {
		return m_itemName[0] != '\0' && m_price >= 0.0;
	}
	double Item::price() const {
		return m_price;
	}

	double Item::tax() const {
		if (m_taxed)
			return m_price * TAX_RATE;
		else
			return 0.0;
	}


}