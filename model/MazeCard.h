#ifndef MAZECARD_H
#define MAZECARD_H

#include "MazeCardShape.h"
#include <stdexcept>

namespace labyrinth {

/**
 * @brief Represents a maze card. A maze card is card representing one of the
 * pathways of the maze.
 */
class MazeCard
{

protected:

    /**
     * @brief Is the shape of this maze card.
     */
    MazeCardShape shape_;

    /**
     * @brief Tells if this maze card is movable or not.
     */
    bool isMovable_;

public:

    /**
     * @brief Constructs this maze card.
     *
     * @param shape is the shape of this maze card.
     * @param isMovable is true if this maze card can be moved.
     */
    MazeCard(const MazeCardShape &shape, bool isMovable=true)
        : shape_{shape}, isMovable_{isMovable}
    {}

    MazeCard() = default;

    MazeCard(const MazeCard &) = default;

    MazeCard(const MazeCard &&) = delete;

    /**
     * @brief Tells if this maze card is movable.
     *
     * @return true if this maze card is movable.
     */
    bool isMovable() const { return isMovable_; }

    /**
     * @brief getShape Gets the shape of the MazeCard.
     * @return the shape of the MazeCard.
     */
    MazeCardShape getShape(){return shape_;}

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isT() const {return shape_.isT();}

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isL() const {return shape_.isL();}

    /**
     * @brief Tells if this card is a T.
     *
     * @return true if this card is a T.
     */
    bool isI() const {return shape_.isI();}

    /**
     * @brief Tells if this maze card is going to the given position.
     *
     * @param direction is the direction this maze card is going to.
     * @return true if this maze card is going right.
     */
    bool isGoing(const MazeDirection direction) const {
        return shape_.isGoing(direction);
    }

    /**
     * @brief Tells if this maze card is going up.
     *
     * @return true if this maze card is going up.
     */
    bool isGoingUp() const { return shape_.isGoingUp(); }

    /**
     * @brief Tells if this maze card is going right.
     *
     * @return true if this maze card is going right.
     */
    bool isGoingRight() const { return shape_.isGoingRight(); }

    /**
     * @brief Tells if this maze card is going down.
     *
     * @return true if this maze card is going down.
     */
    bool isGoingDown() const { return shape_.isGoingDown(); }

    /**
     * @brief Tells if this maze card is going left.
     *
     * @return true if this maze card is going left.
     */
    bool isGoingLeft() const { return shape_.isGoingLeft(); }

    /**
     * @brief Rotates this maze card.
     */
    void rotate() {
        isMovable_ ? shape_.rotate() :
                     throw std::logic_error("The card couldn't be rotated"
                                  " because she isn't movable");}
    ~MazeCard() = default;

};

}

#endif // MAZECARD_H
