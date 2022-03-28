//
//  Camera.cpp
//  randomgl
//
//  Created by Jean Gravier on 25/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//


#include "Camera.hpp"

Camera::Camera(int windowWidth, int windowHeight)
: _position(0.0, 0.0, 0.0), _viewPosition(0.0, 0.0, 1.0), _direction(0.0, 1.0, 0.0)
{
    _projection = glm::perspective(glm::radians(50.0f), static_cast<float>(windowWidth) / static_cast<float>(windowHeight), 0.1f, 100.0f);
}


Camera::~Camera()
{
}

void Camera::lookAt()
{
    _transformation = glm::lookAt(_position, _viewPosition, _direction);
}

void Camera::translate(glm::vec3 vec)
{
    _position += vec;
    _viewPosition += vec;
}

void Camera::update()
{
}

const glm::mat4 &Camera::getTransformation() const
{
    return (_transformation);
}

const glm::mat4 &Camera::getProjection() const
{
    return (_projection);
}

void Camera::setViewPosition(glm::vec3 vec)
{
    _viewPosition = vec;
}

const glm::vec3 &Camera::getViewPosition() const
{
    return (_viewPosition);
}

const glm::vec3 &Camera::getPosition() const
{
    return (_position);
}

void Camera::setPosition(glm::vec3 position)
{
    _position = position;
}