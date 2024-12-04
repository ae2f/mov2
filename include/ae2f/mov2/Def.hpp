#ifndef ae2f_mov2_Def_hpp
#define ae2f_mov2_Def_hpp

#include "Def.h"

#include <ae2f/Pack/Beg.h>

namespace ae2f {
    namespace mov2 {
        template<typename t>
        struct Def {
            using Dot = ae2f_Mov2DotDef(t);
            using Rect = ae2f_Mov2RectDef(t);
        };
    }
}

#include <ae2f/Pack/End.h>

#endif 