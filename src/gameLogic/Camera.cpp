//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Camera.h"
#include <utility>

Camera::Camera(const Coordinates& worldView, const Coordinates& cameraView): m_windowHeight(0), m_worldView(worldView), m_cameraView(cameraView) {}

Coordinates Camera::project(const Coordinates& coordinates) const {
    double x = (coordinates.getX() / this->m_worldView.getX()) * this->m_cameraView.getX();
    double y = this->m_cameraView.getY() - ((coordinates.getY() - this->m_windowHeight) / this->m_worldView.getY()) * this->m_cameraView.getY();
    return {(float)x,(float)y};
}

void Camera::updateHeight(double height) {
    double newWindowHeight = height - (this->m_worldView.getY() / 2);
    if (newWindowHeight > this->m_windowHeight)
        m_windowHeight = newWindowHeight;
}

Coordinates Camera::getWorldView() const {
    return this->m_worldView;
}

bool Camera::evalInWindow(const Coordinates& coordinates) {
    Coordinates projection = this->project(coordinates);
    if (projection.getY() < 0) {
        // Falls out of window
        return false;
    }
    // Doesn't fall out of window
    return true;
}
