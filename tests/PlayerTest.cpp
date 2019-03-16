#ifndef CATCH_HPP
#define CATCH_HPP
#include "catch.hpp"
#include "../model/MazePosition.h"
#include "../model/Player.h"
#include "../model/Objectivesdeck.h"
#include <stdexcept>
#include <vector>
#endif

using namespace labyrinth;

TEST_CASE("A player is constructed as expected")
{
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE, 7, MazePosition{0, 0}, d};
    CHECK(p.geColor() == Player::Color::BLUE);
    CHECK(p.getAge() == 7);
    CHECK(p.getPosition().getRow() == 0);
    CHECK(p.getPosition().getColumn() == 0);
    CHECK(p.getState() == Player::State::WAITING);
}

TEST_CASE("Setting a player position moves the player at the expected position")
{
    const unsigned NEW_ROW = 4;
    const unsigned NEW_COLUMN = 3;
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE, 7, MazePosition{0, 0}, d};
    p.moveTo(NEW_ROW, NEW_COLUMN);
    CHECK(p.getPosition().getRow() == NEW_ROW);
    CHECK(p.getPosition().getColumn() == NEW_COLUMN);
}

TEST_CASE("Setting an invalid position causes an exception")
{
    const unsigned NEW_ROW = 7;
    const unsigned NEW_COLUMN = 12;
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE, 7, MazePosition{0, 0}, d};
    REQUIRE_THROWS_AS(p.moveTo(NEW_ROW, NEW_COLUMN), std::logic_error);
}

TEST_CASE("Turning the current objective card over.")
{
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE, 7, MazePosition{0, 0}, d};
    p.getCurrentObjective()->turnOver();
    CHECK(p.getCurrentObjective()->isTurnedOver());
}

TEST_CASE("Turning all the objectives of a player")
{
    ObjectivesDeck d{
        Object::BAT,
                Object::DRAGON,
                Object::EMERALD,
                Object::FAIRY,
                Object::KEYS,
                Object::GHOST
    };
    Player p{Player::Color::BLUE, 7, MazePosition{0, 0}, d};
    for (auto &obj : p.getObjectives().getCards()) obj.turnOver();
    CHECK(p.hasFoundAllObjectives());
}
