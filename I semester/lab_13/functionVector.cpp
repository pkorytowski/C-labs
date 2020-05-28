#include "functionVector.h"

void FunctionVector::insert(std::function<double(double&)>fun){
    vec.push_back(fun);

}
double FunctionVector::calc(double num){
    double wyn = num;
    numVec.clear();
    for (int i=0;i<static_cast<int>(vec.size());i++){
        wyn = vec[i](wyn);
        numVec.push_back(wyn);
    }
    return wyn;
}
double FunctionVector::operator[](int num){
    return numVec[num];

}
