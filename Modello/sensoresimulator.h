#ifndef SENSORESIMULATOR_H
#define SENSORESIMULATOR_H

#include "Sensore.h"
#include "SensoreAcqua.h"
#include "SensoreAria.h"
#include "SensoreSuolo.h"
#include <vector>
#include <random>
#include <ctime>

class SensoreSimulator
{
public:
    static void simulazioneSensore(Sensore* sensore);
};

#endif // SENSORESIMULATOR_H
