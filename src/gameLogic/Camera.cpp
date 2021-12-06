//
// Created by Cédric Leclercq on 18/11/2021.
//

#include "Camera.h"

Camera::Camera(float maxX, float maxY) {
    this->cameraBordersX = std::make_pair(0.f,maxX);
    this->cameraBordersY = std::make_pair(0.f,maxY);
}
