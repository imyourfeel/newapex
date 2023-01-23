#pragma once
#include <vector>
#include "LocalPlayer.cpp"
#include "Player.cpp"
#include "Math.cpp"
#include "Level.cpp"
#include "X11Utils.cpp"
#include "ConfigLoader.cpp"

class Sense
{
private:
    ConfigLoader *m_configLoader;
    Level *m_level;
    LocalPlayer *m_localPlayer;
    std::vector<Player *> *m_players;
    X11Utils *m_x11Utils;

public:
    Sense(ConfigLoader *configLoader,
          Level *level,
          LocalPlayer *localPlayer,
          std::vector<Player *> *players,
          X11Utils *x11Utils)
    {
        m_configLoader = configLoader;
        m_level = level;
        m_localPlayer = localPlayer;
        m_players = players;
        m_x11Utils = x11Utils;
    }
    void update()
    {
        if (!m_level->isPlayable())
            return;
        for (int i = 0; i < m_players->size(); i++)
        {
            Player *player = m_players->at(i);
            if (!player->isValid())
                continue;
            if (player->getTeamNumber() == m_localPlayer->getTeamNumber())
                continue;

            //if (player->isVisible()){

                player->setCustomGlow();
                player->setCustomGlowPurple();

                if(player->getShieldValue() <= 10){
                    player->setCustomGlowBlue();
                } else
                if(player->getShieldValue() <= 125){
                    player->setCustomGlowPurple();
                }

                
            /*}
            else
            {
                player->setCustomGlow();
                player->setCustomGlowRed();
            } */
        }
    }
};
