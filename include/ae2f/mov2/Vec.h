#include "Def.h"
#include <ae2f/mov/Int.h>
#include <ae2f/mov/Float.h>

#ifndef ae2f_mov2_Vec_h
#define ae2f_mov2_Vec_h

#include <ae2f/Pack/Beg.h>

typedef ae2f_Mov2DotDef(ae2f_MovVec_t) ae2f_Mov2Vec_t;
typedef ae2f_Mov2DotDef(ae2f_float_t) ae2f_Mov2VecF_t;

typedef ae2f_Mov2RectDef(ae2f_MovVec_t) ae2f_Mov2Rect_t;
typedef ae2f_Mov2RectDef(ae2f_float_t) ae2f_Mov2RectF_t;

#include <ae2f/Pack/End.h>

#include <math.h>
#include <ae2f/Cast.h>
#include <ae2f/errGlob.h>

/// @tparam type for `vec`
/// @def ae2f_Mov2DotDefRot##type
/// @brief Rotate the vector in a axis.
/// @param vec Note the original buffer would change.
/// @param axis When 0 will consider axis as (0, 0)
/// @param rot Rotating angle
/// @return @ref ae2f_errGlob_OK
/// @exception @ref ae2f_errGlob_PTR_IS_NULL
#define ae2f_Mov2DotDefRotDef(type) inline ae2f_err_t  \
ae2f_Mov2DotDefRot_##type ( \
type* vec, const type* axis, ae2f_float_t rot) { \
    if(!vec) return ae2f_errGlob_PTR_IS_NULL; \
    const type __axisloc = ae2f_RecordMk(type, 0, 0); \
    if(!axis) axis = &__axisloc; \
    const ae2f_Mov2VecF_t \
    /** sin, cos  */ \
    ___ = ae2f_RecordMk( \
        ae2f_Mov2VecF_t,  \
        ae2f_MovFloatPost(sin)(rot), \
        ae2f_MovFloatPost(cos)(rot) \
    );   \
    const type \
    trans = ae2f_RecordMk( \
        type,  \
        vec->x - axis->x, \
        vec->y = axis->y \
    ); \
    vec->x = trans.x * ___.y + trans.y * ___.x + axis->x; \
    vec->x = trans.y * ___.y + trans.x * ___.x + axis->y; \
    return ae2f_errGlob_OK; \
}

#endif