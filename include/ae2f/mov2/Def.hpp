#ifndef ae2f_mov2_Def_hpp
#define ae2f_mov2_Def_hpp

#include "Def.h"
#include <ae2f/Pack/Beg.h>

namespace ae2f { namespace mov2 {
    /// @tparam t type for pos
    /// @tparam v type for axis
    template<typename t, typename v = void>
    struct __Def;

    /// @tparam t type for pos
    template<typename t>
    struct __Def<t> {
        using Dot_t = ae2f_Mov2DotDef(t);
        using Rect_t = ae2f_Mov2RectDef(t);

        private:
        static ae2f_Mov2RectColGetDef(t);

        public:

        /// @brief
        /// Guess if `pos` is in `rect`.
        /// @param pos  Position
        /// @param rect Rect
        static consteval ae2f_Mov2Col_t ColGet(const Dot_t* vec, const Rect_t* rect) {
            return ae2f_Mov2RectColGetDefName(t)(vec, rect);
        }
    };

    /// @tparam t type for pos
    /// @tparam v type for axis
    template<typename t, typename v>
    struct __Def {
        public:
        using Dot_t = typename __Def<t, void>::Dot_t;
        using Rect_t = typename __Def<t, void>::Rect_t;

        using Dot_v = typename __Def<v, void>::Dot_t;
        using Rect_v = typename __Def<v, void>::Rect_t;

        private:

        ae2f_Mov2DotDef(t); ae2f_Mov2RectDef(t);
        ae2f_Mov2DotDef(v); ae2f_Mov2RectDef(v);
        static ae2f_Mov2DotRotDef(t, v);
        static ae2f_Mov2RectRotColGetDef(t, v);
        static ae2f_Mov2RectColGetDef(t);

        public:
        /// @brief Rotate the vector in a axis.
        /// @param vec Note the original buffer would change.
        /// @param axis When 0 will consider axis as (0, 0)
        /// @param rot Rotating angle
        /// @return @ref ae2f_errGlob_OK
        /// @exception @ref ae2f_errGlob_PTR_IS_NULL
        static inline ae2f_err_t Rot(Dot_t* vec, const Dot_v* axis, ae2f_float_t rot)  {
            return ae2f_Mov2DotRotDefName(t, v)(
                reinterpret_cast<ae2f_Mov2DotDefName(t)*>(vec), 
                reinterpret_cast<const ae2f_Mov2DotDefName(v)*>(axis), 
                rot
            );
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
        static inline ae2f_Mov2Col_t RotColGet(const Dot_t* pos, const Rect_t* rect, const Dot_v* axis, ae2f_float_t rot) {
            return ae2f_Mov2RectRotColGetDefName(t, v)(
                reinterpret_cast<const ae2f_Mov2DotDefName(t)*>(pos), 
                reinterpret_cast<const ae2f_Mov2RectDefName(t)*>(rect),
                reinterpret_cast<const ae2f_Mov2DotDefName(v)*>(axis), 
                rot
            );
        }
    };

    template<typename t>
    struct Def {
        public:
        using Dot = typename __Def<t, void>::Dot_t;
        using Rect = typename __Def<t, void>::Rect_t;

        public:

        /// @tparam v type for axis
        /// @brief 
        /// Rotate the vector in a axis. \n
        /// Notice that it will define a function, not invoking.
        /// @param vec Note the original buffer would change.
        /// @param axis When 0 will consider axis as (0, 0)
        /// @param rot Rotating angle
        /// @return @ref ae2f_errGlob_OK
        /// @exception @ref ae2f_errGlob_PTR_IS_NULL
        template<typename v>
        static inline ae2f_err_t Rot(Dot* vec, const typename Def<v>::Dot* axis, ae2f_float_t rot)  {
            return __Def<t, v>::Rot(vec, axis, rot);
        }

        /// @brief
        /// Guess if `pos` is in `rect`.
        /// @param pos  Position
        /// @param rect Rect
        static consteval ae2f_Mov2Col_t ColGet(const Dot* vec, const Rect* rect) {
            return __Def<t>::ColGet(vec, rect);
        }

        /// @tparam v type for axis
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
        template<typename v>
        static inline ae2f_Mov2Col_t RotColGet(const Dot* pos, const Rect* rect, const typename Def<v>::Dot* axis, ae2f_float_t rot) {
            return __Def<t, v>::RotColGet(pos, rect, axis, rot);
        }
    };
}}

#include <ae2f/Pack/End.h>

#endif