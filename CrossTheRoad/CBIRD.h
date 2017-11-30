#pragma once
#include "COBSTACLE.h"

class CBIRD :public COBSTACLE
{
public:
	CBIRD() :COBSTACLE()
	{
		m_shape[0][0] = 220;
		m_shape[0][1] = ' ';
		m_shape[0][2] = 220;
		m_shape[1][0] = ' ';
		m_shape[1][1] = 223;
		m_shape[1][2] = ' ';
	}
};