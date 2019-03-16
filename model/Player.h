#ifndef PLAYER_H
#define PLAYER_H
#include "MazePosition.h"
#include "ObjectCard.h"
#include "Objectivesdeck.h"
#include <vector>
#include <string>

namespace labyrinth {

/**
 * @brief Represents a player of Labyrinth.
 */
struct Player {

    /**
     * @brief Represents the color of a player.
     */
    enum class Color
    {
        RED,
        BLUE,
        YELLOW,
        GREEN
    };

    /**
     * @brief Represents the state of a player.
     */
    enum class State
    {
        WAITING,
        MOVING_PATHWAYS,
        MOVING_PIECE,
        PASS
    };

private:

    /**
     * @brief Is this player color. Each player of a same game has a different
     * color.
     */
    const Color color_;

    /**
     * @brief Is the age of this player.
     */
    const unsigned age_;

    /**
     * @brief Is the position in the maze of this player.
     */
    MazePosition position_;

    /**
     * @brief Is the state of this player.
     */
    State state_;

    /**
     * @brief Is the current objective of this player.
     */
    ObjectCard *currentObjective_;

    /**
     * @brief Are all the objectives this player must find in order to be the
     * winner.
     */
    ObjectivesDeck objectives_;

public:

    /**
     * @brief Constructs this player. Initially this player has no objectif and
     * is waiting.
     *
     * @param color is the color of this player.
     * @param age is the age of this player.
     * @param position is the position of this player.
     * @param objectives is the player`s objectives deck. The deck contains
     * less than 12 or lower than 6. (24 / 4 = 6 / 24 / 2 = 12).
     */
    Player(Color color, unsigned age, MazePosition position,
           ObjectivesDeck objectives)
        : color_{color},
          age_{age},
          position_{position},
          state_{State::WAITING},
          currentObjective_{nullptr},
          objectives_{objectives}
    {}

    /**
     * @brief Gets this player color.
     *
     * @return this player color.
     */
    Color geColor() const{return color_;}

    /**
     * @brief Gets this player age.
     *
     * @return this player age.
     */
    unsigned getAge() const { return age_; }

    /**
      * @brief getState gets the state of this player.
      *
      * @return the current state of this player.
      */
    State getState() const{ return state_; }

    /**
     * @brief Gets this player position.
     *
     * @return this player position.
     */
    MazePosition getPosition() const{ return position_; }

    /**
     * @brief Gets this player current objective.
     *
     * @return this player current objective.
     */
    ObjectCard *getCurrentObjective() const { return currentObjective_; }

    /**
     * @brief Gets the objectives of this player.
     *
     * @return the objectives of this player.
     */
    ObjectivesDeck getObjectives() const { return objectives_; }

    /**
     * @brief Moves this player position to the given coordinates.
     *
     * @param row is the row of this player position.
     * @param column is the column of this player position.
     */
    void moveTo(unsigned row, unsigned column) { position_.moveTo(row, column); }

    /**
     * @brief Turns the current objective over.
     */
    void turnCurrentObjectiveOver() { currentObjective_->turnOver(); }

    /**
     * @brief Sets the player current objective to the next one.
     */
    void nextObjective() { currentObjective_ = objectives_.getCurrentCard(); }

    /**
     * @brief Tells if this player has found his objectives.
     *
     * @return true if this player has found all his objectives.
     */
    bool hasFoundAllObjectives(){
        return objectives_.areAllCardsTurnedOver();
    }

};

}

#endif
