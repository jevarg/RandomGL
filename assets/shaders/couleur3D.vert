// Version du GLSL

#version 150 core


// Entrées

in vec3 in_Vertex;
in vec3 in_Color;


// Uniform

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;


// Sortie

out vec3 out_Color;


// Fonction main

void main()
{
    // Position finale du vertex en 3D

    gl_Position = projection * view * model * vec4(in_Vertex, 1.0);


    // Envoi de la couleur au Fragment Shader

    out_Color = in_Color * vColor;
}
