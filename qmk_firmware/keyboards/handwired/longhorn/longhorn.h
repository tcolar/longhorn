
#pragma once

#include "quantum.h"

/*
Note: I wired the columns on the right hand "mirrored" compared to the left.
Flipping them back here in the layout mapping is easier than rewiring :)
This why it goes 0,1,2,3,4,5 then b,a,9,8,7
*/

#define LAYOUT( \
        k00, k01, k02, k03, k04, k05, k0b, k0a, k09, k08, k07, k06, \
        k10, k11, k12, k13, k14, k15, k1b, k1a, k19, k18, k17, k16, \
        k20, k21, k22, k23, k24, k25, k2b, k2a, k29, k28, k27, k26, \
        k30, k31, k32, k33, k34, k35, k3b, k3a, k39, k38, k37, k36, \
             k41, k42, k43, k44, k45, k4a, k49, k48, k47, k46 \
) \
{\
        { k00, k01, k02, k03, k04, k05 },     \
        { k10, k11, k12, k13, k14, k15 },     \
        { k20, k21, k22, k23, k24, k25 },     \
        { k30, k31, k32, k33, k34, k35 },     \
        { KC_NO, k41, k42, k43, k44, k45 },   \
\
        { k06, k07, k08, k09, k0a, k0b },    \
        { k16, k17, k18, k19, k1a, k1b },    \
        { k26, k27, k28, k29, k2a, k2b },    \
        { k36, k37, k38, k39, k3a, k3b },    \
        { KC_NO, k46, k47, k48, k49, k4a },  \
}


