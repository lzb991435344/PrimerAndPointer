
//1
#ifndef BASKET_H
#define BASKET_H

#include "Version_test.h"

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <memory>
#include "Quote.h"

// holds items being purchased
class Basket {
public:
#ifdef IN_CLASS_INITS
	// Basket uses synthesized default constructor and copy-control members
#else
	Basket() : items(compare) { }
#endif
	void add_item(const std::shared_ptr<Quote> &sale)  
        { items.insert(sale); }

	void add_item(const Quote& sale) // copy the given object
      { items.insert(std::shared_ptr<Quote>(sale.clone())); }

	void add_item(Quote&& sale)      // move the given object
      { items.insert(
	      std::shared_ptr<Quote>(std::move(sale).clone())); }

    // prints the total price for each book 
	// and the overall total for all items in the basket
    double total_receipt(std::ostream&) const;

	// for debugging purposes, prints contents of the basket
	void display (std::ostream&) const;
private:
	// function to compare shared_ptrs needed by the multiset member
	static bool compare(const std::shared_ptr<Quote> &lhs,
	                    const std::shared_ptr<Quote> &rhs)
		{ return lhs->isbn() < rhs->isbn(); }

	// multiset to hold multiple quotes, ordered by the compare member
#ifdef IN_CLASS_INITS
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> 
	              items{compare}; 
#else
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items;
#endif
};

#endif
