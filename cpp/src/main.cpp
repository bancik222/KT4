#include "ChessMath.h"
#include <iostream>
#include <string>
#include <stdexcept>

static int parseCoord(const char* text) {
    std::string s(text);
    std::size_t used = 0;
    int value = std::stoi(s, &used);
    if (used != s.size() || value < 1 || value > 8)
        throw std::invalid_argument("coordinates must be integers from 1 to 8");
    return value;
}

int main(int argc, char* argv[]) {
    Position k{}, r{}, b{};
    try {
        if (argc == 7) {
            k = {parseCoord(argv[1]), parseCoord(argv[2])};
            r = {parseCoord(argv[3]), parseCoord(argv[4])};
            b = {parseCoord(argv[5]), parseCoord(argv[6])};
        } else if (argc == 1) {
            std::cout << "King (x y): ";
            if (!(std::cin >> k.x >> k.y)) throw std::invalid_argument("invalid input");
            std::cout << "Rook (x y): ";
            if (!(std::cin >> r.x >> r.y)) throw std::invalid_argument("invalid input");
            std::cout << "Bishop (x y): ";
            if (!(std::cin >> b.x >> b.y)) throw std::invalid_argument("invalid input");
            for (int v : {k.x, k.y, r.x, r.y, b.x, b.y})
                if (v < 1 || v > 8) throw std::invalid_argument("coordinates must be 1..8");
        } else {
            std::cerr << "Usage: " << argv[0] << " xk yk xr yr xb yb\n";
            return 1;
        }
        if ((k.x == r.x && k.y == r.y) ||
            (k.x == b.x && k.y == b.y) ||
            (r.x == b.x && r.y == b.y))
            throw std::invalid_argument("pieces must occupy different squares");
        ChessMath math;
        AttackResult result = math.calculate(k, r, b);
        std::cout << math.version() << '\n';
        std::cout << "Rook attacks: " << result.rook << '\n';
        std::cout << "Bishop attacks: " << result.bishop << '\n';
        std::cout << "King is under attack: " << result.any << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}
