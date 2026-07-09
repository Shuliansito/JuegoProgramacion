#include "ticks.h"

// Lo unico que copie de afuera, no tuve ganas de pensar este 
//codigo mucho

double tickTime;
double accumulator;

std::chrono::steady_clock::time_point lastTime;


void iniciarTicks(double TPS)
{
    tickTime = 1.0 / TPS;
    accumulator = 0.0;
    lastTime = std::chrono::steady_clock::now();
}


bool debeEjecutarTick()
{
    auto currentTime = std::chrono::steady_clock::now();

    double deltaTime = std::chrono::duration<double>(currentTime - lastTime).count();

    lastTime = currentTime;

    accumulator += deltaTime;


    if (accumulator >= tickTime)
    {
        accumulator -= tickTime;
        return true;
    }

    return false;
}


void esperarTick()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}