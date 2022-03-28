//
//  Camera.hpp
//  randomgl
//
//  Created by Jean Gravier on 15/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#ifndef randomgl_Camera_hpp
#define randomgl_Camera_hpp

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera(int windowWidth, int windowHeight);
    virtual ~Camera();

    void update();

    void lookAt();
    void translate(glm::vec3 vec);
    void setViewPosition(glm::vec3 vec);
    void setPosition(glm::vec3 pos);

    const glm::mat4 &getTransformation() const;
    const glm::mat4 &getProjection() const;
    const glm::vec3 &getViewPosition() const;
    const glm::vec3 &getPosition() const;

private:
    glm::mat4 _transformation;
    glm::mat4 _projection;
    glm::vec3 _position;
    glm::vec3 _viewPosition;
    glm::vec3 _direction;
};

#endif //randomgl_Camera_hpp
