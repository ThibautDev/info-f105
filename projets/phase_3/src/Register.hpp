#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <iostream>


uint16_t saturated(int new_value);

class Register {
  private:
    uint16_t _value = 0;
    
  public:
    constexpr void operator=(uint16_t value){
      	_value = saturated(value);
    };

    constexpr void operator+=(uint16_t value){
      	_value = saturated(_value + value);
    };

    constexpr void operator-=(uint16_t value){
      	_value = saturated(_value - value);
    };

    constexpr operator uint16_t() const{
      	return _value;
    };
};


#endif