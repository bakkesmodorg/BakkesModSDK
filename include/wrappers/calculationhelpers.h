#pragma once
#include "wrapperstructs.h"
class BAKKESMOD_PLUGIN_IMPORT CalculationHelpers
{
public:
	CalculationHelpers();
	~CalculationHelpers();
	void PredictBall(float timeAhead, PredictionInfo *predictionInfo);
	Rotator face(Vector obj, Vector dest);
};

