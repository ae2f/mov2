#ifndef ae2f_mov2_Col_h
#define ae2f_mov2_Col_h

/// @brief Centre
#define ae2f_eMov2Col_C     0b0000

/// @brief Left
#define ae2f_eMov2Col_L     0b0001

/// @brief Right
#define ae2f_eMov2Col_R     0b0010

/// @brief Up
#define ae2f_eMov2Col_U     0b0100

/// @brief Down
#define ae2f_eMov2Col_D     0b1000

#include <stdint.h>

/// @brief 
/// Contains the information of position as bit vector.
typedef uint8_t ae2f_Mov2Col_t;

#endif