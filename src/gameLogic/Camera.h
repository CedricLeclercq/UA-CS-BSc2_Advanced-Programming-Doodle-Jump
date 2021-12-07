//
// Created by Cédric Leclercq on 18/11/2021.
//

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H

#include <memory>

#include "../utilities/Utilities.h"
#include "World.h"

using Coordinates = Utilities::Coordinates;

/**
 * This class will get the players position and based on that, it will tell which platforms are allowed to draw and which
 * not
 */
class Camera {
private:
    /// The current X coordinates views of the camera
    std::pair<float,float> cameraBordersX;
    /// The current Y coordinates views of the camera
    std::pair<float,float> cameraBordersY;
    /// Shared pointer to the World
    std::shared_ptr<World> world;
public:
    Camera(float maxX, float maxY, std::shared_ptr<World> nWorld);

    void projectCoordinates(std::shared_ptr<Entity> entity);
};


#endif //DOODLEJUMP_CAMERA_H
