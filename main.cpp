/////////////////////
// Matthew Barham
// 2022-04-03
///////////////////////////////////////////////////////////////////
// New House Annual Mortgage
//
// Calculates the annual mortgage and tax savings of a new house
// by a provided price and down payment.
///////////////////////////////////////////////////////////////////

#include <iostream>

double tax_savings(double);

double cost(double, double);

int main() {
    while (true) {
        double house_price{};
        double down_payment{};

        std::cout << "Please enter the price of your house (or 0 to quit): ";
        std::cin >> house_price;

        if (house_price == 0) break;

        std::cout << "\nPlease enter the down payment: ";
        std::cin >> down_payment;

        double first_year_annual_mortgage_principal{0.03 * (house_price - down_payment)};
        double first_year_annual_mortgage_interest{0.06 * (house_price - down_payment)};
        double total_annual_mortgage_cost{first_year_annual_mortgage_principal + first_year_annual_mortgage_interest};

        std::cout.setf(std::ios::fixed);
        std::cout.setf(std::ios::showpoint);
        std::cout.precision(2);
        std::cout << "\nYour first year annual mortgage principal is: $" << first_year_annual_mortgage_principal
                  << std::endl;
        std::cout << "Your first year annual mortgage interest is: $" << first_year_annual_mortgage_interest
                  << std::endl;
        std::cout << "Your total annual mortgage cost is: $" << total_annual_mortgage_cost << std::endl;
        std::cout << "Your tax savings are: $" << tax_savings(first_year_annual_mortgage_interest) << std::endl;
        std::cout << "Your after-tax cost is $"
                  << cost(total_annual_mortgage_cost,
                          tax_savings(first_year_annual_mortgage_interest))
                  << " annually." << std::endl;
    }

    return 0;
}

double tax_savings(double first_year_interest) {
    return first_year_interest * 0.35;
}

double cost(double mortgage_cost, double tax_savings) {
    return mortgage_cost - tax_savings;
}
