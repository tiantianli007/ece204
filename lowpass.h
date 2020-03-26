#include <cmath>
#include "vec.h"

// You are defining a system of N initial-value problems
//  - the maximum is a system of 12 1st-order IVPs
const std::size_t N{ 3 };   // must be <= 12

// Function declarations
vec<N> f( double t, vec<N> y );
double phase( double f );

// Function definitions
vec<N> f( double t, vec<N> y ) {
    // This is not a good filter...
    //  - the filter must depend on 'fc'
    const double R{1.0};
    const double C{1.0/(2.0*M_PI*R*fc)};

    return vec<N>{ (y[1]-y[0])/R/C, (y[0]+y[2]-2*y[1])/R/C, (v(t)+y[0]-2*y[1])/R/C};
}


// Calculate and return the phase shift of the response
// for a function that has a frequency of 'f'
//  - this likely will depend on the critical frequencey 'fc'
double phase( double f ) {
    const double R{1.0};
    const double C{1.0/(2.0*M_PI*R*fc)};
    const double W{2*M_PI*f};

    return (std::atan( (3*W*R*C)/(1-std::pow(W*R*C,2)) ) - std::atan( (6*W*R*C-std::pow(W*R*C,2))/(1-2*W*R*C-3*std::pow(W*R*C,2)) ));
}
