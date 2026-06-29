#pragma once

#include <chrono>
#include <thread>

extern double tickTime;
extern double accumulator;

extern std::chrono::steady_clock::time_point lastTime;

void iniciarTicks(double TPS);

bool debeEjecutarTick();

void esperarTick();