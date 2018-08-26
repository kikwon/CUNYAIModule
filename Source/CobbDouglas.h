#pragma once

#include <BWAPI.h>
#include "CUNYAIModule.h"
#include "PlayerModelManager.h"


using namespace std;

struct Player_Model;

struct CobbDouglas
{
    CobbDouglas() {}; // default constructor.

    void evaluateCD(double army_ct, double tech_ct, double wk_ct);

    double alpha_army;
    double alpha_tech;
    double alpha_econ;

    double worker_stock;
    double army_stock;
    double tech_stock;
    
    double econ_derivative;
    double army_derivative;
    double tech_derivative;

    double getPriority();

    double getlny() const;
    double getlnY() const;

    bool army_starved();
    bool econ_starved();
    bool tech_starved();

    void estimateCD(int e_army_stock, int e_tech_stock, int e_worker_stock);
    void enemy_mimic(const Player_Model &enemy, const double adaptation_rate);

    // prints progress of economy over time every few seconds.  Gets large quickly.
    void printModelParameters();

    //Discontinuities -Cutoff if critically full, or suddenly progress towards one macro goal or another is impossible, or if their army is critically larger than ours.
    bool evalArmyPossible();
    bool evalEconPossible();
    bool evalTechPossible();
    
};




