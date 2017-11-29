#pragma once
#include "COBSTACLE.h"

class CCAR :public COBSTACLE
{
public:
	CCAR() :COBSTACLE()
	{
		m_shape[0][0] = ' ';
		m_shape[0][1] = ' ';
		m_shape[0][2] = ' ';
		m_shape[1][0] = 220;
		m_shape[1][1] = 219;
		m_shape[1][2] = 220;

	}
};