#ifndef ae2f_mov2_Vec_hpp
#define ae2f_mov2_Vec_hpp

#include "Vec.h"

namespace ae2f { namespace mov2 {
    template<typename t>
    class Vec {
        static ae2f_Mov2DotDefRotDef(t);

        public:
        static inline ae2f_err_t Rot(t* vec, const t* axis, ae2f_float_t rot)  {
            return ae2f_Mov2DotDefRot_t(vec, axis, rot);
        }
    };
}}

#endif 