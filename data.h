#include <utility>
// All these are globally defined

// Function declarations
double u0( double x );
double ua( double t );
double ub( double t );

// Constants
double const kappa{1.0}; // The "diffusivity" constant (this may change)
double const a{0.0}; // Left-hand end point (this may change)
double const b{1.0}; // Right-hand end point (this may change)
double const t0{0.0}; // The initial time (always 0.0).

// These constants are two arguments for the 'ivp' constructor
double const H_INIT{ 1e-4 };
std::pair<double, double> const H_RANGE{ std::make_pair( 1e-6, 1e-2 ) };
double const EPS_ABS{ 1e-6 };

// Function definitions
double u0( double x ) { // The initial state could be a function of 'x',
    return 20.0; // but this really doesn't change anything.
}
double ua( double t ) { // This will always be a constant for this project
    return 100.0;
}
double ub( double t ) { // This will always be a constant for this project
    return 0.0;
}

