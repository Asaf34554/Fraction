#pragma once
#include <iostream>


namespace ariel{
    class Fraction
    {
    private:
        int _numerator,_denominator;


    public:
    //constructors
        Fraction():
            _numerator(0),_denominator(1){}

        Fraction(int numerator,int denominator);
        Fraction(float f);
        // Fraction(const Fraction& other) {
        //     _numerator = other._numerator;
        //     _denominator = other._denominator;
        // }

    //destructor
        // ~Fraction();

    //methods
        int getNumerator() const{
            return _numerator;
        }

        int getDenominator() const{
            return _denominator;
        }
   
    //operators
        static float fraction_to_float(const Fraction&);
        Fraction operator + (const Fraction& other) const;
        friend Fraction operator + (const float num1, const Fraction& num2);
        friend Fraction operator + (const Fraction& num1, const float num2);
        
        Fraction operator - (const Fraction& other) const;
        friend Fraction operator - (const float num1, const Fraction& num2);
        friend Fraction operator - (const Fraction& num1, const float num2);

        Fraction operator * (const Fraction& other) const;
        friend Fraction operator * (const float num1, const Fraction& num2);
        friend Fraction operator * (const Fraction& num1, const float num2);
        
        Fraction operator / (const Fraction& other) const;
        friend Fraction operator / (const float num1, const Fraction& num2);
        friend Fraction operator / (const Fraction& num1, const float num2);

        
        bool operator == (const Fraction& f1)const;
        friend bool operator == (float num1,const Fraction& num2);
        friend bool operator == (const Fraction& num1,float num2);

        bool operator > (const Fraction& f1)const;
        friend bool operator > (const float num1,const Fraction& num2);
        friend bool operator > (const Fraction& num1,const float num2);

        bool operator < (const Fraction& f1)const;
        friend bool operator < (const float num1,const Fraction& num2);
        friend bool operator < (const Fraction& num1,const float num2);

        bool operator >= (const Fraction& f1)const;
        friend bool operator >= (const float num1,const Fraction& num2);
        friend bool operator >= (const Fraction& num1,const float num2);


        bool operator <= (const Fraction& f1)const;
        friend bool operator <= (const float num1,const Fraction& num2);
        friend bool operator <= (const Fraction& num1,const float num2);


        Fraction& operator ++ (){
            _numerator += _denominator;
            return *this;
        }
        Fraction operator ++ (int flag_to_overload){
            Fraction copy = *this;
            _numerator += _denominator;
            return copy;
        }
        Fraction& operator -- (){
            _numerator -= _denominator;
            return *this;
        }
        Fraction operator -- (int flag_to_overload){
            Fraction copy = *this;
            _numerator -= _denominator;
            return copy;
        }
        
        friend std::ostream& operator << (std::ostream& output, const Fraction& f);
        // friend ostream& operator << ( const Fraction& f,ostream output);
        
        friend std::istream& operator >> (std::istream& input,Fraction& f); 
        // friend ostream& operator >> ( const Fraction& f,ostream output);

     };  
};

