#ifndef PLAYERDATAWIDGET_H
#define PLAYERDATAWIDGET_H

#include <QWidget>
#include "Player.h"

namespace Ui {
class PlayerDataWidget;
}

class PlayerDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerDataWidget(labyrinth::model::Player player,
                              bool isCurrentPlayer = false,
                              QWidget *parent = 0);
    ~PlayerDataWidget();

private:

    void setupPlayerData(bool);

    void setCurrentObjective();

    void setupBackgroundColor();

    Ui::PlayerDataWidget *ui;
    labyrinth::model::Player player_;
};

#endif // PLAYERDATAWIDGET_H
