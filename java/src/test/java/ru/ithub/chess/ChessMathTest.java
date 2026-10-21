package ru.ithub.chess;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import static ru.ithub.chess.ChessMath.Position;

class ChessMathTest {
    private final ChessMath math = new ChessMath();

    @Test void bothPiecesAttack() {
        var result = math.calculate(new Position(4,4), new Position(4,8), new Position(8,8));
        assertTrue(result.rook());
        assertTrue(result.bishop());
        assertTrue(result.any());
    }

    @Test void rookBlockedByBishop() {
        var result = math.calculate(new Position(4,4), new Position(4,8), new Position(4,6));
        assertFalse(result.rook());
        assertFalse(result.bishop());
        assertFalse(result.any());
    }

    @Test void bishopBlockedByRook() {
        var result = math.calculate(new Position(4,4), new Position(6,6), new Position(8,8));
        assertFalse(result.bishop());
        assertFalse(result.rook());
        assertFalse(result.any());
    }

    @Test void onlyBishopAttacks() {
        var result = math.calculate(new Position(4,4), new Position(1,8), new Position(7,7));
        assertFalse(result.rook());
        assertTrue(result.bishop());
    }

    @Test void noPieceAttacks() {
        var result = math.calculate(new Position(4,4), new Position(1,8), new Position(2,7));
        assertFalse(result.any());
    }

    @Test void rejectsSameSquare() {
        assertThrows(IllegalArgumentException.class, () ->
            math.calculate(new Position(4,4), new Position(4,4), new Position(8,8)));
    }

    @Test void rejectsOutOfBounds() {
        assertThrows(IllegalArgumentException.class, () -> new Position(0,9));
    }
}
