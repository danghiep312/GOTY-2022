//
// Created by hiepd on 2/13/2022.
//

#include "IMushroom.h"

void IMushroom::setCcw(bool ccw) {
    m_Ccw = ccw;
}

bool IMushroom::getCcw() {
    return m_Ccw;
}

int IMushroom::getHealth() {
    return m_Health;
}

void IMushroom::takeHit() {
    m_Health--;
}

Vector2f IMushroom::getFactorScale() {
    return m_FactorScale;
}

void IMushroom::setStartPoint(Vector2f startPoint) {
    m_StartPoint = startPoint;
}

bool IMushroom::isStop() {
    return m_Stop;
}

void IMushroom::setStop(bool mStop) {
    m_Stop = mStop;
}