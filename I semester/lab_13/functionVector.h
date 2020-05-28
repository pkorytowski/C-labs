#pragma once
#include <functional>
#include <vector>
class FunctionVector{

public:
    FunctionVector()=default;
    void insert(std::function<double(double&)>); ///metoda dodajaca funkcje do wektora
    double calc(double); ///metoda liczaca przyjmujaca argument double
    double operator[](int);///przeciazony operator [] zwracajacy wynik posredniej operacji
private:
    std::vector<std::function<double(double&)>> vec; ///vector do przechowywania funkcji
    std::vector<double> numVec; ///vector do przechowywania wynikow operacji pośrednich
};
