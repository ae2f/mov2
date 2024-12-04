#ifndef ae2f_mov2_Def_hpp
#define ae2f_mov2_Def_hpp

#include "Def.h"

#include <ae2f/Pack/Beg.h>

namespace ae2f { namespace mov2 {
    template<typename t>
    struct Def {
        public:
        using Dot = ae2f_Mov2DotDef(t);
        using Rect = ae2f_Mov2RectDef(t);

        private:
        static ae2f_Mov2DotRotDef(t);
        static ae2f_Mov2RectColGetDef(t);
        static ae2f_Mov2RectRotColGetDef(t);

        public:
        /// @brief Rotate the vector in a axis.
        /// @param vec Note the original buffer would change.
        /// @param axis When 0 will consider axis as (0, 0)
        /// @param rot Rotating angle
        /// @return @ref ae2f_errGlob_OK
        /// @exception @ref ae2f_errGlob_PTR_IS_NULL
        static inline ae2f_err_t Rot(Dot* vec, const Dot* axis, ae2f_float_t rot)  {
            return ae2f_Mov2DotRotDefName(t)(vec, axis, rot);
        }

        /// @brief
        /// Guess if `pos` is in `rect`.
        /// @param pos  Position
        /// @param rect Rect
        static constexpr ae2f_Mov2Col_t ColGet(const Dot* vec, const Rect* rect) {
            return ae2f_Mov2RectColGetDefName(t)(vec, rect);
        }

        /// @brief
        /// Guess if `pos` is in `rect` suggesting 
        /// @param pos
        /// @see ae2f_Mov2RectColGetDef
        /// @see ae2f_Mov2DotRotDef
        /// @param rect
        /// @see ae2f_Mov2RectColGetDef
        /// @param axis
        /// @see ae2f_Mov2DotRotDef
        /// @param rot
        /// @see ae2f_Mov2DotRotDef
        static inline ae2f_Mov2Col_t RotColGet(const Dot* pos, const Rect* rect, const Dot* axis, ae2f_float_t rot) {
            return ae2f_Mov2RectRotColGetDefName(t)(pos, rect, axis, rot);
        }
    };
}}

#include <ae2f/Pack/End.h>

#endif