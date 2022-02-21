//
// Created by hiepd on 2/7/2022.
//

#include "ISkeleton.h"

void ISkeleton::setCcw(bool ccw) {
    m_Ccw = ccw;
}

bool ISkeleton::getCcw() {
    return m_Ccw;
}

int ISkeleton::getHealth() {
    return m_Health;
}

void ISkeleton::takeHit() {
    m_Health--;
}

Vector2f ISkeleton::getFactorScale() {
    return m_FactorScale;
}

void ISkeleton::setStartPoint(Vector2f startPoint) {
    m_StartPoint = startPoint;
}

bool ISkeleton::isStop() {
    return m_Stop;
}

void ISkeleton::setStop(bool mStop) {
    m_Stop = mStop;
}
