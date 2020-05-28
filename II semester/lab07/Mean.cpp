#include "Mean.h"


std::ostream& operator<<(std::ostream &os, const Mean& m){
    os<<m.name();
    return os;
}