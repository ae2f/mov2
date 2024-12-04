#ifndef ae2f_mov2_Prm_h
#define ae2f_mov2_Prm_h

#define ae2f_Mov2DotDefName(type) ae2f_Mov2DotDef_##type
#define ae2f_Mov2RectDefName(type) ae2f_Mov2RectDef_##type

#include <ae2f/Cast.h>

/// @brief
/// Pre-definition for dot with `x`, `y` in a implicit type.
/// @tparam type for `x`, `y`.
#define ae2f_Mov2DotDef(type) struct ae2f_Mov2DotDefName(type) { type x, y; }

/// @brief
/// Pre-definition for rectangle with minimun x, y in a implicit type.
/// @tparam type as vector.
#define ae2f_Mov2RectDef(type) struct ae2f_Mov2RectDefName(type) { ae2f_struct ae2f_Mov2DotDefName(type) m, M; }

#include <math.h>
#include <ae2f/errGlob.h>
#include "Vec.h"

/// @tparam type
/// @brief 
/// Rotate the vector in a axis. \n
/// Notice that it will define a function, not invoking.
/// @param vec Note the original buffer would change.
/// @param axis When 0 will consider axis as (0, 0)
/// @param rot Rotating angle
/// @return @ref ae2f_errGlob_OK
/// @exception @ref ae2f_errGlob_PTR_IS_NULL
#define ae2f_Mov2DotRotDefName(type) ae2f_Mov2DotRot_##type

/// @tparam type
/// @brief 
/// Rotate the vector in a axis. \n
/// Notice that it will define a function, not invoking.
/// @param vec Note the original buffer would change.
/// @param axis When 0 will consider axis as (0, 0)
/// @param rot Rotating angle
/// @return @ref ae2f_errGlob_OK
/// @exception @ref ae2f_errGlob_PTR_IS_NULL
#define ae2f_Mov2DotRotDef(type) inline ae2f_err_t  \
ae2f_Mov2DotRotDefName(type) ( \
    ae2f_struct ae2f_Mov2DotDefName(type)* vec, \
    const ae2f_struct ae2f_Mov2DotDefName(type)* axis, \
    ae2f_float_t rot) { \
    if(!vec) return ae2f_errGlob_PTR_IS_NULL; \
    const ae2f_struct ae2f_Mov2DotDefName(type) __axisloc = ae2f_RecordMk(ae2f_struct ae2f_Mov2DotDefName(type), 0, 0); \
    if(!axis) axis = &__axisloc; \
    const ae2f_Mov2VecF_t \
    /** sin, cos  */ \
    ___ = ae2f_RecordMk( \
        ae2f_Mov2VecF_t,  \
        ae2f_MovFloatPost(sin)(rot), \
        ae2f_MovFloatPost(cos)(rot) \
    );   \
    const ae2f_struct ae2f_Mov2DotDefName(type) \
    trans = ae2f_RecordMk( \
        ae2f_struct ae2f_Mov2DotDefName(type),  \
        vec->x - axis->x, \
        vec->y = axis->y \
    ); \
    vec->x = trans.x * ___.y + trans.y * ___.x + axis->x; \
    vec->x = trans.y * ___.y + trans.x * ___.x + axis->y; \
    return ae2f_errGlob_OK; \
}

#include "Col.h"

/// @tparam type
/// @brief
/// Guess if `pos` is in `rect`.
/// @param pos  Position
/// @param rect Rect
#define ae2f_Mov2RectColGetDefName(type) ae2f_Mov2RectColGet_##type

/// @tparam type
/// @brief
/// Guess if `pos` is in `rect`.
/// @param pos  Position
/// @param rect Rect
#define ae2f_Mov2RectColGetDef(type) \
ae2f_WhenC(inline) ae2f_WhenCXX(constexpr) \
ae2f_Mov2Col_t ae2f_Mov2RectColGetDefName(type) \
( \
    const ae2f_struct ae2f_Mov2DotDefName(type)* pos, \
    const ae2f_struct ae2f_Mov2RectDefName(type)* rect \
) { \
    ae2f_Mov2Col_t rtn = 0; \
\
    if(pos->x < rect->m.x) \
    rtn |= ae2f_eMov2Col_L; \
\
    if(pos->x > rect->M.x) \
    rtn |= ae2f_eMov2Col_R; \
\
    if(pos->y > rect->M.y) \
    rtn |= ae2f_eMov2Col_U; \
\
    if(pos->y < rect->m.y) \
    rtn |= ae2f_eMov2Col_D; \
\
    return rtn; \
}


/// @tparam type
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
#define ae2f_Mov2RectRotColGetDefName(type) ae2f_Mov2RectRotColGet_##type

/// @tparam type
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
#define ae2f_Mov2RectRotColGetDef(type) \
inline ae2f_Mov2Col_t ae2f_Mov2RectRotColGetDefName(type)( \
    const ae2f_struct ae2f_Mov2DotDefName(type)* pos, \
    const ae2f_struct ae2f_Mov2RectDefName(type)* rect, \
    const ae2f_struct ae2f_Mov2DotDefName(type)* axis, \
    ae2f_float_t rot \
) { \
    const ae2f_struct ae2f_Mov2DotDefName(type) axisloc = {.x = 0, .y = 0}; \
    ae2f_struct ae2f_Mov2DotDefName(type) posloc = {.x = 0, .y = 0}; \
    if(!axis) axis = &axisloc; \
    if(pos) posloc = pos[0]; \
    ae2f_Mov2DotRotDefName(type)(&posloc, &axisloc, -rot); \
    return ae2f_Mov2RectColGetDefName(type)(&posloc, rect); \
}

#endif