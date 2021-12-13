#version 150

uniform mat4 camera;

layout(points) in;
layout(triangle_strip, max_vertices=6) out;

in mat4 quad_transform[]; // Output from vertex shader for each vertex
out vec3 fColor; // Output to fragment shader

varying vec2 uv_coord; // For depth color shading

void main() {

    uv_coord = vec2(0, 0);
    gl_Position = vec4(-0.5f,  0.5f, 0, 1) * quad_transform[0] * camera;
    // fColor = vec3(1, 0, 0);
    EmitVertex();
    uv_coord = vec2(1, 0);
    gl_Position = vec4( 0.5f,  0.5f, 0, 1) * quad_transform[0] * camera;
    // fColor = vec3(0, 1, 0);
    EmitVertex();
    uv_coord = vec2(1, 1);
    gl_Position = vec4( 0.5f, -0.5f, 0, 1) * quad_transform[0] * camera;
    // fColor = vec3(0, 0, 1);
    EmitVertex();
    EndPrimitive();

    uv_coord = vec2(1, 1);
    gl_Position = vec4( 0.5f, -0.5f, 0, 1) * quad_transform[0] * camera;
    // fColor = vec3(1, 0, 1);
    EmitVertex();
    uv_coord = vec2(0, 1);
    gl_Position = vec4(-0.5f, -0.5f, 0, 1) * quad_transform[0] * camera;
    // fColor = vec3(0, 1, 1);
    EmitVertex();
    uv_coord = vec2(0, 0);
    gl_Position = vec4(-0.5f,  0.5f, 0, 1) * quad_transform[0] * camera;
    // fColor = vec3(1, 1, 0);
    EmitVertex();
    EndPrimitive();
}
