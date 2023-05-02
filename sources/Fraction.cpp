#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <algorithm>

#include "Fraction.hpp"


using namespace std;
namespace ariel{

    Fraction::Fraction(int numerator,int denominator){
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int gcdNum = __gcd(abs(numerator), denominator);
        _numerator = numerator / gcdNum;
        _denominator = denominator / gcdNum;
    }

    Fraction::Fraction(float f){
        if(f == 0){
            _numerator = 0;
            _denominator = 1;
     
        }
        else{
            int sign = f < 0 ? -1 : 1;
            int numerator = f * 1000;
            int denominator = 1000;
            int gcdNumDen = __gcd(numerator, denominator);
            _numerator = sign * numerator / gcdNumDen;
            _denominator = denominator / gcdNumDen;
        }
    }
    float Fraction:: fraction_to_float(const Fraction& num){
        float result = static_cast<float>(num.getNumerator()) / num.getDenominator();
        return round(result * 1000.0) / 1000.0;   
    }

    // operator: +
    Fraction Fraction:: operator + (const Fraction& other) const {
        int nume = (_numerator * other.getDenominator() )+ (_denominator * other.getNumerator());
        int dene = _denominator * other.getDenominator();
        return Fraction(nume,dene);
    }
    Fraction  operator + (const float num1, const Fraction& num2){
        Fraction temp = Fraction(num1) + num2;
        return temp;
    }
    Fraction operator + (const Fraction& num1, const float num2){
        Fraction temp = num1 +Fraction(num2);
        return temp;
    }


    // operator: -
    Fraction Fraction:: operator - (const Fraction& other) const {
        int nume = (_numerator * other.getDenominator() )- (_denominator * other.getNumerator());
        int dene = _denominator * other.getDenominator();
        return Fraction(nume,dene);
    }

    Fraction  operator - (const float num1, const Fraction& num2){
        Fraction temp = Fraction(num1) - num2;
        return temp;
    }
    Fraction operator - (const Fraction& num1, const float num2){
        Fraction temp = num1 -Fraction(num2);
        return temp;
    }


    // operator: *
    Fraction Fraction:: operator * (const Fraction& other) const {
        int nume = _numerator * other.getNumerator();
        int deno = _denominator * other.getDenominator();
        return Fraction(nume,deno);
    }
    Fraction  operator * (const float num1, const Fraction& num2){
        Fraction temp = Fraction(num1) * num2;
        return temp;
    }
    Fraction operator * (const Fraction& num1, const float num2){
        Fraction temp = Fraction(num2) * num1;
        return temp;
    }


    // operator: /
    Fraction Fraction:: operator / (const Fraction& other) const {
        if(other == 0){
            throw runtime_error("Cant divide by zero.");
        }
        int nume = _numerator * other.getDenominator();
        int deno = _denominator * other.getNumerator();
        return Fraction(nume,deno);
    }
    Fraction  operator / (const float num1, const Fraction& num2){
        if(num2 == 0){
           throw runtime_error("Cant divide by zero."); 
        }
        Fraction temp = Fraction(num1) / num2;
        return temp;
    }
    Fraction operator / (const Fraction& num1, const float num2){
        if(num2 == 0){
           throw runtime_error("Cant divide by zero."); 
        }
        Fraction temp = num1/Fraction(num2);
        return temp;
    }

    // operator: ==
    bool Fraction:: operator == (const Fraction& f1)const{
        float thisFloat = Fraction::fraction_to_float(*this);
        float otherFloat = Fraction::fraction_to_float(f1);

        if(thisFloat == otherFloat){
            return true;
        }
        return false;       
    }
    bool operator == (float num1,const Fraction& num2){
        return Fraction(num1) == num2;
    }
    bool operator == (const Fraction& num1,float num2){
        return  num1 == Fraction(num2);
    }


    // operator: >
    bool Fraction:: operator >(const Fraction& f1)const{
    return this->_numerator * f1._denominator > f1._numerator * this->_denominator;

    }
    bool operator > (float num1,const Fraction& num2){
        return Fraction(num1) > num2;
    }
    bool operator > (const Fraction& num1,float num2){
        return num1 > Fraction(num2);
    }


    //operator: <
    bool Fraction:: operator < (const Fraction& f1)const{
    return this->_numerator * f1._denominator < f1._numerator * this->_denominator;
    }
    bool operator < (float num1,const Fraction& num2){
        return Fraction(num1) < num2;
    }
    bool operator < (const Fraction& num1,float num2){
        return num1 < Fraction(num2);
    }


    //operator: >=
    bool Fraction:: operator >= (const Fraction& f1)const{
        return this->_numerator * f1._denominator >= f1._numerator * this->_denominator;
    }
    bool operator >= (float num1,const Fraction& num2){
        return Fraction(num1) >= num2;
    }
    bool operator >= (const Fraction& num1,float num2){
        return num1 >= Fraction(num2);
    }


    //operator: <=
    bool Fraction:: operator <= (const Fraction& f1)const{
     return this->_numerator * f1._denominator <= f1._numerator * this->_denominator;
    }
    bool operator <= (float num1,const Fraction& num2){
        return Fraction(num1) <= num2;
    }
    bool operator <= (const Fraction& num1,float num2){
        return num1 <= Fraction(num2);
    }


    //operator: <<
    std::ostream& operator << (std::ostream& output, const Fraction& f){
        return(output << f.getNumerator() << '/' << f.getDenominator());
    }


    //operator: >>
    std::istream& operator >> (std::istream& input,Fraction& f){
        int num, den;
        input >> num >> den;
        if(input.fail()){
            throw invalid_argument("invalid argument!\n usage int numerator int denominator\n");
        }
        else{
            f = Fraction(num,den);
        }
        return input;
    }
}
