#version 120

varying vec2 txrCoord0;
varying vec3 normal0;

attribute vec3 position;
attribute vec2 txrCoord;
attribute vec3 normal;

uniform mat4 transform;


void main(){
	gl_Position = transform * vec4(position, 1.0);
	txrCoord0 = txrCoord;
	normal0 = (transform * vec4(normal, 0.0)).xyz;
}