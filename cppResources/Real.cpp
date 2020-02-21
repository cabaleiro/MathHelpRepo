#pragma once
#include <vector>
#include <string>

class Real {

	std::vector<unsigned int> natural;
	std::vector<unsigned int> decimal;
public:
	Real(std::string input) {
		//look for , and iterate natural and decimal
	}
	Real(std::vector<unsigned int> _n, std::vector<unsigned int> _d) {
		natural = _n;
		decimal = _n;
	}

	Real operator+ (const Real& rhs) {
		if (this->decimal > rhs.decimal) {
			std::vector<unsigned int> _nat;
			for (int i = this->decimal.size; i >= 0; i--)
			{
				//
			}
		}
		//check which Natural is larger and use it as iterate base
		//check which Decimal is larger and use it as iterate base
		return Real(natural, decimal);
	};
};