// // // // // // // // // // // // // //
//                                     //
//              Camera.h               //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H

#include <memory>
#include "../utilities/Utilities.h"

using Coordinates = Utilities::Coordinates;

/**
 * @class Camera
 * @brief Class that will project between the logic world coordinates and the graphical world coordinates
 */
class Camera {
private:
    /// @brief height of the game window // todo fix comment
    double m_windowHeight{};
    /// @brief Coordinates X and Y of the world view
    Coordinates m_worldView{};
    /// @brief Coordinates X and Y of the camera view
    Coordinates m_cameraView{};

public:
    /**
     * @brief Default constructor
     */
    Camera()=default;
    /**
     * @brief Default destructor
     */
    ~Camera()=default;
    /**
     * @brief Constructor for the camera class
     * @param worldView     Dimensions of the world view
     * @param cameraView    Dimensions of the camera view
     */
    Camera(const Coordinates& worldView, const Coordinates& cameraView);
    /**
     * @brief Will project a coordinate form the world view to a coordinate of the camera view
     * @param coordinates   Coordinate to project
     * @return              Projected coordinate
     */
    Coordinates project(const Coordinates& coordinates) const;
    /**
     * @brief Will update the parameter window height if the given projected height is higher than the current one
     * @param height    Given height to evaluate
     */
    void updateHeight(double height);
    /**
     * @brief Will evaluate if a given coordinate falls into the world window
     * @param coordinates   Given coordinate to evaluate
     * @return              (coordinate.inWorldWindow())
     */
    bool evalInWindow(const Coordinates& coordinates) const;
    /**
     * @brief Will evaluate if a given coordinate falls into the camera window
     * @param coordinates   Given coordinate to evaluate
     * @return              (coordinate.inCameraWindow())
     */
    bool evalInCamera(const Coordinates& coordinates) const;
    /**
     * @brief Will check is a given height, when projected, is higher than the current window height
     * @param height        Given height to evaluate
     * @return              (height > this->height)
     */
    double higherWindowHeight(double height) const;
};


#endif //DOODLEJUMP_CAMERA_H
