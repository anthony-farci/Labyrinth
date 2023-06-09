#ifndef SHOWCOMMAND_H
#define SHOWCOMMAND_H

#include <string>
#include "View.h"
#include "Command.h"

namespace labyrinth { namespace controller {

/**
 * @brief Shows the given item when executed.
 */
class ShowCommand : public Command {

public:

    /**
     * @brief Constructs this command with the given view and game.
     *
     * @param view is the given view.
     * @param game is the given game.
     */
    ShowCommand(view::View & view, model::Game *game)
        : Command(view, game)
    {}

    /**
     * @brief Executes this command.
     */
    void execute() override {
        if (argv_.size() < 2) throw std::logic_error("usage: show <item>");
        std::string item = argv_[1];
        if (item.compare("players") == 0) {
            view_.printPlayers();
        } else if (item.compare("mazecard") == 0) {
            view_.printCurrentMazeCard();
        } else if (item.compare("objectives") == 0) {
            view_.printMazeObjectives();
        } else if (item.compare("objective") == 0) {
            view_.printCurrentPlayerObjective();
        } else {
            view_.print(item + " is not a known item and cannot be shown.");
        }
    }

    ~ShowCommand() override = default;

};

}}

#endif
