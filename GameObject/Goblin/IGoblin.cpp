//
// Created by hiepd on 2/10/2022.
//

#include "IGoblin.h"

void IGoblin::setCcw(bool ccw) {
    m_Ccw = ccw;
}

bool IGoblin::getCcw() {
    return m_Ccw;
}

int IGoblin::getHealth() {
    return m_Health;
}

void IGoblin::takeHit() {
    m_Health--;
}

Vector2f IGoblin::getFactorScale() {
    return m_FactorScale;
}

void IGoblin::setStartPoint(Vector2f startPoint) {
    m_StartPoint = startPoint;
}

bool IGoblin::isStop() {
    return m_Stop;
}

void IGoblin::setStop(bool mStop) {
    m_Stop = mStop;
}