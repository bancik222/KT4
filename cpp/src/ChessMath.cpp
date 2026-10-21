#include "ChessMath.h"
#include <cstdlib>

AttackResult ChessMath::calculate(Position k, Position r, Position b) const {
    const bool rookLine = (k.x == r.x) || (k.y == r.y);
    const bool bishopLine = std::abs(k.x - b.x) == std::abs(k.y - b.y);
    const bool rookBlocked =
        (k.x == r.x && b.x == k.x && (b.y - k.y) * (b.y - r.y) < 0) ||
        (k.y == r.y && b.y == k.y && (b.x - k.x) * (b.x - r.x) < 0);
    const bool bishopBlocked = bishopLine &&
        std::abs(r.x - b.x) == std::abs(r.y - b.y) &&
        (r.x - b.x) * (r.x - k.x) < 0 &&
        (r.y - b.y) * (r.y - k.y) < 0;
    const bool rookAttack = rookLine && !rookBlocked;
    const bool bishopAttack = bishopLine && !bishopBlocked;
    return {rookAttack, bishopAttack, rookAttack || bishopAttack};
}

const char* ChessMath::version() const {
#ifdef LIB_UPDATED
    return "ChessMath: version 2 (library rebuilt)";
#else
    return "ChessMath: version 1";
#endif
}
