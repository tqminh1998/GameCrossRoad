#pragma once
#include "COBSTACLE.h"

class CDINOSAUR :public COBSTACLE
{
public:
	CDINOSAUR() :COBSTACLE()
	{
		m_shape[0][0] = ' ';
		m_shape[0][1] = ' ';
		m_shape[0][2] = 220;
		m_shape[1][0] = 220;
		m_shape[1][1] = 220;
		m_shape[1][2] = 221;
	}
};