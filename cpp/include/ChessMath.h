#pragma once

struct Position { int x; int y; };
struct AttackResult { bool rook; bool bishop; bool any; };

class ChessMath {
public:
    AttackResult calculate(Position king, Position rook, Position bishop) const;
    const char* version() const;
};
