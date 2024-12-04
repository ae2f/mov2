#ifndef ae2f_mov2_Prm_h
#define ae2f_mov2_Prm_h

/// @brief
/// Pre-definition for dot with `x`, `y` in a implicit type.
/// @tparam type for `x`, `y`.
#define ae2f_Mov2Def(type) struct ae2f_Mov2Def_##type { type x, y; }

/// @brief
/// Pre-definition for rectangle with minimun x, y in a implicit type.
/// @tparam type as vector.
#define ae2f_Mov2RectDef(type) struct ae2f_Mov2RectDef_##type { type xm, xM, ym, yM; }

#endif