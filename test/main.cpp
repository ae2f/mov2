#include <ae2f/mov2/Def.hpp>

static int a() {
    using intdev = ae2f::mov2::Def<int>;
    intdev::Dot a;

    intdev::ColGet;
    intdev::Rot;
    intdev::RotColGet;

    return 0;
}