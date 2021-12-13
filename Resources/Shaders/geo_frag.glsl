#version 150 core

// out vec4 outColor;
varying vec2 uv_coord;
in vec3 fColor;

void main() {
    // gl_FragColor = vec4(fColor, 1);
    bool a = uv_coord.x > 0.5;
    a = a ^^ uv_coord.y > 0.5;
    if (a)
        gl_FragColor = vec4(1, 0, 1, 1);
    else
        gl_FragColor = vec4(0.1, 0.1, 0.1, 1);
}
