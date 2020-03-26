#include "vec.h"
#include "ivp.h"
#include "data.h"
#include <iostream>
#include <cassert>
#include <cmath>

// Function declarations
double has_converged( double max_error );
vec<15> f( double t, vec<15> w );
// You will pass 't' to ua(t) and ub(t); for everything else, you
// will use w[1]

// Function definitions
double has_converged( double max_error ) {
    assert( max_error > 0 );
    
    // Your implementation here (some hints included):
    // - you can call all globally defined functions in 'data.h'
    // and all globally defined constants
        
    double h=(b-a)/16;
    
    vec<15> initial_state{};
    for(int k=0;k<15;k++){
        initial_state[k]=u0(a+k*h);
    }
    // Initialize your initial state vector.
        
    ivp<vec<15>> u{ f, t0, initial_state,
    H_INIT, H_RANGE, EPS_ABS, vec<15>::norm };
    // u(3.2) returns a vec<15> with the temperatures at the
    // 15 intermediate points at time 3.2
    
    double s=(ub(t0)-ua(t0))/16;
    double count=0;
    double t=0;
    bool found = true;
    
    while(found){
        t=t+100;
        std::cout<<t<<std::endl;
        for(int k=0;k<15;k++){
            if(abs(u(t)[k]-(ua(t0)+(s*k))) <= max_error){
                count++;
            }
        }
        if(count==15){
            found = false;
        }
        count=0;
    }
    
//    double t1=t0;
//    double t2=t;
//
//    while(abs(t2-t1)<10e-6){
//        t=(t2-t1)/2;
//        for(int k=0;k<15;k++){
//            if(abs(u(t)[k]-(ua(t0)+(s*k))) <= max_error){
//                count++;
//            }
//        }
//        if(count==15){
//            t2=t;
//        }else{
//            t1=t;
//        }
//        count=0;
//    }
    
    
    return t;
}

vec<15> f( double t, vec<15> w ){
    double h=(b-a)/16;
    return {
        kappa*(ua(t)-2*w[0]+w[1])/pow(h,2),
        kappa*(w[0]-2*w[1]+w[2])/pow(h,2),
        kappa*(w[1]-2*w[2]+w[3])/pow(h,2),
        kappa*(w[2]-2*w[3]+w[4])/pow(h,2),
        kappa*(w[3]-2*w[4]+w[5])/pow(h,2),
        kappa*(w[4]-2*w[5]+w[6])/pow(h,2),
        kappa*(w[5]-2*w[6]+w[7])/pow(h,2),
        kappa*(w[6]-2*w[7]+w[8])/pow(h,2),
        kappa*(w[7]-2*w[8]+w[9])/pow(h,2),
        kappa*(w[8]-2*w[9]+w[10])/pow(h,2),
        kappa*(w[9]-2*w[10]+w[11])/pow(h,2),
        kappa*(w[10]-2*w[11]+w[12])/pow(h,2),
        kappa*(w[11]-2*w[12]+w[13])/pow(h,2),
        kappa*(w[12]-2*w[13]+w[14])/pow(h,2),
        kappa*(w[13]-2*w[14]+ub(t))/pow(h,2),
    };
}
