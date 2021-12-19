//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H

#include <memory>
#include "../utilities/Utilities.h"

using Coordinates = Utilities::Coordinates;

/**
 * This class will get the players position and based on that, it will tell which platforms are allowed to draw and which
 * not
 */
class Camera {
private:
    double m_windowHeight;
    Coordinates m_worldView;
    Coordinates m_cameraView;

public:
    Camera(const Coordinates& worldView, const Coordinates& cameraView);
    Coordinates project(const Coordinates& coordinates) const;
    void updateHeight(double height);
    bool evalInWindow(const Coordinates& coordinates) const;
    bool evalInCamera(const Coordinates& coordinates) const;
    Coordinates getWorldView() const;
    double higherWindowHeight(double height) const;
};


#endif //DOODLEJUMP_CAMERA_H
