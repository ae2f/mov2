#include <ae2f/mov2/Def.hpp>

static int a() {
    using intdev = ae2f::mov2::Def<int>;
    intdev::Dot a, b;
    intdev::Rect r;

    intdev::ColGet(&a, &r);
    intdev::Rot<int>(&a, &b, 0.5);
    intdev::RotColGet<int>(&a, &r, &b, 0.1);

    return 0;
}