#include "Def.h"
#include <ae2f/mov/Int.h>
#include <ae2f/mov/Float.h>

#ifndef ae2f_mov2_Vec_h
#define ae2f_mov2_Vec_h

#include <ae2f/Pack/Beg.h>

typedef ae2f_Mov2DotDef(ae2f_MovVec_t) ae2f_Mov2Vec_t;
typedef ae2f_Mov2DotDef(ae2f_float_t) ae2f_Mov2VecF_t;

typedef ae2f_Mov2RectDef(ae2f_MovVec_t) ae2f_Mov2VecRect_t;
typedef ae2f_Mov2RectDef(ae2f_float_t) ae2f_Mov2FloatRect_t;

#include <ae2f/Pack/End.h>

#endif